/*************************************************************************
 Rectangle  -  description
 -------------------
 d�but                : 27 janv. 2012
 copyright            : (C) 2012 par Pitou
 *************************************************************************/

//---------- R�alisation de la classe <Rectangle> (fichier Rectangle.cpp) -------
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Rectangle.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
// type Rectangle::M�thode ( liste des param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode


string Rectangle::Description()
// Algorithme :
//
{
	string description = "R " + doublePoints.Info();
	description += "\n";
	return description;
} //----- Fin de M�thode


bool Rectangle::Appartient ( int x1, int y1, int x2, int y2 )
// Algorithme :
//
{
if (doublePoints.Appartient(x1, y1, x2, y2))
		{
			return true;
		}
return false;
} //----- Fin de M�thode

void Rectangle::Translater ( int deltaX, int deltaY )
// Algorithme :
//
{
doublePoints.Translater ( deltaX, deltaY );
} //----- Fin de M�thode

//------------------------------------------------- Surcharge d'op�rateurs
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
} //----- Fin de M�thode

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

//----------------------------------------------------- M�thodes prot�g�es

