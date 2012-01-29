/*************************************************************************
                           PolyLigne  -  description
                             -------------------
    début                : 27 janv. 2012
    copyright            : (C) 2012 par Pitou
*************************************************************************/

//---------- Réalisation de la classe <PolyLigne> (fichier PolyLigne.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <vector>

//------------------------------------------------------ Include personnel
#include "PolyLigne.h"
#include "Point.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type PolyLigne::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

// type PolyLigne::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void PolyLigne::Translater(int deltaX, int deltaY)
// Algorithme :
//
{
	vector<Point>::iterator it;
	for(it = listePoints.begin(); it != listePoints.end() ; it++)
	{
		it->Translater(deltaX, deltaY);
	}
} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
PolyLigne & PolyLigne::operator = ( const PolyLigne & unPolyLigne )
// Algorithme :
//
{
	listePoints = unPolyLigne.getListePoints();
	return *this;
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
    vector<int,int>::iterator it;
    for(it = unListePoints.begin() ; it != unListePoints.end() ; it++)
    {
    	listePoints.push_back(Point(it->first, it->second));
    }
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

//----------------------------------------------------- Méthodes protégées

