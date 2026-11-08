param([string]$DeviceSerial = "PJMZAEJRX4YLFIDI")

$ErrorActionPreference = "Stop"
$root = (Resolve-Path (Join-Path $PSScriptRoot "..\..")).Path
$clang = "C:\Users\wesll\AppData\Local\Android\Sdk\ndk\29.0.14206865\toolchains\llvm\prebuilt\windows-x86_64\bin\clang++.exe"
$adb = "C:\platform-tools\adb.exe"
$binary = Join-Path $PSScriptRoot "time-import-tests-arm64"
& $clang --target=aarch64-linux-android29 -std=c++17 -O2 `
    -I (Join-Path $root "tools\batch_static_lift") `
    -o $binary (Join-Path $root "tools\batch_static_lift\boot_time_import_tests.cpp") `
    *> (Join-Path $PSScriptRoot "time-import-tests-arm64-build.log")
if ($LASTEXITCODE -ne 0) { throw "ARM64 build failed" }
& $adb -s $DeviceSerial push $binary /data/local/tmp/spore_time_import_tests_arm64
if ($LASTEXITCODE -ne 0) { throw "ADB push failed" }
& $adb -s $DeviceSerial shell chmod 700 /data/local/tmp/spore_time_import_tests_arm64
if ($LASTEXITCODE -ne 0) { throw "ADB chmod failed" }
& $adb -s $DeviceSerial shell /data/local/tmp/spore_time_import_tests_arm64 `
    *> (Join-Path $PSScriptRoot "time-import-tests-arm64-device.log")
if ($LASTEXITCODE -ne 0) {
    Get-Content (Join-Path $PSScriptRoot "time-import-tests-arm64-device.log")
    throw "ARM64 test failed"
}
Get-Content (Join-Path $PSScriptRoot "time-import-tests-arm64-device.log")
