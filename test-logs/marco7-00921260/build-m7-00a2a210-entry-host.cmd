@echo off
call "C:\Program Files (x86)\Microsoft Visual Studio\18\BuildTools\Common7\Tools\VsDevCmd.bat" -arch=x64 -host_arch=x64 >nul
cl /nologo /std:c++17 /EHsc /O2 /I tools\batch_static_lift tools\batch_static_lift\m7_00a2a210_entry_harness.cpp test-logs\marco7-00921260\generated-00a2a210-entry-boundary\spore_00a2a210_prefix.cpp /Fe:test-logs\marco7-00921260\m7_00a2a210_entry_host.exe
