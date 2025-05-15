@echo off
REM Check if any arguments are provided
if "%~1"=="" (
    echo Usage: %~nx0 symbol1 symbol2 symbol3 ...
    echo Example: %~nx0 ?FuncName@@YAHH@Z ?AnotherFunc@@YAXH@Z
    goto :eof
)

REM Loop through each argument (symbol) and undecorate it
:loop
if "%~1"=="" goto :eof
undname.exe %~1 | findstr /v "Microsoft (R) C++ Name Undecorator"
shift
goto loop