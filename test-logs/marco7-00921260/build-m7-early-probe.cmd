@echo off
call "C:\Program Files (x86)\Microsoft Visual Studio\18\BuildTools\Common7\Tools\VsDevCmd.bat" -arch=x86 -host_arch=x64 >nul
cl /nologo /std:c++17 /EHsc /O2 tools\batch_static_lift\m7_early_base_probe.cpp /Fe:test-logs\marco7-00921260\m7_early_base_probe.exe /link /BASE:0x10000000 /DYNAMICBASE:NO /ENTRY:early_entry
