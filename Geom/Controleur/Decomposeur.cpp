/*************************************************************************
                           Decomposeur  -  description
                             -------------------
    d�but                : 9 f�vr. 2012
    copyright            : (C) 2012 par Pitou
*************************************************************************/

//---------- R�alisation du module <Decomposeur> (fichier Decomposeur.cpp) -----

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include syst�me
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
//Taille maximale du buffer
//------------------------------------------------------ Fonctions priv�es

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
void LireCommande(vector<string *> &parametres, string &requete)
// Algorithme : lit le contenu saisi sur cin, le d�compose en une liste
//(separateur : espace) et valorise requete par la chaine complete
//
{
	stringstream flux;
	char *buffer = new char[MAXSIZE];
	getline(cin,requete);

	flux<<requete;

	while(flux>>buffer)
	{
		parametres.push_back(new string(buffer));
	}

	delete buffer;
} //----- fin de LireCommande

void DecomposerCommande(vector<string *> &parametres, string *requete)
{
	stringstream flux;
	char *buffer = new char[MAXSIZE];

	flux<<*requete;

	while(flux>>buffer)
	{
		parametres.push_back(new string(buffer));
	}

	delete buffer;
} //----- fin de DecomposerCommande
