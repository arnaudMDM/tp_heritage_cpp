/*************************************************************************
 Point  -  description
 -------------------
 d�but                : 27 janv. 2012
 copyright            : (C) 2012 par Pitou
 *************************************************************************/

//---------- Interface de la classe <Point> (fichier Point.h) ------
#if ! defined ( POINT_H_ )
#define POINT_H_

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me

//--------------------------------------------------- Interfaces utilis�es

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <Point>
//
//
//------------------------------------------------------------------------ 

class Point
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
	// type M�thode ( liste des param�tres );
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
//------------------------------------------------- Surcharge d'op�rateurs
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
//----------------------------------------------------- M�thodes prot�g�es

//----------------------------------------------------- Attributs prot�g�s

	int x;
	int y;
};

//--------------------------- Autres d�finitions d�pendantes de <Point>

#endif // POINT_H_
