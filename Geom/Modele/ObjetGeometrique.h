/*************************************************************************
                           ObjetGeometrique  -  description
                             -------------------
    début                : 31 janv. 2012
    copyright            : (C) 2012 par arnaud
*************************************************************************/

//---------- Interface de la classe <ObjetGeometrique> (fichier ObjetGeometrique.h) ------
#if ! defined ( OBJETGEOMETRIQUE_H_ )
#define OBJETGEOMETRIQUE_H_


//---------------------------------------------------
using namespace std;
//--------------------------------------------------- Interfaces utilisées

#include "EltGeometrique.h"
#include <vector>

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

    string DescriptionEltsSelect();
    // Mode d'emploi :
    //
    // Contrat :
    //

    string DescriptionEltsTotal();
    // Mode d'emploi :
    //
    // Contrat :
    //

	int NbElts();
    // Mode d'emploi :
    //
    // Contrat :
    //

    void SupprimerTousElts();
    // Mode d'emploi :
    //
    // Contrat :
    //

    void SupprimerElts();
    // Mode d'emploi :
    //
    // Contrat :
    //

    void SupprimerEltParticulier(EltGeometrique *elt);
    // Mode d'emploi :
    //
    // Contrat :
    //

    void Translater(int x, int y);
    // Mode d'emploi :
    //
    // Contrat :
    //

    void SelectionnerElts(int x1, int y1, int x2, int y2);
    // Mode d'emploi :
    //
    // Contrat :
    //

    void AjouterEltGeom(EltGeometrique *unEltGeometrique);
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

    vector <EltGeometrique *> getListeEltsGeomTotal() const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    vector <EltGeometrique *> getListeEltsGeomSelect() const;
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

    ObjetGeometrique (vector <EltGeometrique *> uneListeEltsGeom);
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
vector <EltGeometrique *> listeEltsGeomTotal;
vector <EltGeometrique *> listeEltsGeomSelect;
};

//--------------------------- Autres définitions dépendantes de <ObjetGeometrique>

#endif // OBJETGEOMETRIQUE_H_
