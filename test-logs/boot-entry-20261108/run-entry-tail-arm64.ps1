param([string]$DeviceSerial = "PJMZAEJRX4YLFIDI", [switch]$BuildOnly)

$ErrorActionPreference = "Stop"
$root = (Resolve-Path (Join-Path $PSScriptRoot "..\..")).Path
$clang = "C:\Users\wesll\AppData\Local\Android\Sdk\ndk\29.0.14206865\toolchains\llvm\prebuilt\windows-x86_64\bin\clang++.exe"
$adb = "C:\platform-tools\adb.exe"
$binary = Join-Path $PSScriptRoot "entry_tail_lift_arm64"
$buildLog = Join-Path $PSScriptRoot "entry-tail-arm64-build.log"
$deviceLog = Join-Path $PSScriptRoot "entry-tail-arm64-device.log"
$sources = @(
    (Join-Path $root "tools\batch_static_lift\boot_entry_tail_harness.cpp"),
    (Join-Path $PSScriptRoot "generated-entry-tail\spore_011e11a0.cpp")
)
& $clang --target=aarch64-linux-android29 -std=c++17 -O2 `
    -I (Join-Path $root "tools\batch_static_lift") `
    -o $binary @sources *> $buildLog
if ($LASTEXITCODE -ne 0) { Get-Content $buildLog; throw "ARM64 build failed" }
"PASS ARM64 build" | Add-Content $buildLog
if ($BuildOnly) { Get-Content $buildLog -Tail 1; return }

& $adb -s $DeviceSerial push $binary /data/local/tmp/spore_entry_tail_arm64
if ($LASTEXITCODE -ne 0) { throw "ADB push failed" }
& $adb -s $DeviceSerial shell chmod 700 /data/local/tmp/spore_entry_tail_arm64
if ($LASTEXITCODE -ne 0) { throw "ADB chmod failed" }
& $adb -s $DeviceSerial shell /data/local/tmp/spore_entry_tail_arm64 *> $deviceLog
if ($LASTEXITCODE -ne 0) { Get-Content $deviceLog; throw "ARM64 run failed" }
Get-Content $deviceLog
