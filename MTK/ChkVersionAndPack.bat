@echo off
setLocal EnableDelayedExpansion
for /f  "tokens=1,2 delims=="  %%i in (version.txt) do (
	echo "%%i" | findstr VERNO >nul && set num=yes|| set num=no
	::echo "!num!"
	set version=%%j
	if "!num!" == "yes" goto exit1
)
:exit1
set "version=%version: =%"
set "version=%version:;=%"
set "version=%version:"=%"
echo %version%

for /f  "tokens=1,2 delims=="  %%i in (version.txt) do (
	echo "%%i" | findstr DATETIME >nul && set num=yes|| set num=no
	::echo "!num!"
	set buildtime=%%j
	if "!num!" == "yes" goto exit2
)
:exit2
set "buildtime=%buildtime: =%"
set "buildtime=%buildtime:;=%"
set "buildtime=%buildtime:"=%"
echo %buildtime%

if "%1" == "tar" goto tar
goto exit3
:tar
"C:\Program Files (x86)\WinRAR\Rar.exe" a -r -s -m3 test_%version%_%buildtime%.zip .\test\1.txt .\test\2.txt .\test\3
:exit3

endlocal