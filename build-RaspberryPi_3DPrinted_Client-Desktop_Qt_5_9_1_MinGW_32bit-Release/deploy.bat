@echo off

copy .\release\RaspberryPi_3DPrinted_Client.exe .\release-package\RaspberryPi_3DPrinted_Client\RaspberryPi_3DPrinted_Client.exe

if "%errorlevel%"=="0" (
exit /B
) else (
echo Not deployed !
timeout 10
)