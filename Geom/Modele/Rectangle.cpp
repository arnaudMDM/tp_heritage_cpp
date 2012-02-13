/*************************************************************************
 Rectangle  -  description
 -------------------
 début                : 27 janv. 2012
 copyright            : (C) 2012 par Pitou
 *************************************************************************/

//---------- Réalisation de la classe <Rectangle> (fichier Rectangle.cpp) -------
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Rectangle.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Rectangle::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


string Rectangle::Description()
// Algorithme :
//
{
	string description = "R " + doublePoints.Info();
	description += "\n";
	return description;
} //----- Fin de Méthode


bool Rectangle::Appartient ( int x1, int y1, int x2, int y2 )
// Algorithme :
//
{
if (doublePoints.Appartient(x1, y1, x2, y2))
		{
			return true;
		}
return false;
} //----- Fin de Méthode

void Rectangle::Translater ( int deltaX, int deltaY )
// Algorithme :
//
{
doublePoints.Translater ( deltaX, deltaY );
} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
Rectangle & Rectangle::operator = ( const Rectangle & unRectangle )
// Algorithme :
//
{
doublePoints = unRectangle.getDoublePoints ( );
return *this;
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
Rectangle::Rectangle ( const Rectangle & unRectangle )
// Algorithme :
//
{
#ifdef MAP
cout << "Appel au constructeur de copie de <Rectangle>" << endl;
#endif
doublePoints = unRectangle.getDoublePoints ( );
} //----- Fin de Rectangle (constructeur de copie)

Rectangle::Rectangle ( )
// Algorithme :
//
{
#ifdef MAP
cout << "Appel au constructeur de <Rectangle>" << endl;
#endif
} //----- Fin de Rectangle

Rectangle::Rectangle ( int x1, int y1, int x2, int y2 ) :
	doublePoints ( x1, y1, x2, y2 )
// Algorithme :
//
{
} //----- Fin de Méthode

Rectangle::~Rectangle ( )
// Algorithme :
//
{
#ifdef MAP
cout << "Appel au destructeur de <Rectangle>" << endl;
#endif
}

Ligne Rectangle::getDoublePoints ( ) const
{
return doublePoints;
}

 //----- Fin de ~Rectangle

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

