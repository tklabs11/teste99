param(
    [string]$PePath = "C:\Users\wesll\Downloads\SPORE-SteamRIP.com\SPORE\SporeBin\SporeApp.exe"
)

$ErrorActionPreference = "Stop"

$expectedSha256 = "fb66afc320730dec6f80b79301c7c525689859e3d0a99616b657559e8f11a1ae"
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

$buildDirectory = Join-Path $env:TEMP ("spore-graphics-x86-reference-" + [Guid]::NewGuid().ToString("N"))
New-Item -ItemType Directory -Path $buildDirectory | Out-Null
$executable = Join-Path $buildDirectory "graphics_parameter_x86_reference.exe"

try {
    $buildCommand = 'call "' + $vsDevCmd +
        '" -no_logo -arch=x86 -host_arch=x64 && pushd "' + $buildDirectory +
        '" && cl /nologo /std:c++17 /EHsc /O2 /W4 /Fe:"' + $executable +
        '" "' + (Join-Path $PSScriptRoot "test_graphics_parameter_x86_reference.cpp") + '"'
    & $env:ComSpec /d /s /c $buildCommand
    if ($LASTEXITCODE -ne 0) {
        throw "x86 graphics reference harness build failed"
    }

    Write-Output "reference_pe_sha256=$actualSha256"
    & $executable $PePath
    if ($LASTEXITCODE -ne 0) {
        throw "x86 graphics parameter comparison failed"
    }
} finally {
    Remove-Item -LiteralPath $buildDirectory -Recurse -Force
}
