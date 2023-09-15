@echo off
setlocal enabledelayedexpansion

set "textfile=%~f1"

setlocal enableextensions disabledelayedexpansion
for /f "delims=" %%i in ('type "%textFile%" ^& break ^> "%textFile%" ') do (
    set "line=%%i"
    setlocal enabledelayedexpansion
    set newline=!line:OOP_NEWLINE=^

!   
    set newline=!newline:OOP_TAB=   !
    >>"%textFile%" echo(!newline!
    endlocal
)