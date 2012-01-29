/*************************************************************************
 Rectangle  -  description
 -------------------
 début                : 27 janv. 2012
 copyright            : (C) 2012 par Pitou
 *************************************************************************/

//---------- Interface de la classe <Rectangle> (fichier Rectangle.h) ------
#if ! defined ( RECTANGLE_H_ )
#define RECTANGLE_H_

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//--------------------------------------------------- Interfaces utilisées

#include "EltGeometrique.h"
#include "Ligne.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Rectangle>
//
//
//------------------------------------------------------------------------ 

class Rectangle : public EltGeometrique
{
	//----------------------------------------------------------------- PUBLIC
public:
	//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste des paramètres );
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
	// Mode d'emploi : renvoie vrai si le rectangle est inclus dans le rectangle défini par ces deux points. Il peut être égal.
	//renvoie vrai si le rectangle appartient dans le rectangle de sélection.
	//
	// Contrat :
	//
	virtual void Translater ( int deltaX, int deltaY );
	// Mode d'emploi : translate les quatre points qui définissent le rectanngle par le biais du vecteur défini par deltaX et deltaY
	//
	// Contrat :
	//
	//------------------------------------------------- Surcharge d'opérateurs
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
	//----------------------------------------------------- Méthodes protégées
	//----------------------------------------------------- Attributs protégés
	Ligne doublePoints;
};

//--------------------------- Autres définitions dépendantes de <Rectangle>

#endif // RECTANGLE_H_
