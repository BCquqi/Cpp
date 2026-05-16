@echo off
if "%1"=="" goto loop
copy test%1.in test.in>nul
echo Testing: Test.cpp
echo Case %1
echo Case %1 is tested by Coookie (coookie.dpdns.org)

test.exe

fc test%1.ans test.out
del test.in
del test.out
pause
goto end
:loop
for %%i in ( 1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end