/*************************************************************************
                           Commande  -  description
                             -------------------
    début                : 27 janv. 2012
    copyright            : (C) 2012 par Pitou
*************************************************************************/

//---------- Interface de la classe <Commande> (fichier Commande.h) ------
#if ! defined ( COMMANDE_H_ )
#define COMMANDE_H_

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//--------------------------------------------------- Interfaces utilisées
#include "../Modele/ObjetGeometrique.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Commande>
//
//
//------------------------------------------------------------------------ 

class Commande
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    bool isHistorisable();
    // Mode d'emploi :
    //
    // Contrat :
    //

	virtual void execute() = 0;

	virtual void undo() = 0;

	virtual void redo() = 0;

//------------------------------------------------- Surcharge d'opérateurs
    Commande & operator = ( const Commande & unCommande );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Commande ( const Commande & unCommande );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Commande (ObjetGeometrique *context , bool statusHistorique);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Commande ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    ObjetGeometrique *contexte;
    bool status;
    bool historisable;
    string commande;
};

//--------------------------- Autres définitions dépendantes de <Commande>

#endif // COMMANDE_H_
