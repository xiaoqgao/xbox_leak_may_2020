@if NOT DEFINED _echo echo off

REM *****************************
REM *** DO NOT EDIT THIS FILE ***
REM *****************************

REM *************************************************************************
REM *
REM * InitRazzle.cmd
REM *
REM * Initializes a directory creating a Razzle environment
REM *
REM * Usage:
REM *   InitRazzle drive build [NTROOT directory] [TOOLSROOT directory]
REM *
REM * Examples:
REM *   InitRazzle D: 1941
REM *   InitRazzle D: 1941 TOOLSROOT d:\nt
REM *   InitRazzle D: 1941 NTROOT nt.sp4 TOOLSROOT d:\nt.sp4
REM *
REM *************************************************************************

if "%1" == "-?" goto USAGE
if "%1" == "" goto USAGE
if "%2" == "" goto USAGE

setlocal

set _ntroot_=nt

set _drive_=%1& shift
set _build_=%1& shift
if /i "%1" == "NTROOT" set _ntroot_=%2& shift& shift
if /i "%1" == "TOOLSROOT" set SUCKNT_ToolsRoot=%2& shift& shift

xcopy /f \\orville\razzle\src\private\developr\* %_drive_%\%_ntroot_%\private\developr\
xcopy /f \\orville\razzle\src\private\developr\Template %_drive_%\%_ntroot_%\private\developr\%USERNAME%\
cd /d %_drive_%\%_ntroot_%\private\developr\%USERNAME%
copy CueP-sample.pri CueP.pri
copy SetEnvP-sample.cmd SetEnvP.cmd
copy SetChkP-sample.cmd SetChkP.cmd
copy SetFreP-sample.cmd SetFreP.cmd
copy Tools-sample.ini Tools.ini
set _NTDrive=%_drive_%
set _NTBinDir=%_drive_%\%_ntroot_%
sucknt pubtools tools %_build_%

endlocal

goto DONE

:USAGE

echo.
echo InitRazzle {drive} {build#} [NTROOT directory] [TOOLSROOT directory]
echo.

:DONE
