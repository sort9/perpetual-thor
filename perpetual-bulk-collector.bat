@echo off
:loop
main.exe REM Set to location of exe
timeout /t 60 /nobreak >nul REM 60 is numerical time delay (in seconds) in between runs of this script
goto loop
