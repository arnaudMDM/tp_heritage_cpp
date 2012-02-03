/*************************************************************************
                           ObjetGeometrique  -  description
                             -------------------
    début                : 31 janv. 2012
    copyright            : (C) 2012 par arnaud
*************************************************************************/

//---------- Interface de la classe <ObjetGeometrique> (fichier ObjetGeometrique.h) ------
#if ! defined ( OBJETGEOMETRIQUE_H_ )
#define OBJETGEOMETRIQUE_H_

//--------------------------------------------------- Interfaces utilisées

#include "EltGeometrique.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <ObjetGeometrique>
//
//
//------------------------------------------------------------------------ 

class ObjetGeometrique
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    ObjetGeometrique & operator = ( const ObjetGeometrique & unObjetGeometrique );
    // Mode d'emploi :
    //
    // Contrat :
    //

    vector<EltGeometrique*> getListeEltsGeom() const;
    // Mode d'emploi :
    //
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
    ObjetGeometrique ( const ObjetGeometrique & unObjetGeometrique );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    ObjetGeometrique ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    ObjetGeometrique (vector <EltGeometrique*> uneListeEltsGeom);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~ObjetGeometrique ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
vector <EltGeometrique*> listeEltsGeom;
};

//--------------------------- Autres définitions dépendantes de <ObjetGeometrique>

#endif // OBJETGEOMETRIQUE_H_
