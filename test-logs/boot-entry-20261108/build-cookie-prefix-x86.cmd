@echo off
call "C:\Program Files (x86)\Microsoft Visual Studio\18\BuildTools\Common7\Tools\VsDevCmd.bat" -arch=x86 -host_arch=x64 >nul
if not exist test-logs\boot-entry-20261108\cookie-prefix-obj mkdir test-logs\boot-entry-20261108\cookie-prefix-obj
cl /nologo /std:c++17 /EHsc /O2 /W4 /I tools\batch_static_lift /I test-logs\boot-entry-20261108\generated-cookie-prefix /Fo:test-logs\boot-entry-20261108\cookie-prefix-obj\ /Fe:test-logs\boot-entry-20261108\cookie_prefix_lift_x86.exe tools\batch_static_lift\boot_cookie_prefix_harness.cpp test-logs\boot-entry-20261108\generated-cookie-prefix\spore_011e1548_prefix.cpp
