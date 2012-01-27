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
#include<Vector>

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

	vector<Point> getListePoints() const;
    // Mode d'emploi :
    //
    // Contrat :
    //


	virtual bool Appartient(int x1, int y1, int x2, int y2);
    // Mode d'emploi : renvoie vrai si la polyligne est inclus dans le rectangle d�fini par ces deux points. Il peut �tre �gal.
	//renvoie vrai si la polyligne appartient dans le rectangle de s�lection.
    //
    // Contrat :
    //

	virtual bool Translater(int deltaX, int deltaY);
    // Mode d'emploi : translate les deux points qui d�finissent la polyligne par le biais du vecteur d�fini par deltaX et deltaY
	//renvoie vrai si la translation s'estbien effectu�e.
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

    PolyLigne (vector<int,int> unListePoints);
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

vector<Point> listePoints;

};

//--------------------------- Autres d�finitions d�pendantes de <PolyLigne>

#endif // POLYLIGNE_H_
