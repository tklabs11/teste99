@echo off
call "C:\Program Files (x86)\Microsoft Visual Studio\18\BuildTools\Common7\Tools\VsDevCmd.bat" -arch=x86 -host_arch=x64 >nul
cl /nologo /std:c++17 /EHsc /O2 /W4 /Fe:test-logs\marco7-00921260\m7_rtl_decompress_x86.exe tools\batch_static_lift\m7_rtl_decompress_fixture.cpp
