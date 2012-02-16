/*************************************************************************
 Cercle  -  description
 -------------------
 d�but                : 27 janv. 2012
 copyright            : (C) 2012 par Pitou
 *************************************************************************/

//---------- R�alisation de la classe <Cercle> (fichier Cercle.cpp) -------
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>
#include <sstream>
//------------------------------------------------------ Include personnel
#include "Cercle.h"
#include "Point.h"
#include "../Service.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
// type Cercle::M�thode ( liste des param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode

string Cercle::Description ( )
// Algorithme :
//
{
	ostringstream osX;
	ostringstream osY;
	ostringstream osRayon;
	osX << centre.getX ( );
	osY << centre.getY ( );
	osRayon << rayon;
	string description = "C " + osX.str ( ) + " " + osY.str ( ) + " "
	        + osRayon.str ( );
	description += "\n";
	return description;
} //----- Fin de M�thode

bool Cercle::Appartient ( int x1, int y1, int x2, int y2 )
// type Cercle::M�thode ( liste des param�tres )
// Algorithme :
//
{

	Point point1 ( centre.getX ( ) - rayon, centre.getY ( ) - rayon );
	Point point2 ( centre.getX ( ) - rayon, centre.getY ( ) + rayon );
	Point point3 ( centre.getX ( ) + rayon, centre.getY ( ) - rayon );
	Point point4 ( centre.getX ( ) + rayon, centre.getY ( ) + rayon );

	if ( Contient ( point1.getX ( ), point1.getY ( ), x1, y1, x2, y2 ) )
	{
		if ( Contient ( point2.getX ( ), point2.getY ( ), x1, y1, x2, y2 ) )
		{
			if ( Contient ( point3.getX ( ), point3.getY ( ), x1, y1, x2, y2 ) )
			{
				if ( Contient ( point4.getX ( ), point4.getY ( ), x1, y1, x2,
				        y2 ) )
				{
					return true;
				}
			}
		}
	}
	return false;

} //----- Fin de M�thode

void Cercle::Translater ( int deltaX, int deltaY )
// Algorithme :
//
{
	centre.Translater ( deltaX, deltaY );
} //----- Fin de M�thode

//------------------------------------------------- Surcharge d'op�rateurs
Cercle & Cercle::operator = ( const Cercle & unCercle )
// Algorithme :
//
{
	rayon = unCercle.getRayon ( );
	centre = unCercle.getCentre ( );
	return *this;
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
Cercle::Cercle ( const Cercle & unCercle )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <Cercle>" << endl;
#endif
	rayon = unCercle.getRayon ( );
	centre = unCercle.getCentre ( );
} //----- Fin de Cercle (constructeur de copie)

Cercle::Cercle ( )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Cercle>" << endl;
#endif
} //----- Fin de Cercle

Cercle::Cercle ( int x, int y, int unRayon ) :
		rayon ( unRayon )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Cercle>" << endl;
#endif

	centre = Point ( x, y );
} //----- Fin de Cercle

Cercle::~Cercle ( )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Cercle>" << endl;
#endif
}

Point Cercle::getCentre ( ) const
{
	return centre;
}

int Cercle::getRayon ( ) const
{
	return rayon;
}

//----- Fin de ~Cercle

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

