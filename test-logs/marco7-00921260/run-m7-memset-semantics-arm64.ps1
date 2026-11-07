param(
    [string]$DeviceSerial = "PJMZAEJRX4YLFIDI",
    [switch]$BuildOnly
)

$ErrorActionPreference = "Stop"
$root = (Resolve-Path (Join-Path $PSScriptRoot "..\..")).Path
$clang = "C:\Users\wesll\AppData\Local\Android\Sdk\ndk\29.0.14206865\toolchains\llvm\prebuilt\windows-x86_64\bin\clang++.exe"
$adb = "C:\platform-tools\adb.exe"
$binary = Join-Path $PSScriptRoot "m7_memset_semantics_arm64"
$source = Join-Path $root "tools\batch_static_lift\m7_memset_import_semantics.cpp"
$include = Join-Path $root "tools\batch_static_lift"
$buildLog = Join-Path $PSScriptRoot "m7-memset-semantics-arm64-build.log"
$deviceLog = Join-Path $PSScriptRoot "m7-memset-semantics-android.log"

& $clang --target=aarch64-linux-android29 -std=c++17 -O2 -I $include -o $binary $source *> $buildLog
if ($LASTEXITCODE -ne 0) { Get-Content $buildLog; throw "ARM64 build failed" }
"PASS clang ARM64 memset semantics" | Add-Content $buildLog
if ($BuildOnly) { Get-Content $buildLog -Tail 1; return }

& $adb -s $DeviceSerial push $binary /data/local/tmp/m7_memset_semantics_arm64
if ($LASTEXITCODE -ne 0) { throw "ADB push failed" }
& $adb -s $DeviceSerial shell chmod 700 /data/local/tmp/m7_memset_semantics_arm64
if ($LASTEXITCODE -ne 0) { throw "ADB chmod failed" }
& $adb -s $DeviceSerial shell /data/local/tmp/m7_memset_semantics_arm64 *> $deviceLog
if ($LASTEXITCODE -ne 0) { Get-Content $deviceLog; throw "ARM64 run failed" }
Get-Content $deviceLog
