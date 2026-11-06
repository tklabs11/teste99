param(
    [string]$PePath = "C:\SporeAnalysis\SporeApp.exe",
    [string]$BatchPath = "C:\SporeAnalysis\spore_batch_all_parts\spore_batch_all_0034.json",
    [string]$DeviceSerial = "",
    [switch]$BuildOnly
)

$ErrorActionPreference = "Stop"
$toolsDirectory = $PSScriptRoot
$backendDirectory = Join-Path $toolsDirectory "batch_static_lift"
$generator = Join-Path $backendDirectory "generate_call_closure.py"
$harness = Join-Path $backendDirectory "closure_execution_harness.cpp"
$python = (Get-Command python.exe -ErrorAction Stop).Source
$sdkRoot = if ($env:ANDROID_SDK_ROOT) {
    $env:ANDROID_SDK_ROOT
} elseif ($env:ANDROID_HOME) {
    $env:ANDROID_HOME
} else {
    Join-Path $env:LOCALAPPDATA "Android\Sdk"
}
$adb = Join-Path $sdkRoot "platform-tools\adb.exe"
$ndkRoot = if ($env:ANDROID_NDK_HOME) {
    $env:ANDROID_NDK_HOME
} else {
    Join-Path $sdkRoot "ndk\29.0.14206865"
}
$clang = Join-Path $ndkRoot "toolchains\llvm\prebuilt\windows-x86_64\bin\clang++.exe"
$runId = Get-Date -Format "yyyyMMdd-HHmmssfff"
$runDirectory = Join-Path (Join-Path $toolsDirectory "..\test-logs") `
    ("closure-00921f00-m5-" + $runId)
$generatedDirectory = Join-Path $runDirectory "generated"
$buildDirectory = Join-Path $env:TEMP `
    ("spore-00921f00-closure-" + [Guid]::NewGuid().ToString("N"))
$reportPath = Join-Path $generatedDirectory "report.json"
$byteHeader = Join-Path $generatedDirectory "closure_reference_bytes.hpp"
$x86Executable = Join-Path $buildDirectory "closure_execution_x86.exe"
$arm64Executable = Join-Path $buildDirectory "closure_execution_arm64"
$remoteExecutable = "/data/local/tmp/spore_00921f00_closure"
$deviceSelected = $false

foreach ($requiredPath in @(
    $PePath, $BatchPath, $generator, $harness, $adb, $clang
)) {
    if (-not (Test-Path -LiteralPath $requiredPath)) {
        throw "Required input or tool was not found: $requiredPath"
    }
}

$vswhere = Join-Path ${env:ProgramFiles(x86)} `
    "Microsoft Visual Studio\Installer\vswhere.exe"
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

New-Item -ItemType Directory -Path $runDirectory | Out-Null
New-Item -ItemType Directory -Path $generatedDirectory | Out-Null
New-Item -ItemType Directory -Path $buildDirectory | Out-Null

function Write-CommandOutput {
    param(
        [object[]]$Output,
        [string]$Path
    )

    $lines = foreach ($line in $Output) {
        if ($line -is [System.Management.Automation.ErrorRecord]) {
            $line.Exception.Message
        } else {
            [string]$line
        }
    }
    Set-Content -LiteralPath $Path -Value $lines -Encoding UTF8
    Write-Host "LOG_SAVED=$Path"
}

function Invoke-Harness {
    param(
        [string]$Executable,
        [string[]]$Arguments,
        [string]$LogPath,
        [string]$Description
    )

    $previousPreference = $ErrorActionPreference
    try {
        $ErrorActionPreference = "Continue"
        $output = & $Executable @Arguments 2>&1
        $exitCode = $LASTEXITCODE
    } finally {
        $ErrorActionPreference = $previousPreference
    }
    Write-CommandOutput -Output $output -Path $LogPath
    if ($exitCode -ne 0) {
        throw "$Description failed with exit code $exitCode"
    }
    $jsonLines = @($output | ForEach-Object { [string]$_ } |
        Where-Object { $_ -match '^\{"variant":' })
    if ($jsonLines.Count -ne 1) {
        throw "$Description did not produce exactly one snapshot record"
    }
    return ($jsonLines[0] | ConvertFrom-Json)
}

try {
    $generationOutput = & $python $generator `
        --exe $PePath --batch $BatchPath --entry 0x00921f00 `
        --output-dir $generatedDirectory --report $reportPath `
        --byte-header $byteHeader 2>&1
    if ($LASTEXITCODE -ne 0) {
        Write-CommandOutput -Output $generationOutput `
            -Path (Join-Path $runDirectory "generation.log")
        throw "Eight-function closure generation failed"
    }
    Write-CommandOutput -Output $generationOutput `
        -Path (Join-Path $runDirectory "generation.log")
    $report = Get-Content -LiteralPath $reportPath -Raw |
        ConvertFrom-Json
    $expectedSourceHash =
        "6aec99cb2dc7fd08851a1718e92a60f359fb3fccca3b244a890ae07e93cbe59b"
    if (($report.function_count -ne 8) -or
        ($report.source_sha256 -ne $expectedSourceHash)) {
        throw "Generated closure did not match the verified eight-function PE report"
    }

    $closureSources = @(
        $report.functions | ForEach-Object {
            Join-Path $generatedDirectory $_.generated_source
        }
    )
    foreach ($source in $closureSources) {
        if (-not (Test-Path -LiteralPath $source)) {
            throw "Generated closure source is missing: $source"
        }
    }

    $buildCommand = 'call "' + $vsDevCmd +
        '" -no_logo -arch=x86 -host_arch=x64 && pushd "' + $buildDirectory +
        '" && cl /nologo /std:c++17 /EHsc /O2 /Oy /W4 /I"' +
        $backendDirectory + '" /I"' + $generatedDirectory + '" /Fe:"' +
        $x86Executable + '" "' + $harness + '" "' +
        ($closureSources -join '" "') + '"'
    $buildOutput = & $env:ComSpec /d /s /c $buildCommand 2>&1
    if ($LASTEXITCODE -ne 0) {
        Write-CommandOutput -Output $buildOutput `
            -Path (Join-Path $runDirectory "build-x86.log")
        throw "Windows x86 original-vs-lift closure build failed"
    }
    Write-CommandOutput -Output $buildOutput `
        -Path (Join-Path $runDirectory "build-x86.log")

    $nativeSnapshot = Invoke-Harness `
        -Executable $x86Executable -Arguments @("--native") `
        -LogPath (Join-Path $runDirectory "native-x86.jsonl") `
        -Description "Original byte-verified x86 closure"
    $liftedX86Snapshot = Invoke-Harness `
        -Executable $x86Executable -Arguments @("--lift") `
        -LogPath (Join-Path $runDirectory "lift-x86.jsonl") `
        -Description "Generated closure on Windows x86"

    $comparisonFields = @(
        "status", "eip", "esp_delta", "eflags", "calls", "object",
        "stack_entry_frame"
    )
    $registerNames = @(
        "EAX", "ECX", "EDX", "EBX", "ESP", "EBP", "ESI", "EDI"
    )
    $comparedRegisterIndices = @(0, 3, 4, 5, 6, 7)
    foreach ($index in $comparedRegisterIndices) {
        $nativeRegister = ([string]$nativeSnapshot.registers).Split(',')[$index]
        $liftedRegister = ([string]$liftedX86Snapshot.registers).Split(',')[$index]
        if ($nativeRegister -cne $liftedRegister) {
            throw "Windows x86 differential mismatch in register " +
                "'$($registerNames[$index])': original=$nativeRegister " +
                "lifted=$liftedRegister"
        }
    }
    foreach ($field in $comparisonFields) {
        if ([string]$nativeSnapshot.$field -cne `
            [string]$liftedX86Snapshot.$field) {
            throw "Windows x86 differential mismatch in '$field': " +
                "original=$($nativeSnapshot.$field) " +
                "lifted=$($liftedX86Snapshot.$field)"
        }
    }
    if (-not $nativeSnapshot.calls) {
        throw "The original closure returned without an instrumented import call"
    }
    Write-Output (
        "PASS x86_differential root=0x00921f00 functions=8 " +
        "fields=$($comparisonFields -join ',') " +
        "registers=EAX,EBX,ESP,EBP,ESI,EDI")
    Write-Output (
        "VOLATILE_REGISTERS x86_original=" +
        "$($nativeSnapshot.registers) " +
        "x86_lift=$($liftedX86Snapshot.registers)")
    Write-Output "IMPORT_TRACE $($nativeSnapshot.calls)"

    $armBuildOutput = & $clang "--target=aarch64-linux-android29" `
        "-std=c++17" "-O2" "-pthread" "-Wall" "-Wextra" "-Werror" `
        "-static-libstdc++" "-static-libgcc" "-fPIE" "-pie" `
        "-I$backendDirectory" "-I$generatedDirectory" `
        $harness $closureSources "-o" $arm64Executable 2>&1
    if ($LASTEXITCODE -ne 0) {
        Write-CommandOutput -Output $armBuildOutput `
            -Path (Join-Path $runDirectory "build-arm64.log")
        throw "Android ARM64 closure harness build failed"
    }
    Write-CommandOutput -Output $armBuildOutput `
        -Path (Join-Path $runDirectory "build-arm64.log")
    Write-Output "PASS arm64_compile target=aarch64-linux-android29"
    if ($BuildOnly) {
        Write-Output "DEVICE_RUN_SKIPPED=BuildOnly"
        return
    }

    if ($DeviceSerial) {
        $deviceState = & $adb -s $DeviceSerial get-state 2>$null
        if ($LASTEXITCODE -ne 0 -or $deviceState -ne "device") {
            throw "Requested ADB device is not connected and authorized: $DeviceSerial"
        }
    } else {
        $devices = @(
            & $adb devices |
                Where-Object { $_ -match '^\S+\s+device$' } |
                ForEach-Object { ($_ -split '\s+')[0] }
        )
        if ($devices.Count -gt 1) {
            throw "Multiple ADB devices found; provide -DeviceSerial explicitly"
        }
        if ($devices.Count -eq 1) {
            $DeviceSerial = $devices[0]
        }
    }
    if (-not $DeviceSerial) {
        Write-Output "DEVICE_RUN_SKIPPED=no_connected_authorized_device"
        return
    }

    $deviceSelected = $true
    $previousPreference = $ErrorActionPreference
    try {
        $ErrorActionPreference = "Continue"
        $pushOutput = & $adb -s $DeviceSerial push $arm64Executable `
            $remoteExecutable 2>&1
        $pushExitCode = $LASTEXITCODE
    } finally {
        $ErrorActionPreference = $previousPreference
    }
    Write-CommandOutput -Output $pushOutput `
        -Path (Join-Path $runDirectory "device-push.log")
    if ($pushExitCode -ne 0) {
        throw "Could not push the ARM64 closure harness to $DeviceSerial"
    }
    $previousPreference = $ErrorActionPreference
    try {
        $ErrorActionPreference = "Continue"
        $chmodOutput = & $adb -s $DeviceSerial shell chmod 700 `
            $remoteExecutable 2>&1
        $chmodExitCode = $LASTEXITCODE
    } finally {
        $ErrorActionPreference = $previousPreference
    }
    Write-CommandOutput -Output $chmodOutput `
        -Path (Join-Path $runDirectory "device-chmod.log")
    if ($chmodExitCode -ne 0) {
        throw "Could not make the ARM64 closure harness executable"
    }
    $deviceSnapshot = Invoke-Harness `
        -Executable $adb `
        -Arguments @("-s", $DeviceSerial, "shell", $remoteExecutable, "--lift") `
        -LogPath (Join-Path $runDirectory "device-run.jsonl") `
        -Description "Lifted closure on Android ARM64"
    foreach ($index in $comparedRegisterIndices) {
        $liftedRegister = ([string]$liftedX86Snapshot.registers).Split(',')[$index]
        $deviceRegister = ([string]$deviceSnapshot.registers).Split(',')[$index]
        if ($liftedRegister -cne $deviceRegister) {
            throw "Android ARM64 differential mismatch in register " +
                "'$($registerNames[$index])': x86=$liftedRegister " +
                "arm64=$deviceRegister"
        }
    }
    foreach ($field in $comparisonFields) {
        if ([string]$liftedX86Snapshot.$field -cne `
            [string]$deviceSnapshot.$field) {
            throw "Android ARM64 differential mismatch in '$field': " +
                "x86=$($liftedX86Snapshot.$field) " +
                "arm64=$($deviceSnapshot.$field)"
        }
    }
    Write-Output (
        "PASS arm64_device_run serial=$DeviceSerial " +
        "root=0x00921f00 functions=8")

    $manifest = [ordered]@{
        schema = "spore-closure-execution-m5-v1"
        source_sha256 = $report.source_sha256
        root = "0x00921f00"
        function_count = $report.function_count
        imports_observed = $nativeSnapshot.calls
        comparisons = $comparisonFields
        compared_registers = @("EAX", "EBX", "ESP", "EBP", "ESI", "EDI")
        recorded_but_volatile_registers = @("ECX", "EDX")
        stack_comparison = (
            "root return address and two caller argument slots at " +
            "[entry ESP, entry ESP+4, entry ESP+8]; native Win32 API " +
            "private stack scratch is excluded")
        object_normalization = (
            "guest addresses and handles normalized; x86 CRITICAL_SECTION " +
            "DebugInfo pointer and implementation-specific SpinCount excluded")
        x86_original_vs_lift = "passed"
        x86_lift_vs_android_arm64 = "passed"
        android_serial = $DeviceSerial
        test_state = (
            "isolated zeroed 0x400-byte object with boundary canary and " +
            "separate 16 KiB stack with bottom canary; ECX=object+0x28, " +
            "ESI=object, stack args=[EBX=0,EDI=1]")
        limitation = (
            "Harness state is a controlled closure test, not captured " +
            "from full game initialization.")
    }
    $manifest | ConvertTo-Json -Depth 6 |
        Set-Content -LiteralPath (Join-Path $runDirectory "manifest.json") `
            -Encoding UTF8
    Write-Output "EVIDENCE_DIRECTORY=$runDirectory"
} finally {
    if ($deviceSelected) {
        $previousPreference = $ErrorActionPreference
        try {
            $ErrorActionPreference = "Continue"
            $cleanupOutput = & $adb -s $DeviceSerial shell rm -f `
                $remoteExecutable 2>&1
            $cleanupExitCode = $LASTEXITCODE
        } finally {
            $ErrorActionPreference = $previousPreference
        }
        if ($cleanupExitCode -ne 0) {
            Write-Warning "Could not remove the temporary Android harness: $cleanupOutput"
        }
    }
    if (Test-Path -LiteralPath $buildDirectory) {
        Remove-Item -LiteralPath $buildDirectory -Recurse -Force
    }
}
