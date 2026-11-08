param(
    [string]$ReferencePe = "C:\SporeAnalysis\SporeApp.exe",
    [string]$CandidatePe = "C:\Program Files (x86)\Steam\steamapps\common\Spore\SPOREFILES\SporeBin\SporeApp.exe",
    [string]$BatchDirectory = "C:\SporeAnalysis\spore_batch_all_parts",
    [string]$DeviceSerial = "",
    [string[]]$Stage = @("seh-call-boundary", "startupinfo-call", "interlocked-call", "startup-lock", "initterm-call", "initterm-executed", "startup-state-initializing", "cpp-walk-initializers"),
    [int]$BatchInitializers = 5,
    [switch]$BuildOnly
)

$ErrorActionPreference = "Stop"
$toolsDirectory = $PSScriptRoot
$repoRoot = Split-Path $toolsDirectory -Parent
$backendDirectory = Join-Path $toolsDirectory "batch_static_lift"
$logsDirectory = Join-Path $repoRoot "test-logs\boot-entry-20261108"
$generator = Join-Path $backendDirectory "generate_boot_crt_prefix.py"
$closureGenerator = Join-Path $backendDirectory "generate_initterm_closure.py"
$imageGenerator = Join-Path $backendDirectory "generate_initterm_guest_image.py"
$batchGenerator = Join-Path $backendDirectory "generate_cpp_initializer_batch.py"
$originalHarness = Join-Path $backendDirectory "boot_entry_crt_original_x86.cpp"
$liftHarness = Join-Path $backendDirectory "boot_entry_crt_harness.cpp"
$entryTailDirectory = Join-Path $logsDirectory "generated-entry-tail"
$cookieDirectory = Join-Path $logsDirectory "generated-cookie-cookie-prefix"
$batch = Join-Path $BatchDirectory "spore_batch_all_0086.json"
$python = (Get-Command python.exe -ErrorAction Stop).Source

$vswhere = Join-Path ${env:ProgramFiles(x86)} "Microsoft Visual Studio\Installer\vswhere.exe"
$vsInstall = & $vswhere -latest -products "*" -property installationPath
if ($LASTEXITCODE -ne 0 -or -not $vsInstall) {
    throw "Could not locate Visual Studio Build Tools"
}
$vsDevCmd = Join-Path $vsInstall "Common7\Tools\VsDevCmd.bat"

$sdkRoot = if ($env:ANDROID_SDK_ROOT) { $env:ANDROID_SDK_ROOT }
    elseif ($env:ANDROID_HOME) { $env:ANDROID_HOME }
    else { Join-Path $env:LOCALAPPDATA "Android\Sdk" }
$ndkRoot = if ($env:ANDROID_NDK_HOME) { $env:ANDROID_NDK_HOME }
    else { Join-Path $sdkRoot "ndk\29.0.14206865" }
$clang = Join-Path $ndkRoot "toolchains\llvm\prebuilt\windows-x86_64\bin\clang++.exe"
$adb = @(
    (Join-Path $sdkRoot "platform-tools\adb.exe"),
    "C:\platform-tools\adb.exe"
) | Where-Object { Test-Path -LiteralPath $_ } | Select-Object -First 1

foreach ($requiredPath in @(
    $ReferencePe, $CandidatePe, $batch, $generator, $closureGenerator,
    $imageGenerator, $batchGenerator, $originalHarness, $liftHarness,
    $vsDevCmd, $clang,
    (Join-Path $entryTailDirectory "spore_011e11a0.cpp"),
    (Join-Path $cookieDirectory "spore_011e1548_prefix.cpp"),
    (Join-Path $logsDirectory "cpp-batch-1\closure.json")
)) {
    if (-not (Test-Path -LiteralPath $requiredPath)) {
        throw "Required input or tool was not found: $requiredPath"
    }
}

$buildDirectory = Join-Path $env:TEMP ("spore-crt-entry-" + [Guid]::NewGuid().ToString("N"))
New-Item -ItemType Directory -Path $buildDirectory -Force | Out-Null

function Invoke-AdbCommand {
    param([string[]]$Arguments)
    $previousPreference = $ErrorActionPreference
    try {
        $ErrorActionPreference = "Continue"
        $output = & $adb @Arguments 2>&1
        $exitCode = $LASTEXITCODE
    } finally {
        $ErrorActionPreference = $previousPreference
    }
    return [PSCustomObject]@{ Output = @($output); ExitCode = $exitCode }
}

function Assert-OnlyExpectedLines {
    param($Output, [string]$Label)
    $unexpected = @($Output | Where-Object { "$_" -notmatch '^(PASS|DETAIL) ' })
    if ($unexpected.Count -gt 0) {
        throw "Unexpected $Label output: $($unexpected -join ' | ')"
    }
}

function Get-PassLine {
    param($Output, [string]$Label)
    $pass = @($Output | Where-Object { "$_" -match '^PASS ' })[0]
    if (-not $pass) { throw "Missing $Label PASS line" }
    return "$pass"
}

try {
    $deviceSelected = $false
    if (-not $BuildOnly -and -not $DeviceSerial) {
        if ($adb) {
            $devices = @(
                & $adb devices |
                    Where-Object { $_ -match '^\S+\s+device$' } |
                    ForEach-Object { ($_ -split '\s+')[0] }
            )
            if ($devices.Count -eq 1) { $DeviceSerial = $devices[0] }
        }
        if (-not $DeviceSerial) {
            "DEVICE_RUN_SKIPPED=no_connected_authorized_device" |
                Set-Content -LiteralPath (Join-Path $logsDirectory "crt-arm64.log")
        } else {
            $deviceSelected = $true
        }
    } elseif (-not $BuildOnly) {
        $deviceSelected = $true
    }

    # The harness always declares the initializer bodies, so the closure is
    # generated once; only the executing stage compiles and registers it.
    $closureDirectory = Join-Path $logsDirectory "generated-initterm-closure"
    if (Test-Path -LiteralPath $closureDirectory) {
        Remove-Item -LiteralPath $closureDirectory -Recurse -Force
    }
    $closureLog = & $python $closureGenerator --reference $ReferencePe `
        --candidate $CandidatePe --batch $batch `
        --extra-batch (Join-Path $logsDirectory "crt_init_routines.json") `
        --extra-batch (Join-Path $logsDirectory "crt_dep_routines.json") `
        --extra-batch (Join-Path $logsDirectory "crt_dep_routines2.json") `
        --extra-batch (Join-Path $logsDirectory "crt_dep_functions.json") `
        --output $closureDirectory 2>&1
    $closureLog | Tee-Object -FilePath (Join-Path $logsDirectory "initterm-closure-generation.log")
    if ($LASTEXITCODE -ne 0) { throw "CRT initializer closure generation failed" }
    $closureManifest = Get-Content -LiteralPath `
        (Join-Path $closureDirectory "manifest.json") -Raw | ConvertFrom-Json
    $closureSources = @(
        $closureManifest.functions |
            ForEach-Object { Join-Path $closureDirectory $_.source }
    )
    # These stages run guest initializer bodies, so they link the closure and
    # cannot be compared against the real CRT bytes.
    $closureStages = @("initterm-executed", "startup-state-initializing")
    $imageDirectory = Join-Path $logsDirectory "generated-initterm-guest-image"
    if (Test-Path -LiteralPath $imageDirectory) {
        Remove-Item -LiteralPath $imageDirectory -Recurse -Force
    }
    $imageLog = & $python $imageGenerator --reference $ReferencePe `
        --candidate $CandidatePe --closure $closureDirectory `
        --output $imageDirectory 2>&1
    $imageLog | Tee-Object -FilePath (Join-Path $logsDirectory "initterm-guest-image.log")
    if ($LASTEXITCODE -ne 0) { throw "Guest image generation failed" }

    # Batch 1 of the C++ initializers: the lifted bodies the walk needs, built
    # from the measured closure, plus the runtime it links.
    $batchClosure = Join-Path $logsDirectory "cpp-batch-1\closure.json"
    $batchOutputDirectory = Join-Path $logsDirectory "generated-cpp-batch-1"
    if (Test-Path -LiteralPath $batchOutputDirectory) {
        Remove-Item -LiteralPath $batchOutputDirectory -Recurse -Force
    }
    $batchLog = & $python $batchGenerator --reference $ReferencePe `
        --candidate $CandidatePe --closure $batchClosure `
        --initializers $BatchInitializers --output $batchOutputDirectory 2>&1
    $batchLog | Tee-Object -FilePath (Join-Path $logsDirectory "cpp-batch-generation.log")
    if ($LASTEXITCODE -ne 0) { throw "C++ initializer batch generation failed" }
    $batchSources = @(
        Get-ChildItem -LiteralPath $batchOutputDirectory -Filter *.cpp |
            ForEach-Object { $_.FullName }
    )

    foreach ($stageName in $Stage) {
        $crtDirectory = Join-Path $logsDirectory ("generated-crt-" + $stageName)
        if (Test-Path -LiteralPath $crtDirectory) {
            Remove-Item -LiteralPath $crtDirectory -Recurse -Force
        }
        $generated = & $python $generator --reference $ReferencePe `
            --candidate $CandidatePe --batch $batch --output $crtDirectory `
            --stage $stageName 2>&1
        $generated | Tee-Object -FilePath (Join-Path $logsDirectory "crt-$stageName-generation.log")
        if ($LASTEXITCODE -ne 0) { throw "CRT prefix generation failed for $stageName" }

        $generatedSources = @(
            (Join-Path $entryTailDirectory "spore_011e11a0.cpp"),
            (Join-Path $cookieDirectory "spore_011e1548_prefix.cpp"),
            (Join-Path $crtDirectory "spore_011e0ee0.cpp")
        )
        $prologSource = Join-Path $crtDirectory "spore_011e11d4.cpp"
        if (Test-Path -LiteralPath $prologSource) {
            $generatedSources += $prologSource
        }

        # Running a table walk needs the initializer bodies and the guest memory
        # image they read. The real _initterm_e/_initterm perform process
        # initialization, so these stages have no original-bytes reference.
        $skipOriginal = $false
        if ($closureStages -contains $stageName) {
            $generatedSources += $closureSources
            $skipOriginal = $true
        }
        if ($stageName -eq "cpp-walk-initializers") {
            $generatedSources += $closureSources
            $generatedSources += $batchSources
            $skipOriginal = $true
        }

        # The _initterm_e closure and the lifted batch overlap on shared CRT
        # bodies; each address is generated by both sets and must link once.
        $seenSource = @{}
        $generatedSources = @(
            $generatedSources | Where-Object {
                $sourceName = [System.IO.Path]::GetFileName($_)
                if ($seenSource.ContainsKey($sourceName)) {
                    $false
                } else {
                    $seenSource[$sourceName] = $true
                    $true
                }
            }
        )

        $includes = @(
            '/I"' + $backendDirectory + '"',
            '/I"' + $entryTailDirectory + '"',
            '/I"' + $cookieDirectory + '"',
            '/I"' + $closureDirectory + '"',
            '/I"' + $imageDirectory + '"',
            '/I"' + $batchOutputDirectory + '"',
            '/I"' + $crtDirectory + '"'
        ) -join ' '
        $originalExecutable = Join-Path $buildDirectory "crt-$stageName-original-x86.exe"
        $liftExecutable = Join-Path $buildDirectory "crt-$stageName-lift-x86.exe"
        $originalObjectDirectory = Join-Path $buildDirectory "original-obj-$stageName"
        $liftObjectDirectory = Join-Path $buildDirectory "lift-obj-$stageName"
        New-Item -ItemType Directory -Path $originalObjectDirectory | Out-Null
        New-Item -ItemType Directory -Path $liftObjectDirectory | Out-Null

        $quotedSources = ($generatedSources | ForEach-Object { '"' + $_ + '"' }) -join ' '
        $originalCommand = 'call "' + $vsDevCmd +
            '" -arch=x86 -host_arch=x64 -no_logo && cl /nologo /std:c++17 /EHsc /O2 /W4 ' +
            $includes + ' /Fo"' + $originalObjectDirectory + '\\" /Fe:"' +
            $originalExecutable + '" "' + $originalHarness + '"'
        $liftCommand = 'call "' + $vsDevCmd +
            '" -arch=x86 -host_arch=x64 -no_logo && cl /nologo /std:c++17 /EHsc /O2 /W4 ' +
            $includes + ' /Fo"' + $liftObjectDirectory + '\\" /Fe:"' +
            $liftExecutable + '" "' + $liftHarness + '" ' + $quotedSources

        if (-not $skipOriginal) {
            $originalBuild = & $env:ComSpec /d /s /c $originalCommand 2>&1
            $originalBuild | Set-Content -LiteralPath (Join-Path $logsDirectory "crt-$stageName-original-x86-build.log")
            if ($LASTEXITCODE -ne 0) {
                $originalBuild | ForEach-Object { Write-Output $_ }
                throw "Windows x86 original CRT build failed for $stageName"
            }
        }
        $liftBuild = & $env:ComSpec /d /s /c $liftCommand 2>&1
        $liftBuild | Set-Content -LiteralPath (Join-Path $logsDirectory "crt-$stageName-lift-x86-build.log")
        if ($LASTEXITCODE -ne 0) {
            $liftBuild | ForEach-Object { Write-Output $_ }
            throw "Windows x86 lift CRT build failed for $stageName"
        }

        $originalOutput = @()
        $originalPass = ""
        $previousPreference = $ErrorActionPreference
        try {
            $ErrorActionPreference = "Continue"
            if (-not $skipOriginal) {
                $originalOutput = & $originalExecutable 2>&1
                $originalCode = $LASTEXITCODE
            }
            $liftOutput = & $liftExecutable 2>&1
            $liftCode = $LASTEXITCODE
        } finally {
            $ErrorActionPreference = $previousPreference
        }
        if (-not $skipOriginal) {
            $originalOutput | Set-Content -LiteralPath (Join-Path $logsDirectory "crt-$stageName-original-x86.log")
        }
        $liftOutput | Set-Content -LiteralPath (Join-Path $logsDirectory "crt-$stageName-lift-x86.log")
        if ((-not $skipOriginal -and $originalCode -ne 0) -or $liftCode -ne 0) {
            $originalOutput | ForEach-Object { Write-Output $_ }
            $liftOutput | ForEach-Object { Write-Output $_ }
            throw "x86 CRT comparison failed for $stageName"
        }
        if (-not $skipOriginal) {
            Assert-OnlyExpectedLines -Output $originalOutput -Label "x86 original $stageName"
        }
        Assert-OnlyExpectedLines -Output $liftOutput -Label "x86 lift $stageName"
        $liftPass = Get-PassLine -Output $liftOutput -Label "x86 lift $stageName"
        if ($skipOriginal) {
            "SKIP original_x86_real_win32 stage=$stageName reason=the_real_crt_walk_initializes_the_process" |
                Set-Content -LiteralPath (Join-Path $logsDirectory "crt-$stageName-differential.log")
            Write-Output "SKIP original_x86_real_win32 stage=$stageName reason=the_real_crt_walk_initializes_the_process"
            $expectedPass = $liftPass
        } else {
            $originalPass = Get-PassLine -Output $originalOutput -Label "x86 original $stageName"
            if ($originalPass -ne $liftPass) {
                throw "PASS lines differ for ${stageName}: [$originalPass] vs [$liftPass]"
            }
            "PASS original_x86_real_win32_vs_lift_x86 $liftPass" |
                Set-Content -LiteralPath (Join-Path $logsDirectory "crt-$stageName-differential.log")
            $expectedPass = $originalPass
        }
        Write-Output "$liftPass"

        $arm64Executable = Join-Path $buildDirectory "crt-$stageName-lift-arm64"
        $clangArguments = @(
            '--target=aarch64-linux-android29', '-std=c++17', '-O2', '-Wall',
            '-Wextra', '-Werror', '-Wno-unused-label',
            "-I$backendDirectory", "-I$entryTailDirectory",
            "-I$cookieDirectory", "-I$closureDirectory",
            "-I$imageDirectory", "-I$batchOutputDirectory", "-I$crtDirectory",
            $liftHarness
        ) + $generatedSources + @('-o', $arm64Executable)
        & $clang @clangArguments 2>&1 |
            Set-Content -LiteralPath (Join-Path $logsDirectory "crt-$stageName-arm64-build.log")
        if ($LASTEXITCODE -ne 0) {
            Get-Content -LiteralPath (Join-Path $logsDirectory "crt-$stageName-arm64-build.log")
            throw "Android ARM64 CRT harness build failed for $stageName"
        }
        Write-Output "PASS arm64_build stage=$stageName target=aarch64-linux-android29"

        if ($BuildOnly -or -not $deviceSelected) { continue }

        $remote = "/data/local/tmp/spore_crt_" + $stageName + "_" + [Guid]::NewGuid().ToString("N")
        $push = Invoke-AdbCommand -Arguments @("-s", $DeviceSerial, "push", $arm64Executable, $remote)
        if ($push.ExitCode -ne 0) { throw "ADB push failed for $stageName" }
        $chmod = Invoke-AdbCommand -Arguments @("-s", $DeviceSerial, "shell", "chmod", "700", $remote)
        if ($chmod.ExitCode -ne 0) { throw "ADB chmod failed for $stageName" }
        $run = Invoke-AdbCommand -Arguments @("-s", $DeviceSerial, "shell", $remote)
        $run.Output | Set-Content -LiteralPath (Join-Path $logsDirectory "crt-$stageName-arm64.log")
        [void](Invoke-AdbCommand -Arguments @("-s", $DeviceSerial, "shell", "rm", "-f", $remote))
        if ($run.ExitCode -ne 0) {
            $run.Output | ForEach-Object { Write-Output $_ }
            throw "ARM64 CRT run failed for $stageName"
        }
        Assert-OnlyExpectedLines -Output $run.Output -Label "ARM64 $stageName"
        $arm64Pass = Get-PassLine -Output $run.Output -Label "ARM64 $stageName"
        if ($arm64Pass -ne $expectedPass) {
            throw "ARM64 snapshot differs for ${stageName}: [$arm64Pass] vs [$expectedPass]"
        }
        Write-Output "PASS x86_vs_arm64 $arm64Pass"
        Write-Output "PASS arm64_device_run stage=$stageName serial=$DeviceSerial"
    }
} finally {
    if (Test-Path -LiteralPath $buildDirectory) {
        for ($attempt = 0; $attempt -lt 40; $attempt++) {
            try {
                Remove-Item -LiteralPath $buildDirectory -Recurse -Force `
                    -ErrorAction Stop
                break
            } catch {
                Start-Sleep -Milliseconds 250
            }
        }
        if (Test-Path -LiteralPath $buildDirectory) {
            Write-Output "WARN build_directory_not_removed=$buildDirectory"
        }
    }
}
