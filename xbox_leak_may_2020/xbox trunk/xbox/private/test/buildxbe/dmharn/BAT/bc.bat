@echo off
REM Builds and copies everything (private harness, media) to XBox and runs it.
call %_NTDRIVE%%_NTROOT%\private\test\buildxbe\dmharn\bat\b %1
call copymedia
:END
