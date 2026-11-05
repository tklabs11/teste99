param(
    [string]$PePath = "C:\SporeAnalysis\SporeApp.exe"
)

$ErrorActionPreference = "Stop"

$expectedSha256 = "6aec99cb2dc7fd08851a1718e92a60f359fb3fccca3b244a890ae07e93cbe59b"
if (-not (Test-Path -LiteralPath $PePath)) {
    throw "Reference PE not found: $PePath"
}
$actualSha256 = (Get-FileHash -LiteralPath $PePath -Algorithm SHA256).Hash.ToLowerInvariant()
if ($actualSha256 -ne $expectedSha256) {
    throw "Unexpected reference PE SHA-256: $actualSha256"
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

$buildDirectory = Join-Path $env:TEMP ("spore-x86-sort-" + [Guid]::NewGuid().ToString("N"))
New-Item -ItemType Directory -Path $buildDirectory | Out-Null
$executable = Join-Path $buildDirectory "x86_sort_differential.exe"
$source = Join-Path $PSScriptRoot "x86_sort_differential\main.cpp"
$includeDirectory = Join-Path $PSScriptRoot "..\app\src\main\cpp"

try {
    $buildCommand = 'call "' + $vsDevCmd +
        '" -no_logo -arch=x86 -host_arch=x64 && pushd "' + $buildDirectory +
        '" && cl /nologo /std:c++17 /EHsc /O2 /W4 /I"' + $includeDirectory +
        '" /Fe:"' + $executable + '" "' + $source +
        '" /link /BASE:0x10000000 /DYNAMICBASE:NO'
    & $env:ComSpec /d /s /c $buildCommand
    if ($LASTEXITCODE -ne 0) {
        throw "Windows x86 sort differential harness build failed"
    }

    & $executable $PePath
    if ($LASTEXITCODE -ne 0) {
        throw "Windows x86 sort differential comparison failed"
    }
    Write-Output "reference_pe_sha256=$actualSha256"
} finally {
    Remove-Item -LiteralPath $buildDirectory -Recurse -Force
}
