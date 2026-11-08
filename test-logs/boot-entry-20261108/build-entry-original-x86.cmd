@echo off
call "C:\Program Files (x86)\Microsoft Visual Studio\18\BuildTools\Common7\Tools\VsDevCmd.bat" -arch=x86 -host_arch=x64 >nul
if not exist test-logs\boot-entry-20261108\entry-original-obj mkdir test-logs\boot-entry-20261108\entry-original-obj
cl /nologo /std:c++17 /EHsc /O2 /W4 /I tools\batch_static_lift /I test-logs\boot-entry-20261108\generated-entry-tail /Fo:test-logs\boot-entry-20261108\entry-original-obj\ /Fe:test-logs\boot-entry-20261108\entry_original_verified_x86.exe tools\batch_static_lift\boot_entry_original_x86.cpp
