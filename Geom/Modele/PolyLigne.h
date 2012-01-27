/*************************************************************************
                           PolyLigne  -  description
                             -------------------
    début                : 27 janv. 2012
    copyright            : (C) 2012 par Pitou
*************************************************************************/

//---------- Interface de la classe <PolyLigne> (fichier PolyLigne.h) ------
#if ! defined ( POLYLIGNE_H_ )
#define POLYLIGNE_H_

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include<Vector>

//--------------------------------------------------- Interfaces utilisées
#include "EltGeometrique.h"
#include "Point.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <PolyLigne>
//
//
//------------------------------------------------------------------------ 

class PolyLigne : public EltGeometrique
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
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
    // Mode d'emploi : renvoie vrai si la polyligne est inclus dans le rectangle défini par ces deux points. Il peut être égal.
	//renvoie vrai si la polyligne appartient dans le rectangle de sélection.
    //
    // Contrat :
    //

	virtual bool Translater(int deltaX, int deltaY);
    // Mode d'emploi : translate les deux points qui définissent la polyligne par le biais du vecteur défini par deltaX et deltaY
	//renvoie vrai si la translation s'estbien effectuée.
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
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
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

vector<Point> listePoints;

};

//--------------------------- Autres définitions dépendantes de <PolyLigne>

#endif // POLYLIGNE_H_
