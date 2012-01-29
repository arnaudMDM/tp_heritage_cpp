/*************************************************************************
 Rectangle  -  description
 -------------------
 d�but                : 27 janv. 2012
 copyright            : (C) 2012 par Pitou
 *************************************************************************/

//---------- Interface de la classe <Rectangle> (fichier Rectangle.h) ------
#if ! defined ( RECTANGLE_H_ )
#define RECTANGLE_H_

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me

//--------------------------------------------------- Interfaces utilis�es

#include "EltGeometrique.h"
#include "Ligne.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <Rectangle>
//
//
//------------------------------------------------------------------------ 

class Rectangle : public EltGeometrique
{
	//----------------------------------------------------------------- PUBLIC
public:
	//----------------------------------------------------- M�thodes publiques
	// type M�thode ( liste des param�tres );
	// Mode d'emploi :
	//
	// Contrat :
	//
	PolyLigne getDoublePoints ( ) const;
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual bool Appartient ( int x1, int y1, int x2, int y2 );
	// Mode d'emploi : renvoie vrai si le rectangle est inclus dans le rectangle d�fini par ces deux points. Il peut �tre �gal.
	//renvoie vrai si le rectangle appartient dans le rectangle de s�lection.
	//
	// Contrat :
	//
	virtual void Translater ( int deltaX, int deltaY );
	// Mode d'emploi : translate les quatre points qui d�finissent le rectanngle par le biais du vecteur d�fini par deltaX et deltaY
	//
	// Contrat :
	//
	//------------------------------------------------- Surcharge d'op�rateurs
	Rectangle & operator = ( const Rectangle & unRectangle );
	// Mode d'emploi :
	//
	// Contrat :
	//
	//-------------------------------------------- Constructeurs - destructeur
	Rectangle ( const Rectangle & unRectangle );
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	Rectangle ( );
	// Mode d'emploi :
	//
	// Contrat :
	//

	Rectangle (int x1, int y1, int x2, int y2);
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~Rectangle ( );
	// Mode d'emploi :
	//
	// Contrat :
	//
	//------------------------------------------------------------------ PRIVE
protected:
	//----------------------------------------------------- M�thodes prot�g�es
	//----------------------------------------------------- Attributs prot�g�s
	Ligne doublePoints;
};

//--------------------------- Autres d�finitions d�pendantes de <Rectangle>

#endif // RECTANGLE_H_
