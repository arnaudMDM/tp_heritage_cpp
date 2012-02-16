/*************************************************************************
                           PolyLigne  -  description
                             -------------------
    début                : 27 janv. 2012
    copyright            : (C) 2012 par Pitou
*************************************************************************/

//---------- Réalisation de la classe <Ligne> (fichier Ligne.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <sstream>

//------------------------------------------------------ Include personnel
#include "Ligne.h"
#include "../Service.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Ligne::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


string Ligne::Info()
// Algorithme :
//
{
	ostringstream osX1;
	ostringstream osY1;
	ostringstream osX2;
	ostringstream osY2;
	osX1 << point1.getX();
	osY1 << point1.getY();
	osX2 << point2.getX();
	osY2 << point2.getY();
	string info = osX1.str() + " " + osY1.str() + " " + osX2.str() + " " + osY2.str();
	return info;
} //----- Fin de Méthode


string Ligne::Description()
// Algorithme :
//
{
	string description = "L " + Info() + "\n";
	return description;
} //----- Fin de Méthode


bool Ligne::Appartient(int x1, int y1, int x2, int y2)
// Algorithme : On vérifie que le premier point ainsi que le deuxième apprtiennent au rectangle de sélection
//
{
	if(Contient(point1.getX(), point1.getY(), x1, y1, x2, y2)&&Contient(point2.getX(), point2.getY(), x1, y1, x2, y2))
			{
		return true;
			}
	return false;
} //----- Fin de Méthode

void Ligne::Translater(int deltaX, int deltaY)
// Algorithme :
//
{
point1.Translater(deltaX, deltaY);
point2.Translater(deltaX, deltaY);
} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
Ligne & Ligne::operator = ( const Ligne & unLigne )
// Algorithme :
//
{
    point1 = unLigne.getPoint1();
    point2 = unLigne.getPoint2();
    return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Ligne::Ligne ( const Ligne & unLigne )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <PolyLigne>" << endl;
#endif
    point1 = unLigne.getPoint1();
    point2 = unLigne.getPoint2();
} //----- Fin de PolyLigne (constructeur de copie)


Ligne::Ligne ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <PolyLigne>" << endl;
#endif
} //----- Fin de PolyLigne


Ligne::Ligne (int x1, int y1, int x2, int y2):
		point1(x1,y1),point2(x2,y2)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <PolyLigne>" << endl;
#endif
} //----- Fin de PolyLigne


Ligne::~Ligne ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <PolyLigne>" << endl;
#endif
}

Point Ligne::getPoint1() const
{
    return point1;
}

Point Ligne::getPoint2() const
{
    return point2;
}


 //----- Fin de ~PolyLigne


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

