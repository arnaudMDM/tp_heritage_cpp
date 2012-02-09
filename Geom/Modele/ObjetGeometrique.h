/*************************************************************************
                           ObjetGeometrique  -  description
                             -------------------
    d�but                : 31 janv. 2012
    copyright            : (C) 2012 par arnaud
*************************************************************************/

//---------- Interface de la classe <ObjetGeometrique> (fichier ObjetGeometrique.h) ------
#if ! defined ( OBJETGEOMETRIQUE_H_ )
#define OBJETGEOMETRIQUE_H_


//---------------------------------------------------
using namespace std;
//--------------------------------------------------- Interfaces utilis�es

#include "EltGeometrique.h"
#include <vector>

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


//------------------------------------------------- Surcharge d'op�rateurs
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
//----------------------------------------------------- M�thodes prot�g�es

//----------------------------------------------------- Attributs prot�g�s
vector <EltGeometrique *> listeEltsGeomTotal;
vector <EltGeometrique *> listeEltsGeomSelect;
};

//--------------------------- Autres d�finitions d�pendantes de <ObjetGeometrique>

#endif // OBJETGEOMETRIQUE_H_
