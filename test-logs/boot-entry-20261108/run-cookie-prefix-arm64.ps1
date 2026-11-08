param(
    [string]$DeviceSerial = "PJMZAEJRX4YLFIDI",
    [switch]$BuildOnly,
    [switch]$EntryChain
)

$ErrorActionPreference = "Stop"
$root = (Resolve-Path (Join-Path $PSScriptRoot "..\..")).Path
$clang = "C:\Users\wesll\AppData\Local\Android\Sdk\ndk\29.0.14206865\toolchains\llvm\prebuilt\windows-x86_64\bin\clang++.exe"
$adb = "C:\platform-tools\adb.exe"
$variant = if ($EntryChain) { "boot-entry-prefix" } else { "cookie-prefix" }
$binary = Join-Path $PSScriptRoot ($variant + "-lift-arm64")
$buildLog = Join-Path $PSScriptRoot ($variant + "-arm64-build.log")
$deviceLog = Join-Path $PSScriptRoot ($variant + "-arm64-device.log")
$sources = @(
    (Join-Path $root "tools\batch_static_lift\boot_cookie_prefix_harness.cpp"),
    (Join-Path $PSScriptRoot "generated-cookie-prefix\spore_011e1548_prefix.cpp")
)
$defines = @()
if ($EntryChain) {
    $defines += "-DBOOT_ENTRY_CHAIN"
    $sources += Join-Path $PSScriptRoot "generated-entry-tail\spore_011e11a0.cpp"
}
& $clang --target=aarch64-linux-android29 -std=c++17 -O2 @defines `
    -I (Join-Path $root "tools\batch_static_lift") `
    -I (Join-Path $PSScriptRoot "generated-cookie-prefix") `
    -o $binary @sources *> $buildLog
if ($LASTEXITCODE -ne 0) { Get-Content $buildLog; throw "ARM64 build failed" }
"PASS ARM64 build" | Add-Content $buildLog
if ($BuildOnly) { Get-Content $buildLog -Tail 1; return }

$deviceBinary = "/data/local/tmp/spore_$($variant.Replace('-', '_'))_arm64"
& $adb -s $DeviceSerial push $binary $deviceBinary
if ($LASTEXITCODE -ne 0) { throw "ADB push failed" }
& $adb -s $DeviceSerial shell chmod 700 $deviceBinary
if ($LASTEXITCODE -ne 0) { throw "ADB chmod failed" }
& $adb -s $DeviceSerial shell $deviceBinary *> $deviceLog
if ($LASTEXITCODE -ne 0) { Get-Content $deviceLog; throw "ARM64 run failed" }
Get-Content $deviceLog
