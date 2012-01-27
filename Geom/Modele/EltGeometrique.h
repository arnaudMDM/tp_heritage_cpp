/*************************************************************************
                           EltGeometrique  -  description
                             -------------------
    début                : 27 janv. 2012
    copyright            : (C) 2012 par Pitou
*************************************************************************/

//---------- Interface de la classe <EltGeometrique> (fichier EltGeometrique.h) ------
#if ! defined ( ELTGEOMETRIQUE_H_ )
#define ELTGEOMETRIQUE_H_

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <EltGeometrique>
//
//
//------------------------------------------------------------------------ 

class EltGeometrique
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


	virtual bool Appartient(int X1, int Y1, int X2, int Y2);
    // Mode d'emploi : renvoie vrai si la forme géométrique appartient dans le caré défini par ces deux points.
    //
    // Contrat :
    //

	virtual bool Translater(int deltaX, int deltaY);
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
    EltGeometrique & operator = ( const EltGeometrique & unEltGeometrique );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    EltGeometrique ( const EltGeometrique & unEltGeometrique );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    EltGeometrique ( );
    // Mode d'emploi :
    //
    // Contrat :
    //



    virtual ~EltGeometrique ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//--------------------------- Autres définitions dépendantes de <EltGeometrique>

#endif // ELTGEOMETRIQUE_H_
