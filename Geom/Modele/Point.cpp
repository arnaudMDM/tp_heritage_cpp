/*************************************************************************
 Point  -  description
 -------------------
 d�but                : 27 janv. 2012
 copyright            : (C) 2012 par Pitou
 *************************************************************************/

//---------- R�alisation de la classe <Point> (fichier Point.cpp) -------
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Point.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
// type Point::M�thode ( liste des param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode

int Point::getX ( ) const
// Algorithme : Trivial
//
{
	return x;
} //----- Fin de M�thode

int Point::getY ( ) const
// Algorithme : Trivial
//
{
	return y;
} //----- Fin de M�thode

void Point::Translater ( int deltaX, int deltaY )
// Algorithme : trivial
//
{
	x += deltaX;
	y += deltaY;
} //----- Fin de M�thode

//------------------------------------------------- Surcharge d'op�rateurs
Point & Point::operator = ( const Point & unPoint )
// Algorithme :
//
{
	x = unPoint.getX ( );
	y = unPoint.getY ( );
	return *this;
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
Point::Point ( const Point & unPoint )
// Algorithme : Trivial
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <Point>" << endl;
#endif
	x = unPoint.getX ( );
	y = unPoint.getY ( );
} //----- Fin de Point (constructeur de copie)

Point::Point ( )
// Algorithme : Trivial
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Point>" << endl;
#endif
} //----- Fin de Point

Point::Point ( int unX, int unY )
// Algorithme : Trivial
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Point>" << endl;
#endif
	x = unX;
	y = unY;
} //----- Fin de Point

Point::~Point ( )
// Algorithme : Trivial
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Point>" << endl;
#endif
}

//----- Fin de ~Point

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

