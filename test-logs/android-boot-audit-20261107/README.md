# Android boot audit — 2026-11-07

Device `PJMZAEJRX4YLFIDI` was connected through `C:\platform-tools\adb.exe`.
This is an APK UI audit, separate from the Marco 7 x86/ARM64 differential
prefix tests. No game boot, menu, or game rendering was observed.

## What ran

- The pre-existing installed package `dev.sporeport.cellstage` opened a
  `PC Compatibility Launcher` screen. The package manager reported its last
  update as `2026-11-02 00:09:27`; see [screenshot](screen.png) and
  [UI hierarchy](ui.xml).
- The local `app/build/outputs/apk/debug/app-debug.apk` had SHA-256
  `1AE66A482CC11B3D17540979D02E64841E5C95DA84D820A9F12FD7736C4F44B2`.
  `adb install -r` succeeded. Its Gradle debug application ID is
  `dev.sporeport.cellstage.dev`, so this installation was **side by side**
  with the older package and did not replace it.
- Launching the debug component
  `dev.sporeport.cellstage.dev/dev.sporeport.cellstage.MainActivity` opened
  the `Spore ARM64` validation screen. It displayed a verified imported EXE
  and the Marco 1 / Marco 7 test buttons; see [screenshot](screen-debug.png)
  and [UI hierarchy](ui-debug.xml).
- Tapping the Marco 7 fixture button produced
  `MARCO7_FIXTURE_PASS boundary=0x00a221fc` for functions `00a23570`,
  `00921260`, `00921300`, `00921360`, `00a221b0`; see
  [device logcat](fixture-logcat.txt) and [result screenshot](fixture-result.png).
  The log explicitly identifies `fixture=isolated_not_game_boot`.

## Why there is no Spore menu yet

The APK's JNI library builds the older five-function fixture from
`generated-00a23570-through-00a221b0` in `app/src/main/cpp/CMakeLists.txt`.
`MainActivity` calls it only through `nativeMarco7Fixture()`. The newer
constructor prefix through `0x00a30e9d` is exercised by a standalone ARM64
test binary, not by this APK. `nativeSporeLookup()` is a separate Marco 1
lookup test. The SDL and D3D9 activities are graphics probes. The current
APK has no path that starts the verified PE entry point, runs the translated
startup and constructor chain to completion, or hands control to a Spore
menu/render loop. The compatibility runtime methods are not attached to a
visible launch button in the current `MainActivity` UI.

The next boot-focused task is to connect a verified startup chain to the APK
and advance it through the unresolved constructor calls and required imports,
then tie its real graphics calls to the Android display. A fixture screen is
not evidence of reaching those boundaries.

## Reproduction

```powershell
& 'C:\platform-tools\adb.exe' devices -l
& 'C:\platform-tools\adb.exe' install -r app/build/outputs/apk/debug/app-debug.apk
& 'C:\platform-tools\adb.exe' shell am start -n dev.sporeport.cellstage.dev/dev.sporeport.cellstage.MainActivity
& 'C:\platform-tools\adb.exe' logcat -d -s SporeMarco7:I AndroidRuntime:E
```

The fixture button was tapped manually through ADB input at screen coordinate
`(1200, 940)` after inspecting its UI bounds. No files or app data were
removed. The existing debug APK was installed without rebuilding it in this
audit. No Python regression suite was rerun because no backend or app source
code was changed.
