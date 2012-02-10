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
static const int MAXSIZE = 10000;
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
void LireCommande(vector<string *> &parametres)
// Algorithme :
//
{
	stringstream flux;
	char *buffer = new char[MAXSIZE];
	string temp;
	getline(cin,temp);

	flux<<temp;

	while(flux>>buffer)
	{
		parametres.push_back(new string(buffer));
	}
//	cin.clear();
//	cin.seekg(0,ios::end);

} //----- fin de Nom
