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
static const int MAXSIZE = 100;
static const char DELIM = ' ';
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
void Decompose(queue<string *> &parametres, string &temp)
// Algorithme :
//
{
	char *mot;
	mot = new char[MAXSIZE];
	while (flux.get(mot, MAXSIZE, DELIM))
	{
		parametres.push(new string(mot));
	}
} //----- fin de Nom
