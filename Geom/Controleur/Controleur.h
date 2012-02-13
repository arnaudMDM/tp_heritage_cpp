/*************************************************************************
                           Controleur  -  description
                             -------------------
    début                : 27 janv. 2012
    copyright            : (C) 2012 par Pitou
*************************************************************************/

//---------- Interface de la classe <Controleur> (fichier Controleur.h) ------
#if ! defined ( CONTROLEUR_H_ )
#define CONTROLEUR_H_

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <string>
#include <stack>
#include <vector>
//--------------------------------------------------- Interfaces utilisées
#include "../Modele/ObjetGeometrique.h"
#include "Commande.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Controleur>
//
//
//------------------------------------------------------------------------ 

class Controleur
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void traitementCommande();
    // Mode d'emploi :
    //
    // Contrat :
    //
    static const char CAR_COMMENTAIRE = '#';

//------------------------------------------------- Surcharge d'opérateurs
    Controleur & operator = ( const Controleur & unControleur );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Controleur ( const Controleur & unControleur );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Controleur ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Controleur ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    bool quitter;
    string requete;
    vector < string *> parametres;
    ObjetGeometrique *contexte;
    stack < Commande *> commandesExec;
    stack < Commande *> commandesHistorique;

private:
    void ViderParametres();

    string Defaire();

    string Refaire();

    string Selectionner();

    string Save();
};

//--------------------------- Autres définitions dépendantes de <Controleur>

#endif // CONTROLEUR_H_
