/*************************************************************************
 Point  -  description
 -------------------
 début                : 27 janv. 2012
 copyright            : (C) 2012 par Pitou
 *************************************************************************/

//---------- Interface de la classe <Point> (fichier Point.h) ------
#if ! defined ( POINT_H_ )
#define POINT_H_

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Point>
//
//
//------------------------------------------------------------------------ 

class Point
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste des paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	//

	int getY ( ) const;
	// Mode d'emploi :
	//
	// Contrat :
	//

	int getX ( ) const;
	// Mode d'emploi :
	//
	// Contrat :
	//

	void Translater ( int delatX, int deltaY );
	// Mode d'emploi: translate le point d'un certain vecteur
	//
	// Contrat :
	//
//------------------------------------------------- Surcharge d'opérateurs
	Point & operator = ( const Point & unPoint );
	// Mode d'emploi :
	//
	// Contrat :
	//

//-------------------------------------------- Constructeurs - destructeur
	Point ( const Point & unPoint );
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	Point ( );
	// Mode d'emploi :
	//
	// Contrat :
	//

	Point ( int unX, int unY );
	// Mode d'emploi :Constructeur avec affectation de deux valeurs
	//
	// Contrat :
	//

	virtual ~Point ( );
	// Mode d'emploi :
	//
	// Contrat :
	//

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

	int x;
	int y;
};

//--------------------------- Autres définitions dépendantes de <Point>

#endif // POINT_H_
