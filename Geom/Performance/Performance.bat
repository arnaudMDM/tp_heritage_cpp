@echo off
set repertoire="C:\Users\arnaud\workspace_Cpp\Geom\"
if %repertoire%==[] goto end
cd %repertoire%
set /A clock=date +%s
"Debug/geom.exe" <"Performance/fichiers/Creation.txt" >nul
set /A time=date + %s
::set /A time-=clock
@echo %clock%
	@echo %time%
:end
pause