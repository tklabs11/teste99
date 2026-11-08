param(
    [string]$ReferencePe = "C:\SporeAnalysis\SporeApp.exe",
    [string]$CandidatePe = "C:\Program Files (x86)\Steam\steamapps\common\Spore\SPOREFILES\SporeBin\SporeApp.exe",
    [string]$BatchDirectory = "C:\SporeAnalysis\spore_batch_all_parts",
    [string]$DeviceSerial = "",
    [switch]$BuildOnly
)

$ErrorActionPreference = "Stop"
$toolsDirectory = $PSScriptRoot
$repoRoot = Split-Path $toolsDirectory -Parent
$backendDirectory = Join-Path $toolsDirectory "batch_static_lift"
$logsDirectory = Join-Path $repoRoot "test-logs\boot-entry-20261108"
$generator = Join-Path $backendDirectory "generate_boot_pid_prefix.py"
$originalHarness = Join-Path $backendDirectory "boot_cookie_pid_original_x86.cpp"
$liftHarness = Join-Path $backendDirectory "boot_cookie_pid_prefix_harness.cpp"
$entryTailSource = Join-Path $logsDirectory "generated-entry-tail\spore_011e11a0.cpp"
$entryTailDirectory = Join-Path $logsDirectory "generated-entry-tail"
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
$adbCandidates = @(
    (Join-Path $sdkRoot "platform-tools\adb.exe"),
    "C:\platform-tools\adb.exe"
)
$adb = $adbCandidates | Where-Object { Test-Path -LiteralPath $_ } | Select-Object -First 1

$stages = @(
    @{ Name = "pid-prefix"; Stage = "pid-call-boundary"; Chain = $true },
    @{ Name = "pid-call-prefix"; Stage = "pid-call-executed"; Chain = $true },
    @{ Name = "entropy-prefix"; Stage = "entropy-complete"; Chain = $true },
    @{ Name = "cookie-prefix"; Stage = "cookie-complete"; Chain = $false }
)

$buildDirectory = Join-Path $env:TEMP ("spore-boot-pid-" + [Guid]::NewGuid().ToString("N"))
New-Item -ItemType Directory -Path $buildDirectory -Force | Out-Null
$deviceSelected = $false

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

foreach ($requiredPath in @(
    $ReferencePe, $CandidatePe, $batch, $generator,
    $originalHarness, $liftHarness, $entryTailSource, $vsDevCmd
)) {
    if (-not (Test-Path -LiteralPath $requiredPath)) {
        throw "Required input or tool was not found: $requiredPath"
    }
}

try {
    foreach ($stage in $stages) {
        $generatedDirectory = Join-Path $logsDirectory ("generated-cookie-" + $stage.Name)
        $manifest = Join-Path $generatedDirectory "manifest.json"
        if (-not (Test-Path -LiteralPath $manifest)) {
            $generatorOutput = & $python $generator `
                --reference $ReferencePe `
                --candidate $CandidatePe `
                --batch $batch `
                --output $generatedDirectory `
                --stage $stage.Stage 2>&1
            if ($LASTEXITCODE -ne 0) {
                $generatorOutput | ForEach-Object { Write-Output $_ }
                throw "Boot prefix generation failed for stage $($stage.Stage)"
            }
            $generatorOutput | ForEach-Object { Write-Output $_ }
            "GENERATED=$generatedDirectory" |
                Set-Content -LiteralPath (Join-Path $logsDirectory ("$($stage.Name)-generation.log"))
        } else {
            "REUSED_GENERATED=$generatedDirectory" |
                Set-Content -LiteralPath (Join-Path $logsDirectory ("$($stage.Name)-generation.log"))
        }
        $manifestData = Get-Content -LiteralPath $manifest -Raw | ConvertFrom-Json
        if ($manifestData.stage -ne $stage.Stage) {
            throw "Generated manifest stage mismatch in $manifest"
        }
        $stage.Boundary = $manifestData.boundary
        $stage.PidExecuted = [bool]$manifestData.process_id_call_executed

        $originalExecutable = Join-Path $buildDirectory ("$($stage.Name)-original-x86.exe")
        $liftExecutable = Join-Path $buildDirectory ("$($stage.Name)-lift-x86.exe")
        $originalObjectDirectory = Join-Path $buildDirectory ("$($stage.Name)-original-obj")
        $liftObjectDirectory = Join-Path $buildDirectory ("$($stage.Name)-lift-obj")
        New-Item -ItemType Directory -Path $originalObjectDirectory | Out-Null
        New-Item -ItemType Directory -Path $liftObjectDirectory | Out-Null

        $chainSource = if ($stage.Chain) {
            '"' + $entryTailSource + '" '
        } else { '' }
        $chainDefine = if ($stage.Chain) { '/DBOOT_ENTRY_CHAIN ' } else { '' }
        $entryTailInclude = if ($stage.Chain) {
            ' /I"' + $entryTailDirectory + '"'
        } else { '' }

        $originalCommand = 'call "' + $vsDevCmd +
            '" -arch=x86 -host_arch=x64 -no_logo && cl /nologo /std:c++17 /EHsc /O2 /W4 ' +
            $chainDefine +
            '/I"' + $backendDirectory + '" /I"' + $generatedDirectory + '"' +
            $entryTailInclude + ' /Fo"' + $originalObjectDirectory + '\\" /Fe:"' +
            $originalExecutable + '" "' + $originalHarness + '"'
        $liftCommand = 'call "' + $vsDevCmd +
            '" -arch=x86 -host_arch=x64 -no_logo && cl /nologo /std:c++17 /EHsc /O2 /W4 ' +
            $chainDefine +
            '/I"' + $backendDirectory + '" /I"' + $generatedDirectory + '"' +
            $entryTailInclude + ' /Fo"' + $liftObjectDirectory + '\\" /Fe:"' +
            $liftExecutable + '" "' + $liftHarness + '" ' + $chainSource + '"' +
            (Join-Path $generatedDirectory "spore_011e1548_prefix.cpp") + '"'

        $originalBuild = & $env:ComSpec /d /s /c $originalCommand 2>&1
        $originalBuild | Set-Content -LiteralPath (Join-Path $logsDirectory ("$($stage.Name)-original-x86-build.log"))
        if ($LASTEXITCODE -ne 0) {
            $originalBuild | ForEach-Object { Write-Output $_ }
            throw "Windows x86 original build failed for stage $($stage.Stage)"
        }
        $liftBuild = & $env:ComSpec /d /s /c $liftCommand 2>&1
        $liftBuild | Set-Content -LiteralPath (Join-Path $logsDirectory ("$($stage.Name)-lift-x86-build.log"))
        if ($LASTEXITCODE -ne 0) {
            $liftBuild | ForEach-Object { Write-Output $_ }
            throw "Windows x86 lift build failed for stage $($stage.Stage)"
        }

        $previousPreference = $ErrorActionPreference
        try {
            $ErrorActionPreference = "Continue"
            $originalOutput = & $originalExecutable 2>&1
            $originalCode = $LASTEXITCODE
            $liftOutput = & $liftExecutable 2>&1
            $liftCode = $LASTEXITCODE
        } finally {
            $ErrorActionPreference = $previousPreference
        }
        $originalOutput | Set-Content -LiteralPath (Join-Path $logsDirectory ("$($stage.Name)-original-x86.log"))
        $liftOutput | Set-Content -LiteralPath (Join-Path $logsDirectory ("$($stage.Name)-lift-x86.log"))
        if ($originalCode -ne 0 -or $liftCode -ne 0) {
            $originalOutput | ForEach-Object { Write-Output $_ }
            $liftOutput | ForEach-Object { Write-Output $_ }
            throw "x86 comparison failed for stage $($stage.Stage)"
        }
        $originalPass = @($originalOutput | Where-Object { "$_" -match '^PASS ' })[0]
        $liftPass = @($liftOutput | Where-Object { "$_" -match '^PASS ' })[0]
        if (-not $originalPass -or -not $liftPass) {
            throw "Missing PASS line for stage $($stage.Stage)"
        }
        foreach ($entry in @(
            @{ Name = "original"; Lines = $originalOutput },
            @{ Name = "lift"; Lines = $liftOutput }
        )) {
            $unexpected = @($entry.Lines | Where-Object { "$_" -notmatch '^(PASS|DETAIL) ' })
            if ($unexpected.Count -gt 0) {
                throw "Unexpected $($entry.Name) x86 output for stage $($stage.Stage): $($unexpected -join ' | ')"
            }
        }
        if ("$originalPass" -ne "$liftPass") {
            throw "PASS lines differ for stage $($stage.Stage): [$originalPass] vs [$liftPass]"
        }
        "PASS original_x86_real_win32_vs_lift_x86 $originalPass" |
            Set-Content -LiteralPath (Join-Path $logsDirectory ("$($stage.Name)-differential.log"))
        Write-Output "$originalPass"
    }

    if ($BuildOnly) {
        Write-Output "PASS x86_differential"
    }

    # Compile the ARM64 binary even without a device so the lift stays
    # build-verified on the local machine.
    foreach ($stage in $stages) {
        $generatedDirectory = Join-Path $logsDirectory ("generated-cookie-" + $stage.Name)
        $arm64Executable = Join-Path $buildDirectory ("$($stage.Name)-lift-arm64")
        & $clang --target=aarch64-linux-android29 -std=c++17 -O2 -Wall -Wextra -Werror `
            -Wno-unused-label `
            $(if ($stage.Chain) { '-DBOOT_ENTRY_CHAIN' } else { '-DSPORE_COOKIE_STANDALONE' }) `
            "-I$backendDirectory" "-I$generatedDirectory" `
            $(if ($stage.Chain) { "-I$entryTailDirectory" } else { "-I$backendDirectory" }) `
            $liftHarness $(if ($stage.Chain) { $entryTailSource } else { '' }) `
            (Join-Path $generatedDirectory "spore_011e1548_prefix.cpp") `
            -o $arm64Executable 2>&1 |
            Set-Content -LiteralPath (Join-Path $logsDirectory ("$($stage.Name)-arm64-build.log"))
        if ($LASTEXITCODE -ne 0) {
            Get-Content -LiteralPath (Join-Path $logsDirectory ("$($stage.Name)-arm64-build.log"))
            throw "ARM64 build failed for stage $($stage.Stage)"
        }
        $stage.Arm64Executable = $arm64Executable
    }
    Write-Output "PASS arm64_build target=aarch64-linux-android29"

    if ($BuildOnly) {
        foreach ($stage in $stages) {
            "DEVICE_RUN_SKIPPED=BuildOnly" |
                Set-Content -LiteralPath (Join-Path $logsDirectory ("$($stage.Name)-arm64.log"))
        }
        Write-Output "DEVICE_RUN_SKIPPED=BuildOnly"
        return
    }

    if (-not $adb) {
        foreach ($stage in $stages) {
            "DEVICE_RUN_SKIPPED=adb_not_found" |
                Set-Content -LiteralPath (Join-Path $logsDirectory ("$($stage.Name)-arm64.log"))
        }
        Write-Output "DEVICE_RUN_SKIPPED=adb_not_found"
        return
    }
    if (-not $DeviceSerial) {
        $devices = @(
            & $adb devices |
                Where-Object { $_ -match '^\S+\s+device$' } |
                ForEach-Object { ($_ -split '\s+')[0] }
        )
        if ($devices.Count -eq 1) { $DeviceSerial = $devices[0] }
    }
    if (-not $DeviceSerial) {
        foreach ($stage in $stages) {
            "DEVICE_RUN_SKIPPED=no_connected_authorized_device" |
                Set-Content -LiteralPath (Join-Path $logsDirectory ("$($stage.Name)-arm64.log"))
        }
        Write-Output "DEVICE_RUN_SKIPPED=no_connected_authorized_device"
        return
    }
    $deviceState = & $adb -s $DeviceSerial get-state 2>$null
    if ($LASTEXITCODE -ne 0 -or $deviceState -ne "device") {
        throw "Requested ADB device is not connected and authorized: $DeviceSerial"
    }

    $deviceSelected = $true
    foreach ($stage in $stages) {
        $arm64Executable = $stage.Arm64Executable
        $remote = "/data/local/tmp/spore_boot_" + $stage.Name + "_" + [Guid]::NewGuid().ToString("N")
        $push = Invoke-AdbCommand -Arguments @("-s", $DeviceSerial, "push", $arm64Executable, $remote)
        if ($push.ExitCode -ne 0) { throw "ADB push failed for stage $($stage.Stage)" }
        $chmod = Invoke-AdbCommand -Arguments @("-s", $DeviceSerial, "shell", "chmod", "700", $remote)
        if ($chmod.ExitCode -ne 0) { throw "ADB chmod failed for stage $($stage.Stage)" }
        $run = Invoke-AdbCommand -Arguments @("-s", $DeviceSerial, "shell", $remote)
        $run.Output | Set-Content -LiteralPath (Join-Path $logsDirectory ("$($stage.Name)-arm64.log"))
        [void](Invoke-AdbCommand -Arguments @("-s", $DeviceSerial, "shell", "rm", "-f", $remote))
        if ($run.ExitCode -ne 0) {
            $run.Output | ForEach-Object { Write-Output $_ }
            throw "ARM64 run failed for stage $($stage.Stage)"
        }
        $arm64Unexpected = @($run.Output | Where-Object { "$_" -notmatch '^(PASS|DETAIL) ' })
        if ($arm64Unexpected.Count -gt 0) {
            throw "Unexpected ARM64 output for stage $($stage.Stage): $($arm64Unexpected -join ' | ')"
        }
        $arm64Pass = @($run.Output | Where-Object { "$_" -match '^PASS ' })[0]
        $x86Pass = (Get-Content -LiteralPath (Join-Path $logsDirectory ("$($stage.Name)-differential.log")) -Raw).Trim()
        $x86Pass = $x86Pass -replace '^PASS original_x86_real_win32_vs_lift_x86 ', ''
        if ("$arm64Pass" -ne "$x86Pass") {
            throw "ARM64 snapshot differs for stage $($stage.Stage): [$arm64Pass] vs [$x86Pass]"
        }
        Write-Output "PASS x86_vs_arm64 $arm64Pass"
    }
    Write-Output "PASS arm64_device_run serial=$DeviceSerial"
} finally {
    if (Test-Path -LiteralPath $buildDirectory) {
        Remove-Item -LiteralPath $buildDirectory -Recurse -Force
    }
}
