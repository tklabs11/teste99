param(
    [string]$PePath = "C:\SporeAnalysis\SporeApp.exe",
    [string]$DeviceSerial = "",
    [switch]$BuildOnly
)

$ErrorActionPreference = "Stop"
$toolsDirectory = $PSScriptRoot
$backendDirectory = Join-Path $toolsDirectory "batch_static_lift"
$generator = Join-Path $backendDirectory "generate_call_closure.py"
$harness = Join-Path $backendDirectory "call_closure_harness.cpp"
$recursiveBatch = "C:\SporeAnalysis\spore_batch_pilot_100.json"
$callerBatch = "C:\SporeAnalysis\spore_batch_all_parts\spore_batch_all_0051.json"
$calleeBatch = "C:\SporeAnalysis\spore_batch_all_parts\spore_batch_all_0050.json"
$startupOuterBatch = "C:\SporeAnalysis\spore_batch_all_parts\spore_batch_all_0041.json"
$startupInnerBatch = "C:\SporeAnalysis\spore_batch_all_parts\spore_batch_all_0086.json"
$startupHelperBatch = "C:\SporeAnalysis\spore_batch_all_parts\spore_batch_all_0034.json"
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

function Invoke-AdbChecked {
    param(
        [string[]]$Arguments,
        [string]$FailureMessage
    )

    $previousPreference = $ErrorActionPreference
    try {
        $ErrorActionPreference = "Continue"
        $output = & $adb @Arguments 2>&1
        $exitCode = $LASTEXITCODE
    } finally {
        $ErrorActionPreference = $previousPreference
    }
    foreach ($line in $output) {
        if ($line -is [System.Management.Automation.ErrorRecord]) {
            Write-Output $line.Exception.Message
        } else {
            Write-Output $line
        }
    }
    if ($exitCode -ne 0) {
        throw "$FailureMessage (adb exit code $exitCode)"
    }
}

foreach ($requiredPath in @(
    $PePath, $recursiveBatch, $callerBatch, $calleeBatch,
    $startupOuterBatch, $startupInnerBatch, $startupHelperBatch, $adb, $clang
)) {
    if (-not (Test-Path -LiteralPath $requiredPath)) {
        throw "Required input or tool was not found: $requiredPath"
    }
}

$vswhere = Join-Path ${env:ProgramFiles(x86)} "Microsoft Visual Studio\Installer\vswhere.exe"
if (-not (Test-Path -LiteralPath $vswhere)) {
    throw "Visual Studio locator not found: $vswhere"
}
$vsInstall = & $vswhere -latest -products "*" -property installationPath
if ($LASTEXITCODE -ne 0 -or -not $vsInstall) {
    throw "Could not locate Visual Studio Build Tools"
}
$vsDevCmd = Join-Path $vsInstall "Common7\Tools\VsDevCmd.bat"
if (-not (Test-Path -LiteralPath $vsDevCmd)) {
    throw "Visual Studio environment script not found: $vsDevCmd"
}

$buildDirectory = Join-Path $env:TEMP ("spore-batch-call-lift-" + [Guid]::NewGuid().ToString("N"))
New-Item -ItemType Directory -Path $buildDirectory | Out-Null
$recursiveOutput = Join-Path $buildDirectory "recursive"
$crossCallOutput = Join-Path $buildDirectory "cross_call"
$startupResmanOutput = Join-Path $buildDirectory "startup_resman"
$recursiveSource = Join-Path $recursiveOutput "spore_006237a0_arm64.cpp"
$calleeSource = Join-Path $crossCallOutput "spore_00b8dab0_arm64.cpp"
$callerSource = Join-Path $crossCallOutput "spore_00bb9b70_arm64.cpp"
$resmanSources = @(
    (Join-Path $startupResmanOutput "spore_00a247f0_arm64.cpp"),
    (Join-Path $startupResmanOutput "spore_009222a0_arm64.cpp"),
    (Join-Path $startupResmanOutput "spore_00922150_arm64.cpp"),
    (Join-Path $startupResmanOutput "spore_011e5d80_arm64.cpp"),
    (Join-Path $startupResmanOutput "spore_011e8b20_arm64.cpp")
)
$recursiveBytes = Join-Path $buildDirectory "recursive_reference_bytes.hpp"
$crossCallBytes = Join-Path $buildDirectory "cross_call_reference_bytes.hpp"
$resmanBytes = Join-Path $buildDirectory "startup_resman_reference_bytes.hpp"
$x86Executable = Join-Path $buildDirectory "batch_call_lift_x86.exe"
$arm64Executable = Join-Path $buildDirectory "batch_call_lift_arm64"
$remoteExecutable = "/data/local/tmp/spore_batch_call_lift"
$deviceSelected = $false

try {
    & $python $generator --exe $PePath --batch $recursiveBatch `
        --entry 0x006237a0 --output-dir $recursiveOutput `
        --report (Join-Path $recursiveOutput "report.json") `
        --byte-header $recursiveBytes
    if ($LASTEXITCODE -ne 0) {
        throw "Recursive call-closure generation failed"
    }
    & $python $generator --exe $PePath `
        --batch $callerBatch --batch $calleeBatch `
        --entry 0x00bb9b70 --output-dir $crossCallOutput `
        --report (Join-Path $crossCallOutput "report.json") `
        --byte-header $crossCallBytes
    if ($LASTEXITCODE -ne 0) {
        throw "Distinct-function call-closure generation failed"
    }
    & $python $generator --exe $PePath `
        --batch $startupOuterBatch --batch $startupInnerBatch `
        --batch $startupHelperBatch --entry 0x00a247f0 `
        --output-dir $startupResmanOutput `
        --report (Join-Path $startupResmanOutput "report.json") `
        --byte-header $resmanBytes --data-string-va 0x01449334
    if ($LASTEXITCODE -ne 0) {
        throw "Import-boundary startup call-closure generation failed"
    }

    $buildCommand = 'call "' + $vsDevCmd +
        '" -no_logo -arch=x86 -host_arch=x64 && pushd "' + $buildDirectory +
        '" && cl /nologo /std:c++17 /EHsc /O2 /W4 /I"' +
        $backendDirectory + '" /I"' + $buildDirectory + '" /Fe:"' +
        $x86Executable + '" "' + $harness + '" "' + $recursiveSource +
        '" "' + $calleeSource + '" "' + $callerSource + '" "' +
        ($resmanSources -join '" "') + '"'
    & $env:ComSpec /d /s /c $buildCommand
    if ($LASTEXITCODE -ne 0) {
        throw "Windows x86 reference-vs-generated-lift build failed"
    }
    & $x86Executable
    if ($LASTEXITCODE -ne 0) {
        throw "Windows x86 reference-vs-generated-lift comparison failed"
    }

    & $clang "--target=aarch64-linux-android29" "-std=c++17" "-O2" "-pthread" `
        "-Wall" "-Wextra" "-Werror" "-I$backendDirectory" "-I$buildDirectory" `
        $harness $recursiveSource $calleeSource $callerSource `
        $resmanSources `
        "-o" $arm64Executable
    if ($LASTEXITCODE -ne 0) {
        throw "Android ARM64 generated-lift harness build failed"
    }
    Write-Output "PASS arm64_compile target=aarch64-linux-android29"
    if ($BuildOnly) {
        Write-Output "DEVICE_RUN_SKIPPED=BuildOnly"
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
        Write-Output "DEVICE_RUN_SKIPPED=no_connected_authorized_device"
        return
    }
    $deviceSelected = $true
    Invoke-AdbChecked `
        -Arguments @("-s", $DeviceSerial, "push", $arm64Executable, $remoteExecutable) `
        -FailureMessage "Could not push ARM64 call-closure harness to $DeviceSerial"
    Invoke-AdbChecked `
        -Arguments @("-s", $DeviceSerial, "shell", "chmod", "700", $remoteExecutable) `
        -FailureMessage "Could not set executable permission on the ARM64 harness"
    Invoke-AdbChecked `
        -Arguments @("-s", $DeviceSerial, "shell", $remoteExecutable) `
        -FailureMessage "ARM64 call-closure harness failed on device $DeviceSerial"
    Write-Output "PASS arm64_device_run serial=$DeviceSerial"
} finally {
    if ($deviceSelected) {
        $previousPreference = $ErrorActionPreference
        try {
            $ErrorActionPreference = "Continue"
            $cleanupOutput = & $adb -s $DeviceSerial shell rm -f $remoteExecutable 2>&1
            $cleanupExitCode = $LASTEXITCODE
        } finally {
            $ErrorActionPreference = $previousPreference
        }
        foreach ($line in $cleanupOutput) {
            if ($line -is [System.Management.Automation.ErrorRecord]) {
                Write-Output $line.Exception.Message
            } else {
                Write-Output $line
            }
        }
        if ($cleanupExitCode -ne 0) {
            Write-Warning "Could not remove the temporary device harness (adb exit code $cleanupExitCode)"
        }
    }
    if (Test-Path -LiteralPath $buildDirectory) {
        Remove-Item -LiteralPath $buildDirectory -Recurse -Force
    }
}
