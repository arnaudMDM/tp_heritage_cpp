
:: batch permettant d'automatiser les tests de non regression du prg Geom
set redirectionSortie="redirectionSortieAffichage.txt"
:: Cette variable va contenir tout le texte obtenu lors de l'éxécution du prg

set redirectionEntree="cmdsATester.txt"
:: le fichier contenant les différentes commandes à faire executer par le prg

set fichierAComparer="testRegression.txt"
:: le fichier contenant l'affichage attendu

set res="resultatTestRegression.txt"

cd ../Debug/

Geom.exe >../NonRegression/%redirectionSortie% <../NonRegression/%redirectionEntree%
cd ../NonRegression/
@echo off
fc /C %redirectionSortie% %fichierAComparer% | findstr "aucune diff"
if errorlevel 1 echo Le test a echoue

pause
