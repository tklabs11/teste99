$ErrorActionPreference = "Stop"

$ndk = "$env:LOCALAPPDATA\Android\Sdk\ndk\29.0.14206865"
$clangxx = "$ndk\toolchains\llvm\prebuilt\windows-x86_64\bin\clang++.exe"
$sysroot = "$ndk\toolchains\llvm\prebuilt\windows-x86_64\sysroot"
$objectOutput = Join-Path $PSScriptRoot "lifting_harness_arm64.o"
$executableOutput = Join-Path $PSScriptRoot "lifting_harness_arm64"
$arrayKernelOutput = Join-Path $PSScriptRoot "lifted_array_kernel_arm64"
$lowerBoundOutput = Join-Path $PSScriptRoot "lifted_lower_bound_arm64"

if (-not (Test-Path $clangxx)) {
    throw "NDK clang++ not found: $clangxx"
}

Push-Location $PSScriptRoot
try {
    & $clangxx --target=aarch64-linux-android21 --sysroot=$sysroot `
        -std=c++17 -O2 -Wall -Wextra -Wpedantic `
        -c lifting_harness.cpp -o $objectOutput
    if ($LASTEXITCODE -ne 0) {
        throw "Android ARM64 harness build failed"
    }

    & $clangxx --target=aarch64-linux-android21 --sysroot=$sysroot `
        -std=c++17 -O2 -Wall -Wextra -Wpedantic `
        -static-libstdc++ -static-libgcc `
        -fPIE -pie lifting_harness.cpp -o $executableOutput
    if ($LASTEXITCODE -ne 0) {
        throw "Android ARM64 executable build failed"
    }

    & $clangxx --target=aarch64-linux-android21 --sysroot=$sysroot `
        -std=c++17 -O2 -Wall -Wextra -Wpedantic `
        -static-libstdc++ -static-libgcc `
        -fPIE -pie lifted_array_kernel.cpp -o $arrayKernelOutput
    if ($LASTEXITCODE -ne 0) {
        throw "Lifted array kernel build failed"
    }

    & $clangxx --target=aarch64-linux-android21 --sysroot=$sysroot `
        -std=c++17 -O2 -Wall -Wextra -Wpedantic `
        -static-libstdc++ -static-libgcc `
        -fPIE -pie lifted_lower_bound.cpp -o $lowerBoundOutput
    if ($LASTEXITCODE -ne 0) {
        throw "Lifted lower-bound build failed"
    }

    Write-Output "Built $objectOutput"
    Write-Output "Built $executableOutput"
    Write-Output "Built $arrayKernelOutput"
    Write-Output "Built $lowerBoundOutput"
} finally {
    Pop-Location
}
