@echo off
call "C:\Program Files (x86)\Microsoft Visual Studio\18\BuildTools\Common7\Tools\VsDevCmd.bat" -arch=x86 -host_arch=x64 >nul
cl /nologo /std:c++17 /EHsc /O2 /I tools\batch_static_lift /I test-logs\marco7-00921260\generated-00a23570-boundary-v2 tools\batch_static_lift\m7_00a23570_boundary_harness.cpp /Fe:test-logs\marco7-00921260\m7_cfg_boundary_x86.exe
