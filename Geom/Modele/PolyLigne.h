/*************************************************************************
                           PolyLigne  -  description
                             -------------------
    d�but                : 27 janv. 2012
    copyright            : (C) 2012 par Pitou
*************************************************************************/

//---------- Interface de la classe <PolyLigne> (fichier PolyLigne.h) ------
#if ! defined ( POLYLIGNE_H_ )
#define POLYLIGNE_H_

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me

//--------------------------------------------------- Interfaces utilis�es
#include "EltGeometrique.h"
#include "Point.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <PolyLigne>
//
//
//------------------------------------------------------------------------ 

class PolyLigne : public EltGeometrique
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
    // type M�thode ( liste des param�tres );
    // Mode d'emploi :
    //
    // Contrat :
    //


	virtual bool Appartient(int X1, int Y1, int X2, int Y2);
    // Mode d'emploi : renvoie vrai si la forme g�om�trique appartient dans le car� d�fini par ces deux points.
    //
    // Contrat :
    //

	virtual bool Translater(int deltaX, int deltaY);
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'op�rateurs
    PolyLigne & operator = ( const PolyLigne & unPolyLigne );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    PolyLigne ( const PolyLigne & unPolyLigne );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    PolyLigne ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~PolyLigne ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- M�thodes prot�g�es

//----------------------------------------------------- Attributs prot�g�s
    Point point1;
    Point point2;

};

//--------------------------- Autres d�finitions d�pendantes de <PolyLigne>

#endif // POLYLIGNE_H_
