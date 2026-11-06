@echo off
call "C:\Program Files (x86)\Microsoft Visual Studio\18\BuildTools\Common7\Tools\VsDevCmd.bat" -arch=x86 -host_arch=x64 >nul
if not exist test-logs\marco7-00921260\m7-first-call-obj mkdir test-logs\marco7-00921260\m7-first-call-obj
cl /nologo /std:c++17 /EHsc /O2 /W4 /DM7_COMPOSITE_ENTRY /DM7_THROUGH_FIRST_CALL /I tools\batch_static_lift /I test-logs\constructor-prefix-00a33600-20261106-173351200\generated /I test-logs\constructor-prefix-00a33600-20261106-173351200\generated\closure /I test-logs\marco7-00921260\generated-constructor-first-call-v5 /Fo:test-logs\marco7-00921260\m7-first-call-obj\ /Fe:test-logs\marco7-00921260\m7_constructor_first_call_x86.exe tools\batch_static_lift\constructor_prefix_harness.cpp test-logs\marco7-00921260\generated-constructor-first-call-v5\spore_00a33600_prefix.cpp test-logs\marco7-00921260\generated-constructor-first-call-v5\spore_00a2a210_prefix.cpp test-logs\marco7-00921260\generated-constructor-first-call-v5\spore_00921260.cpp test-logs\marco7-00921260\generated-00a2a210-entry-composite-v2\indexed_memory_store_test.cpp test-logs\constructor-prefix-00a33600-20261106-173351200\generated\closure\spore_*.cpp


