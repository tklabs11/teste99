param(
    [string]$PePath = "C:\SporeAnalysis\SporeApp.exe",
    [string]$DeviceSerial = "",
    [switch]$BuildOnly
)

$ErrorActionPreference = "Stop"
$toolsDirectory = $PSScriptRoot
$generator = Join-Path $toolsDirectory "generate_recursive_call_lift.py"
$generatedDirectory = Join-Path $toolsDirectory "call_chain_lift\generated"
$generatedSource = Join-Path $generatedDirectory "spore_006237a0_arm64.cpp"
$byteHeader = Join-Path $generatedDirectory "spore_006237a0_bytes.hpp"
$x86Source = Join-Path $toolsDirectory "call_chain_lift\x86_reference.cpp"
$guestSource = Join-Path $toolsDirectory "call_chain_lift\guest_main.cpp"
$runtimeInclude = Join-Path $toolsDirectory "x86_lift_differential"
$guestInclude = Join-Path $toolsDirectory "call_chain_lift"
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

if (-not (Test-Path -LiteralPath $PePath)) {
    throw "Reference PE not found: $PePath"
}
if (-not (Test-Path -LiteralPath $adb)) {
    throw "Android platform-tools adb.exe not found: $adb"
}
if (-not (Test-Path -LiteralPath $clang)) {
    throw "Android NDK clang++ not found: $clang"
}

& $python $generator --pe $PePath --output $generatedSource --byte-header $byteHeader
if ($LASTEXITCODE -ne 0) {
    throw "Verified static-lift generation failed"
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

$buildDirectory = Join-Path $env:TEMP ("spore-call-lift-" + [Guid]::NewGuid().ToString("N"))
New-Item -ItemType Directory -Path $buildDirectory | Out-Null
$x86Executable = Join-Path $buildDirectory "spore_call_lift_x86.exe"
$arm64Executable = Join-Path $buildDirectory "spore_call_lift_arm64"
$remoteExecutable = "/data/local/tmp/spore_call_lift_006237a0"
$deviceSelected = $false

try {
    $buildCommand = 'call "' + $vsDevCmd +
        '" -no_logo -arch=x86 -host_arch=x64 && pushd "' + $buildDirectory +
        '" && cl /nologo /std:c++17 /EHsc /O2 /W4 /I"' +
        $runtimeInclude + '" /I"' + $guestInclude + '" /I"' +
        $generatedDirectory + '" /Fe:"' + $x86Executable +
        '" "' + $x86Source + '" "' + $generatedSource + '"'
    & $env:ComSpec /d /s /c $buildCommand
    if ($LASTEXITCODE -ne 0) {
        throw "Windows x86 reference-vs-lift build failed"
    }

    & $x86Executable
    if ($LASTEXITCODE -ne 0) {
        throw "Windows x86 reference-vs-lift comparison failed"
    }

    & $clang "--target=aarch64-linux-android29" "-std=c++17" "-O2" `
        "-Wall" "-Wextra" "-Werror" "-I$runtimeInclude" "-I$guestInclude" `
        "-I$generatedDirectory" $guestSource $generatedSource `
        "-o" $arm64Executable
    if ($LASTEXITCODE -ne 0) {
        throw "Android ARM64 guest harness build failed"
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
        if ($devices.Count -eq 0) {
            throw "No connected ADB device; ARM64 binary compiled but was not executed"
        }
        if ($devices.Count -gt 1) {
            throw "Multiple ADB devices found; provide -DeviceSerial explicitly"
        }
        $DeviceSerial = $devices[0]
    }
    $deviceSelected = $true

    & $adb -s $DeviceSerial push $arm64Executable $remoteExecutable
    if ($LASTEXITCODE -ne 0) {
        throw "Could not push ARM64 guest harness to $DeviceSerial"
    }
    & $adb -s $DeviceSerial shell chmod 700 $remoteExecutable
    if ($LASTEXITCODE -ne 0) {
        throw "Could not set executable permission on the ARM64 harness"
    }
    & $adb -s $DeviceSerial shell $remoteExecutable
    if ($LASTEXITCODE -ne 0) {
        throw "ARM64 guest harness failed on device $DeviceSerial"
    }
    Write-Output "PASS arm64_device_run"
} finally {
    if ($deviceSelected) {
        & $adb -s $DeviceSerial shell rm -f $remoteExecutable | Out-Null
    }
    if (Test-Path -LiteralPath $buildDirectory) {
        Remove-Item -LiteralPath $buildDirectory -Recurse -Force
    }
}
