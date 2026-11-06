param(
    [string]$PePath = "C:\SporeAnalysis\SporeApp.exe",
    [string]$BatchDirectory = "C:\SporeAnalysis\spore_batch_all_parts",
    [string]$DeviceSerial = "",
    [switch]$BuildOnly
)

$ErrorActionPreference = "Stop"
$toolsDirectory = $PSScriptRoot
$repoRoot = Split-Path $toolsDirectory -Parent
$backendDirectory = Join-Path $toolsDirectory "batch_static_lift"
$generator = Join-Path $backendDirectory "generate_function_prefix.py"
$harness = Join-Path $backendDirectory "constructor_prefix_harness.cpp"
$rootBatch = Join-Path $BatchDirectory "spore_batch_all_0041.json"
$childBatch = Join-Path $BatchDirectory "spore_batch_all_0021.json"
$boundaryBatch = Join-Path $BatchDirectory "spore_batch_all_0034.json"
$python = (Get-Command python.exe -ErrorAction Stop).Source
$sdkRoot = if ($env:ANDROID_SDK_ROOT) {
    $env:ANDROID_SDK_ROOT
} elseif ($env:ANDROID_HOME) {
    $env:ANDROID_HOME
} else {
    Join-Path $env:LOCALAPPDATA "Android\Sdk"
}
$adb = Join-Path $sdkRoot "platform-tools\adb.exe"
$ndkRoot = if ($env:ANDROID_NDK_HOME) {
    $env:ANDROID_NDK_HOME
} else {
    Join-Path $sdkRoot "ndk\29.0.14206865"
}
$clang = Join-Path $ndkRoot "toolchains\llvm\prebuilt\windows-x86_64\bin\clang++.exe"
$vswhere = Join-Path ${env:ProgramFiles(x86)} "Microsoft Visual Studio\Installer\vswhere.exe"
$logsRoot = Join-Path $repoRoot "test-logs"
$runName = "constructor-prefix-00a33600-" + (Get-Date -Format "yyyyMMdd-HHmmssfff")
$runDirectory = Join-Path $logsRoot $runName
$generatedDirectory = Join-Path $runDirectory "generated"
$buildDirectory = Join-Path $env:TEMP ("spore-constructor-prefix-" + [Guid]::NewGuid().ToString("N"))
$remoteExecutable = "/data/local/tmp/spore_constructor_prefix_" + [Guid]::NewGuid().ToString("N")
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
    return [PSCustomObject]@{
        Output = @($output)
        ExitCode = $exitCode
    }
}

foreach ($requiredPath in @(
    $PePath, $rootBatch, $childBatch, $boundaryBatch,
    $generator, $harness, $adb, $clang, $vswhere
)) {
    if (-not (Test-Path -LiteralPath $requiredPath)) {
        throw "Required input or tool was not found: $requiredPath"
    }
}
if (Test-Path -LiteralPath $runDirectory) {
    throw "Refusing to overwrite an existing run directory: $runDirectory"
}
New-Item -ItemType Directory -Path $generatedDirectory -Force | Out-Null
New-Item -ItemType Directory -Path $buildDirectory | Out-Null

$source = Join-Path $generatedDirectory "spore_00a33600_prefix.cpp"
$byteHeader = Join-Path $generatedDirectory "prefix_reference_bytes.hpp"
$report = Join-Path $generatedDirectory "report.json"
$x86Log = Join-Path $runDirectory "windows-x86.log"
$arm64Log = Join-Path $runDirectory "android-arm64.log"
$comparisonLog = Join-Path $runDirectory "comparison.log"
$x86Executable = Join-Path $buildDirectory "constructor_prefix_x86.exe"
$arm64Executable = Join-Path $buildDirectory "constructor_prefix_arm64"

try {
    $generatorArguments = @(
        $generator,
        "--exe", $PePath,
        "--batch", $rootBatch,
        "--batch", $childBatch,
        "--batch", $boundaryBatch,
        "--entry", "0x00a33600",
        "--stop-at", "0x00a3366a",
        "--include-call-target", "0x00743b50",
        "--output-dir", $generatedDirectory,
        "--report", $report,
        "--byte-header", $byteHeader
    )
    [IO.File]::WriteAllText(
        (Join-Path $runDirectory "generation-command.txt"),
        "python " + ($generatorArguments -join " ") + "`r`n",
        [Text.Encoding]::UTF8
    )
    $generatorOutput = & $python @generatorArguments 2>&1
    $generatorCode = $LASTEXITCODE
    $generatorOutput | Tee-Object -FilePath (Join-Path $runDirectory "generation.log")
    if ($generatorCode -ne 0) {
        throw "Partial-prefix generation failed (exit code $generatorCode)"
    }

    $vsInstall = & $vswhere -latest -products "*" -property installationPath
    if ($LASTEXITCODE -ne 0 -or -not $vsInstall) {
        throw "Could not locate Visual Studio Build Tools"
    }
    $vsDevCmd = Join-Path $vsInstall "Common7\Tools\VsDevCmd.bat"
    if (-not (Test-Path -LiteralPath $vsDevCmd)) {
        throw "Visual Studio environment script not found: $vsDevCmd"
    }
    $buildCommand = 'call "' + $vsDevCmd +
        '" -no_logo -arch=x86 -host_arch=x64 && pushd "' + $buildDirectory +
        '" && cl /nologo /std:c++17 /EHsc /O2 /W4 /I"' +
        $backendDirectory + '" /I"' + $generatedDirectory + '" /Fe:"' +
        $x86Executable + '" "' + $harness + '" "' + $source + '"'
    $buildOutput = & $env:ComSpec /d /s /c $buildCommand 2>&1
    $buildCode = $LASTEXITCODE
    $buildOutput | Tee-Object -FilePath (Join-Path $runDirectory "windows-x86-build.log")
    if ($buildCode -ne 0) {
        throw "Windows x86 differential harness build failed (exit code $buildCode)"
    }

    $previousPreference = $ErrorActionPreference
    try {
        $ErrorActionPreference = "Continue"
        $x86Output = & $x86Executable 2>&1
        $x86Code = $LASTEXITCODE
    } finally {
        $ErrorActionPreference = $previousPreference
    }
    $x86Output | Tee-Object -FilePath $x86Log
    if ($x86Code -ne 0) {
        throw "Windows x86 reference-vs-lift comparison failed (exit code $x86Code)"
    }

    & $clang "--target=aarch64-linux-android29" "-std=c++17" "-O2" `
        "-Wall" "-Wextra" "-Werror" "-I$backendDirectory" "-I$generatedDirectory" `
        $harness $source "-o" $arm64Executable 2>&1 |
        Tee-Object -FilePath (Join-Path $runDirectory "android-arm64-build.log")
    if ($LASTEXITCODE -ne 0) {
        throw "Android ARM64 prefix harness build failed"
    }

    $x86LiftLine = @($x86Output | Where-Object { "$_" -match '^case=lifted_x86 ' })[0]
    if (-not $x86LiftLine) {
        throw "Windows x86 output did not contain the lifted snapshot"
    }
    if ($BuildOnly) {
        "DEVICE_RUN_SKIPPED=BuildOnly" | Set-Content -LiteralPath $arm64Log
        "PASS windows_x86_differential; ARM64 build completed; device run skipped" |
            Tee-Object -FilePath $comparisonLog
        return
    }

    if ($DeviceSerial) {
        $deviceState = & $adb -s $DeviceSerial get-state 2>$null
        if ($LASTEXITCODE -ne 0 -or $deviceState -ne "device") {
            throw "Requested ADB device is not connected and authorized: $DeviceSerial"
        }
    } else {
        $devices = @(
            & $adb devices |
                Where-Object { $_ -match '^\S+\s+device$' } |
                ForEach-Object { ($_ -split '\s+')[0] }
        )
        if ($devices.Count -gt 1) {
            throw "Multiple ADB devices found; provide -DeviceSerial explicitly"
        }
        if ($devices.Count -eq 1) {
            $DeviceSerial = $devices[0]
        }
    }
    if (-not $DeviceSerial) {
        "DEVICE_RUN_SKIPPED=no_connected_authorized_device" |
            Set-Content -LiteralPath $arm64Log
        "PASS windows_x86_differential; ARM64 build completed; no authorized device" |
            Tee-Object -FilePath $comparisonLog
        return
    }

    $deviceSelected = $true
    $pushResult = Invoke-AdbCommand -Arguments @(
        "-s", $DeviceSerial, "push", $arm64Executable, $remoteExecutable
    )
    if ($pushResult.Output) {
        $pushResult.Output |
            Tee-Object -FilePath (Join-Path $runDirectory "device-push.log")
    }
    if ($pushResult.ExitCode -ne 0) {
        throw "Could not push the ARM64 harness to $DeviceSerial"
    }
    $chmodResult = Invoke-AdbCommand -Arguments @(
        "-s", $DeviceSerial, "shell", "chmod", "700", $remoteExecutable
    )
    if ($chmodResult.ExitCode -ne 0) {
        throw "Could not set executable permission on the ARM64 harness"
    }
    $arm64Result = Invoke-AdbCommand -Arguments @(
        "-s", $DeviceSerial, "shell", $remoteExecutable
    )
    $arm64Output = $arm64Result.Output
    $arm64Output | Tee-Object -FilePath $arm64Log
    if ($arm64Result.ExitCode -ne 0) {
        throw "Android ARM64 prefix harness failed on $DeviceSerial (exit code $arm64Code)"
    }
    $arm64LiftLine = @($arm64Output | Where-Object { "$_" -match '^case=lifted_arm64 ' })[0]
    if (-not $arm64LiftLine) {
        throw "Android output did not contain the lifted snapshot"
    }
    $x86Canonical = "$x86LiftLine" -replace '^case=\S+\s+', ''
    $arm64Canonical = "$arm64LiftLine" -replace '^case=\S+\s+', ''
    if ($x86Canonical -ne $arm64Canonical) {
        "FAIL x86-versus-ARM64 snapshot mismatch" |
            Tee-Object -FilePath $comparisonLog
        "x86: $x86Canonical" | Add-Content -LiteralPath $comparisonLog
        "arm64: $arm64Canonical" | Add-Content -LiteralPath $comparisonLog
        throw "x86 and ARM64 guest snapshots differ"
    }
    @(
        "PASS original_x86_vs_lifted_x86"
        "PASS lifted_x86_vs_lifted_arm64"
        "PASS arm64_device_run serial=$DeviceSerial"
        "BOUNDARY=0x00a3366a target=FUN_00921f00 status=unsupported_dependency"
    ) | Tee-Object -FilePath $comparisonLog
} finally {
    if ($deviceSelected) {
        $cleanupResult = Invoke-AdbCommand -Arguments @(
            "-s", $DeviceSerial, "shell", "rm", "-f", $remoteExecutable
        )
        if ($cleanupResult.ExitCode -ne 0) {
            Write-Warning "Could not remove the temporary device harness"
        }
    }
    if (Test-Path -LiteralPath $buildDirectory) {
        Remove-Item -LiteralPath $buildDirectory -Recurse -Force
    }
}
