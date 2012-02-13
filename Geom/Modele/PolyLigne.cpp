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
#include <sstream>

//------------------------------------------------------ Include personnel
#include "PolyLigne.h"
#include "Point.h"
#include "Service.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type PolyLigne::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


string PolyLigne::Description()
// Algorithme :
//
{
	ostringstream osX;
	ostringstream osY;
	string description = "PL";
	for(vector<Point*>::iterator it = listePoints.begin() ; it != listePoints.end() ; it++)
	{
		osX << (*it)->getX();
		osY << (*it)->getY();
		description.append(" " + osX.str() + " " + osY.str());
		osX.str("");
		osY.str("");
	}
	description += "\n";
	return description;
} //----- Fin de Méthode


bool PolyLigne::Appartient(int x1, int y1, int x2, int y2)
// Algorithme :
//
{
	for(vector<Point*>::iterator it = listePoints.begin() ; it != listePoints.end() ; it++)
	{
		if(!Contient((*it)->getX(),(*it)->getY(),x1,y1,x2,y2))
		{
			return false;
		}
	}
	return true;
} //----- Fin de Méthode

void PolyLigne::Translater(int deltaX, int deltaY)
// Algorithme :
//
{
	vector<Point*>::iterator it;
	for(it = listePoints.begin(); it != listePoints.end() ; it++)
	{
		(*it)->Translater(deltaX, deltaY);
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


PolyLigne::PolyLigne (vector<int> unListeX, vector<int> unListeY)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <PolyLigne>" << endl;
#endif
    vector<int>::iterator it1;
    vector<int>::iterator it2 = unListeY.begin();
    for(it1 = unListeX.begin() ; it1 != unListeX.end() ; it1++)
    {
    	listePoints.push_back(new Point(*it1,*it2));
    	it2++;
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

vector<Point*> PolyLigne::getListePoints() const
{
    return listePoints;
}

 //----- Fin de ~PolyLigne


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

