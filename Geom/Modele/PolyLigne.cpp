/*************************************************************************
                           PolyLigne  -  description
                             -------------------
    d�but                : 27 janv. 2012
    copyright            : (C) 2012 par Pitou
*************************************************************************/

//---------- R�alisation de la classe <PolyLigne> (fichier PolyLigne.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "PolyLigne.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
// type PolyLigne::M�thode ( liste des param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode


//------------------------------------------------- Surcharge d'op�rateurs
PolyLigne & PolyLigne::operator = ( const PolyLigne & unPolyLigne )
// Algorithme :
//
{
	listePoints = unPolyLigne.getListePoints();
	return this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
PolyLigne::PolyLigne ( const PolyLigne & unPolyLigne )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <PolyLigne>" << endl;
#endif
    listePoints = unPolyLigne.getListePoints();
} //----- Fin de PolyLigne (constructeur de copie)


PolyLigne::PolyLigne ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <PolyLigne>" << endl;
#endif
} //----- Fin de PolyLigne


PolyLigne::PolyLigne (vector<int,int> unListePoints)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <PolyLigne>" << endl;
#endif
    listePoints = unListePoints;
} //----- Fin de PolyLigne


PolyLigne::~PolyLigne ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <PolyLigne>" << endl;
#endif
}

vector<Point> PolyLigne::getListePoints() const
{
    return listePoints;
}

 //----- Fin de ~PolyLigne


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

