param(
    [string]$ReferencePe = "C:\SporeAnalysis\SporeApp.exe",
    [string]$CandidatePe = "C:\Program Files (x86)\Steam\steamapps\common\Spore\SPOREFILES\SporeBin\SporeApp.exe",
    [string]$BatchDirectory = "C:\SporeAnalysis\spore_batch_all_parts"
)

$ErrorActionPreference = "Stop"
$toolsDirectory = $PSScriptRoot
$repoRoot = Split-Path $toolsDirectory -Parent
$backendDirectory = Join-Path $toolsDirectory "batch_static_lift"
$logsDirectory = Join-Path $repoRoot "test-logs\boot-entry-20261108"
$generator = Join-Path $backendDirectory "generate_initterm_closure.py"
$outputDirectory = Join-Path $logsDirectory "generated-initterm-closure"
$batch = Join-Path $BatchDirectory "spore_batch_all_0086.json"
$python = (Get-Command python.exe -ErrorAction Stop).Source

$vswhere = Join-Path ${env:ProgramFiles(x86)} "Microsoft Visual Studio\Installer\vswhere.exe"
$vsInstall = & $vswhere -latest -products "*" -property installationPath
if ($LASTEXITCODE -ne 0 -or -not $vsInstall) {
    throw "Could not locate Visual Studio Build Tools"
}
$vsDevCmd = Join-Path $vsInstall "Common7\Tools\VsDevCmd.bat"

$sdkRoot = if ($env:ANDROID_SDK_ROOT) { $env:ANDROID_SDK_ROOT }
    elseif ($env:ANDROID_HOME) { $env:ANDROID_HOME }
    else { Join-Path $env:LOCALAPPDATA "Android\Sdk" }
$ndkRoot = if ($env:ANDROID_NDK_HOME) { $env:ANDROID_NDK_HOME }
    else { Join-Path $sdkRoot "ndk\29.0.14206865" }
$clang = Join-Path $ndkRoot "toolchains\llvm\prebuilt\windows-x86_64\bin\clang++.exe"

foreach ($requiredPath in @(
    $ReferencePe, $CandidatePe, $batch, $generator, $vsDevCmd, $clang,
    (Join-Path $logsDirectory "crt_init_routines.json"),
    (Join-Path $logsDirectory "crt_dep_routines.json"),
    (Join-Path $logsDirectory "crt_dep_routines2.json"),
    (Join-Path $logsDirectory "crt_dep_functions.json")
)) {
    if (-not (Test-Path -LiteralPath $requiredPath)) {
        throw "Required input or tool was not found: $requiredPath"
    }
}

if (Test-Path -LiteralPath $outputDirectory) {
    Remove-Item -LiteralPath $outputDirectory -Recurse -Force
}
$generated = & $python $generator --reference $ReferencePe `
    --candidate $CandidatePe --batch $batch `
    --extra-batch (Join-Path $logsDirectory "crt_init_routines.json") `
    --extra-batch (Join-Path $logsDirectory "crt_dep_routines.json") `
    --extra-batch (Join-Path $logsDirectory "crt_dep_routines2.json") `
    --extra-batch (Join-Path $logsDirectory "crt_dep_functions.json") `
    --output $outputDirectory 2>&1
$generated | Tee-Object -FilePath (Join-Path $logsDirectory "initterm-closure-generation.log")
if ($LASTEXITCODE -ne 0) { throw "Closure generation failed" }

$manifest = Get-Content -LiteralPath (Join-Path $outputDirectory "manifest.json") -Raw |
    ConvertFrom-Json
$sources = @($manifest.functions | ForEach-Object { Join-Path $outputDirectory $_.source })

$buildDirectory = Join-Path $env:TEMP ("spore-initterm-closure-" + [Guid]::NewGuid().ToString("N"))
New-Item -ItemType Directory -Path $buildDirectory -Force | Out-Null
try {
    $x86Objects = Join-Path $buildDirectory "x86"
    $arm64Objects = Join-Path $buildDirectory "arm64"
    New-Item -ItemType Directory -Path $x86Objects | Out-Null
    New-Item -ItemType Directory -Path $arm64Objects | Out-Null

    $quoted = ($sources | ForEach-Object { '"' + $_ + '"' }) -join ' '
    $x86Command = 'call "' + $vsDevCmd +
        '" -arch=x86 -host_arch=x64 -no_logo && cl /nologo /c /std:c++17 /EHsc /O2 /W4 ' +
        '/I"' + $backendDirectory + '" /I"' + $outputDirectory + '" /Fo"' +
        $x86Objects + '\\" ' + $quoted
    $x86Build = & $env:ComSpec /d /s /c $x86Command 2>&1
    $x86Build | Set-Content -LiteralPath (Join-Path $logsDirectory "initterm-closure-x86-build.log")
    if ($LASTEXITCODE -ne 0) {
        $x86Build | ForEach-Object { Write-Output $_ }
        throw "Windows x86 closure build failed"
    }

    # clang -c with several inputs needs per-file invocations.
    $arm64Build = @()
    foreach ($source in $sources) {
        $object = Join-Path $arm64Objects ((Split-Path $source -Leaf) + ".o")
        $arm64Build += & $clang --target=aarch64-linux-android29 -std=c++17 -O2 `
            -Wall -Wextra -Werror -Wno-unused-label -c `
            "-I$backendDirectory" "-I$outputDirectory" $source -o $object 2>&1
        if ($LASTEXITCODE -ne 0) {
            $arm64Build | Set-Content -LiteralPath (Join-Path $logsDirectory "initterm-closure-arm64-build.log")
            $arm64Build | ForEach-Object { Write-Output $_ }
            throw "Android ARM64 closure build failed for $source"
        }
    }
    $arm64Build | Set-Content -LiteralPath (Join-Path $logsDirectory "initterm-closure-arm64-build.log")

    $x86Count = @(Get-ChildItem -LiteralPath $x86Objects -Filter *.obj).Count
    $arm64Count = @(Get-ChildItem -LiteralPath $arm64Objects -Filter *.o).Count
    if ($x86Count -ne $sources.Count -or $arm64Count -ne $sources.Count) {
        throw "Object count mismatch: x86=$x86Count arm64=$arm64Count sources=$($sources.Count)"
    }
    Write-Output ("PASS closure_build routines=" + $sources.Count +
        " instructions=" + $manifest.instruction_total +
        " imports=" + @($manifest.imports).Count +
        " x86_objects=" + $x86Count + " arm64_objects=" + $arm64Count)
} finally {
    if (Test-Path -LiteralPath $buildDirectory) {
        Remove-Item -LiteralPath $buildDirectory -Recurse -Force -ErrorAction SilentlyContinue
    }
}
