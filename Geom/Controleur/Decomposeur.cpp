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
using namespace std;
//------------------------------------------------------ Include personnel
#include "Decomposeur.h"

///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques
static const int MAXSIZE = 100;
static const char DELIM = ' ';
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
queue <string*> * Decompose(stringstream &flux)
// Algorithme :
//
{
	queue<string*> *parametres = new queue<string *>();
	char *mot = new char[MAXSIZE];


	while (flux.good())
	{
		flux.get(mot, MAXSIZE, DELIM);
		parametres->push(new string(mot));
	}


	return parametres;

} //----- fin de Nom
