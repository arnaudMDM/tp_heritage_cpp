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
//------------------------------------------------------ Fonctions priv�es
//static type nom ( liste de param�tres )
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
void LireCommande(vector<string *> &parametres, string &requete)
// Algorithme :
//
{
//	if(!parametres.empty())
//	{
////	    for(vector<string *>::iterator it = parametres.begin(); it != parametres.end(); it++)
////	    {
////	    	delete *it;
////	    }
////
//	    parametres.clear();
//	}

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
// Algorithme :
//
{
	stringstream flux;
	char *buffer = new char[MAXSIZE];

	flux<<*requete;

	while(flux>>buffer)
	{
		parametres.push_back(new string(buffer));
	}

	delete buffer;
} //----- fin de LireCommande
