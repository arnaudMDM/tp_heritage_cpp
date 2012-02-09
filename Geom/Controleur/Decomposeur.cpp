/*************************************************************************
                           Decomposeur  -  description
                             -------------------
    début                : 9 févr. 2012
    copyright            : (C) 2012 par Pitou
*************************************************************************/

//---------- Réalisation du module <Decomposeur> (fichier Decomposeur.cpp) -----

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
#include <string>
#include <sstream>
using namespace std;
#include <iostream>
//------------------------------------------------------ Include personnel
#include "Decomposeur.h"

///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques
static const int MAXSIZE = 100;
static const char DELIM = '\n';
//------------------------------------------------------ Fonctions privées
//static type nom ( liste de paramètres )
// Mode d'emploi :
//
// Contrat :
//
// Algorithme :
//
//{
//} //----- fin de nom

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
void LireCommande(queue<string *> &parametres)
// Algorithme :
//
{
	stringstream flux;
	char *buffer = new char[MAXSIZE];
	cin.get(buffer, MAXSIZE, DELIM);
	flux<<buffer;

	while(flux>>buffer)
	{
		parametres.push(new string(buffer));
	}
	cin.clear();
	cin.seekg(0,ios::end);

} //----- fin de Nom
