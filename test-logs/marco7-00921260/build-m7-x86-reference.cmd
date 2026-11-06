@echo off
call "C:\Program Files (x86)\Microsoft Visual Studio\18\BuildTools\Common7\Tools\VsDevCmd.bat" -arch=x86 -host_arch=x64 >nul
cl /nologo /std:c++17 /EHsc /O2 /I test-logs\marco7-00921260\generated-00921260 tools\batch_static_lift\m7_00921260_x86_reference.cpp /Fe:test-logs\marco7-00921260\m7_00921260_x86_reference.exe
