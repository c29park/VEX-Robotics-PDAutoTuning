
cd .

if "%1"=="" ("C:\Users\chong\OneDrive\Desktop\ALLVEX~1\bin\win64\gmake"  -f tune.mk all) else ("C:\Users\chong\OneDrive\Desktop\ALLVEX~1\bin\win64\gmake"  -f tune.mk %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
exit /B 1