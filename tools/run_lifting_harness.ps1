$ErrorActionPreference = "Stop"

$adb = Join-Path $env:LOCALAPPDATA "Android\Sdk\platform-tools\adb.exe"
$binary = Join-Path $PSScriptRoot "lifting_harness_arm64"
$remote = "/data/local/tmp/lifting_harness_arm64"
$arrayBinary = Join-Path $PSScriptRoot "lifted_array_kernel_arm64"
$arrayRemote = "/data/local/tmp/lifted_array_kernel_arm64"
$lowerBinary = Join-Path $PSScriptRoot "lifted_lower_bound_arm64"
$lowerRemote = "/data/local/tmp/lifted_lower_bound_arm64"

if (-not (Test-Path $adb)) {
    throw "ADB not found: $adb"
}
if (-not (Test-Path $binary)) {
    throw "ARM64 executable not found. Run build_lifting_harness.ps1 first."
}

& $adb wait-for-device
& $adb shell getprop ro.product.cpu.abi
& $adb push $binary $remote
if ($LASTEXITCODE -ne 0) {
    throw "Failed to push ARM64 executable"
}

& $adb shell chmod 755 $remote
& $adb shell "unset LD_PRELOAD; $remote"
if ($LASTEXITCODE -ne 0) {
    throw "ARM64 executable failed on device/emulator"
}

if (-not (Test-Path $arrayBinary)) {
    throw "Lifted array kernel not found. Run build_lifting_harness.ps1 first."
}
& $adb push $arrayBinary $arrayRemote
if ($LASTEXITCODE -ne 0) {
    throw "Failed to push lifted array kernel"
}
& $adb shell chmod 755 $arrayRemote
& $adb shell "unset LD_PRELOAD; $arrayRemote"
if ($LASTEXITCODE -ne 0) {
    throw "Lifted array kernel failed on Android"
}

if (-not (Test-Path $lowerBinary)) {
    throw "Lifted lower-bound executable not found. Run build_lifting_harness.ps1 first."
}
& $adb push $lowerBinary $lowerRemote
if ($LASTEXITCODE -ne 0) {
    throw "Failed to push lifted lower-bound executable"
}
& $adb shell chmod 755 $lowerRemote
& $adb shell "unset LD_PRELOAD; $lowerRemote"
if ($LASTEXITCODE -ne 0) {
    throw "Lifted lower-bound executable failed on Android"
}
