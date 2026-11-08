@echo off
call "C:\Program Files (x86)\Microsoft Visual Studio\18\BuildTools\Common7\Tools\VsDevCmd.bat" -arch=x86 -host_arch=x64 >nul
if not exist test-logs\boot-entry-20261108\entry-tail-obj mkdir test-logs\boot-entry-20261108\entry-tail-obj
cl /nologo /std:c++17 /EHsc /O2 /W4 /I tools\batch_static_lift /Fo:test-logs\boot-entry-20261108\entry-tail-obj\ /Fe:test-logs\boot-entry-20261108\entry_tail_lift_x86.exe tools\batch_static_lift\boot_entry_tail_harness.cpp test-logs\boot-entry-20261108\generated-entry-tail\spore_011e11a0.cpp
