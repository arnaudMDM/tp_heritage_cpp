@echo off
set repertoire="C:\Users\Pitou\workspace\Geom\"
::Chemin d'accès au répertoire Geom
set /A compteurs="0"

if %repertoire%==[] goto end
cd %repertoire%
for /F %%a in ('dir /B "NonRegression/Test"') do (
	"Debug/geom.exe" <"NonRegression/Test/%%a" >"NonRegression/res/%%a"
)

cd NonRegression/res/
for /F %%a in ('dir /B "../Test"') do (
	
	fc /C "%%a" "res%%a" | findstr "aucune" 
	if errorlevel 1 (
		echo Le test %%a a echoue
		set /A compteurs+=1 
	) else (
		echo Le test %%a est passe) )

cd ../..

@echo %compteurs% test(s) echoue(s)

:end
pause
