param(
    [string]$DeviceSerial = "PJMZAEJRX4YLFIDI",
    [switch]$BuildOnly
)

$ErrorActionPreference = "Stop"
$root = (Resolve-Path (Join-Path $PSScriptRoot "..\..")).Path
$old = Join-Path $root "test-logs\constructor-prefix-00a33600-20261106-173351200\generated"
$generated = Join-Path $PSScriptRoot "generated-constructor-child-return-v14"
$indexed = Join-Path $PSScriptRoot "generated-00a2a210-entry-composite-v2\indexed_memory_store_test.cpp"
$clang = "C:\Users\wesll\AppData\Local\Android\Sdk\ndk\29.0.14206865\toolchains\llvm\prebuilt\windows-x86_64\bin\clang++.exe"
$adb = "C:\platform-tools\adb.exe"
$binary = Join-Path $PSScriptRoot "m7_constructor_child_return_arm64"
$buildLog = Join-Path $PSScriptRoot "m7-child-return-arm64-build.log"
$deviceLog = Join-Path $PSScriptRoot "m7-child-return-android.log"
$sources = @(
    (Join-Path $root "tools\batch_static_lift\constructor_prefix_harness.cpp"),
    (Join-Path $generated "spore_00a33600_prefix.cpp"),
    (Join-Path $generated "spore_00a2a210_prefix.cpp"),
    (Join-Path $generated "spore_00921260.cpp"),
    (Join-Path $generated "spore_00921340.cpp"),
    (Join-Path $generated "spore_009212c0.cpp"),
    (Join-Path $generated "spore_00a23570.cpp"),
    (Join-Path $generated "spore_00921300.cpp"),
    (Join-Path $generated "spore_00921360.cpp"),
    (Join-Path $generated "spore_009213c0.cpp"),
    (Join-Path $generated "spore_00a221b0.cpp"),
    $indexed
) + @(Get-ChildItem -LiteralPath (Join-Path $old "closure") -Filter "spore_*.cpp" |
    ForEach-Object FullName)
$compileArgs = @("--target=aarch64-linux-android29", "-std=c++17", "-O2",
    "-DM7_COMPOSITE_ENTRY", "-DM7_THROUGH_FIRST_CALL",
    "-DM7_THROUGH_SECOND_CALL", "-DM7_THROUGH_THIRD_CALL",
    "-DM7_THROUGH_MEMSET", "-DM7_THROUGH_FLOAT_CALL",
    "-DM7_THROUGH_CHILD_RETURN", "-I", (Join-Path $root "tools\batch_static_lift"),
    "-I", $old, "-I", (Join-Path $old "closure"), "-I", $generated,
    "-o", $binary) + $sources

& $clang @compileArgs *> $buildLog
if ($LASTEXITCODE -ne 0) { Get-Content $buildLog; throw "ARM64 build failed" }
"PASS clang ARM64 source_count=$($sources.Count)" | Add-Content $buildLog
if ($BuildOnly) { Get-Content $buildLog -Tail 1; return }

& $adb -s $DeviceSerial push $binary /data/local/tmp/m7_constructor_child_return_arm64
if ($LASTEXITCODE -ne 0) { throw "ADB push failed" }
& $adb -s $DeviceSerial shell chmod 700 /data/local/tmp/m7_constructor_child_return_arm64
if ($LASTEXITCODE -ne 0) { throw "ADB chmod failed" }
& $adb -s $DeviceSerial shell /data/local/tmp/m7_constructor_child_return_arm64 *> $deviceLog
if ($LASTEXITCODE -ne 0) { Get-Content $deviceLog -Tail 5; throw "ARM64 run failed" }
Get-Content $deviceLog | Select-String '^PASS'
