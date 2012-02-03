/*************************************************************************
                           ObjetGeometrique  -  description
                             -------------------
    d�but                : 31 janv. 2012
    copyright            : (C) 2012 par arnaud
*************************************************************************/

//---------- Interface de la classe <ObjetGeometrique> (fichier ObjetGeometrique.h) ------
#if ! defined ( OBJETGEOMETRIQUE_H_ )
#define OBJETGEOMETRIQUE_H_

//--------------------------------------------------- Interfaces utilis�es

#include "EltGeometrique.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <ObjetGeometrique>
//
//
//------------------------------------------------------------------------ 

class ObjetGeometrique
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
    // type M�thode ( liste des param�tres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'op�rateurs
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
//----------------------------------------------------- M�thodes prot�g�es

//----------------------------------------------------- Attributs prot�g�s
vector <EltGeometrique*> listeEltsGeom;
};

//--------------------------- Autres d�finitions d�pendantes de <ObjetGeometrique>

#endif // OBJETGEOMETRIQUE_H_
