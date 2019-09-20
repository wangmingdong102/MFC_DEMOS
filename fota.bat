@echo off
setlocal enabledelayedexpansion
del version.bld.change

for /f  "tokens=1,2 delims=="  %%i in (version.bld) do (
	echo "%%i" | findstr version >nul && set num=yes|| set num=no
	::echo "!num!"
	set version=%%j
	if "!num!" == "yes" goto exit1
)
:exit1
set "version=%version: =%"
set "version=%version:;=%"
set "version=%version:"=%"
set "version=%version:V=%"
set "version=%version:.0=%"
set oldversion=%version%
echo %oldversion%
set /a version+=1
echo %version%


for /f "delims=" %%a in ('type version.bld') do (
    set "str=%%a"
	set "str=!str:V%oldversion%=V%version%!"

    echo !str! >> version.bld.change
)
::move version.bld.change version.bld