/*************************************************************************
                           Point  -  description
                             -------------------
    début                : 27 janv. 2012
    copyright            : (C) 2012 par Pitou
*************************************************************************/

//---------- Interface de la classe <Point> (fichier Point.h) ------
#if ! defined ( POINT_H_ )
#define POINT_H_

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Point>
//
//
//------------------------------------------------------------------------ 

class Point : public Ancetre
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
    Point & operator = ( const Point & unPoint );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Point ( const Point & unPoint );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Point ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Point ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//--------------------------- Autres définitions dépendantes de <Point>

#endif // POINT_H_
