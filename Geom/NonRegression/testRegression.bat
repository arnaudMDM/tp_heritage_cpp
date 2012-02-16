@echo off
set repertoire="C:\Users\pitou\workspace\Geom\"
::Chemin d'accès au répertoire Geom
set /A compteurEchecs="0"
set /A compteurGlobal="0"
if %repertoire%==[] goto end
cd %repertoire%
for /F %%a in ('dir /B "NonRegression/Test"') do (
	"Debug/geom.exe" <"NonRegression/Test/%%a" >"NonRegression/res/%%a"
)

cd NonRegression/res/
for /F %%a in ('dir /B "../Test"') do (
	::diff -I "^#.*" "%%a" "res%%a"
	FINDSTR /V "#" "%%a" >"#%%a"
	fc /C "#%%a" "res%%a" | findstr "aucune" >nul
	set /A compteurGlobal+=1
	if errorlevel 1 (
		echo Le test %%a a echoue
		set /A compteurEchecs+=1 
	) else (
		echo Le test %%a est passe) )

cd ../..

if compteurEchecs LEQ 1 (
@echo %compteurEchecs% test echoue sur %compteurGlobal%
) else (
@echo %compteurEchecs% tests echoues sur %compteurGlobal%
)

:end
pause
