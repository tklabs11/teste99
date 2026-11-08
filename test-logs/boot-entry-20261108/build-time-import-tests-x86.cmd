@echo off
call "C:\Program Files (x86)\Microsoft Visual Studio\18\BuildTools\Common7\Tools\VsDevCmd.bat" -arch=x86 -host_arch=x64 >nul
if not exist test-logs\boot-entry-20261108\time-import-tests-obj mkdir test-logs\boot-entry-20261108\time-import-tests-obj
cl /nologo /std:c++17 /EHsc /O2 /W4 /I tools\batch_static_lift /Fo:test-logs\boot-entry-20261108\time-import-tests-obj\ /Fe:test-logs\boot-entry-20261108\time_import_tests_x86.exe tools\batch_static_lift\boot_time_import_tests.cpp
