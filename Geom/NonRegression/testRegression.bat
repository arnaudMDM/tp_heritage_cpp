@echo off
rem batch permettant d'automatiser les tests de non regression du prg Geom
set redirectionSortie="redirectionSortieAffichage.txt"
rem Cette variable va contenir tout le texte obtenu lors de l'éxécution du prg

set redirectionEntree=""
rem le fichier contenant les différentes commandes à faire executer par le prg

set fichierAComparer="testRegression.txt"
rem le fichier contenant l'affichage attendu

set res="resultatTestRegression.txt"

cd ../Debug/

Geom.exe >../NonRegression/%redirectionSortie%
cd ../NonRegression/
@echo on
cmp --verbose --print-bytes %redirectionSortie% %fichierAComparer% >%res%
set /P contenu= < %res%
echo var : %contenu%
@echo off
if  errorlevel 0 echo Erreur
pause
