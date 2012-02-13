/*************************************************************************
                           Controleur  -  description
                             -------------------
    d�but                : 27 janv. 2012
    copyright            : (C) 2012 par Pitou
*************************************************************************/

//---------- Interface de la classe <Controleur> (fichier Controleur.h) ------
#if ! defined ( CONTROLEUR_H_ )
#define CONTROLEUR_H_

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
#include <string>
#include <stack>
#include <vector>
//--------------------------------------------------- Interfaces utilis�es
#include "../Modele/ObjetGeometrique.h"
#include "Commande.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <Controleur>
//
//
//------------------------------------------------------------------------ 

class Controleur
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
    void traitementCommande();
    // Mode d'emploi :
    //
    // Contrat :
    //
    static const char CAR_COMMENTAIRE = '#';

//------------------------------------------------- Surcharge d'op�rateurs
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
//----------------------------------------------------- M�thodes prot�g�es

//----------------------------------------------------- Attributs prot�g�s
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

//--------------------------- Autres d�finitions d�pendantes de <Controleur>

#endif // CONTROLEUR_H_
