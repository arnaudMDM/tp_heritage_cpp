/*************************************************************************
                           CommandeDeplac  -  description
                             -------------------
    début                : 12 févr. 2012
    copyright            : (C) 2012 par Pitou
*************************************************************************/

//---------- Interface de la classe <CommandeDeplac> (fichier CommandeDeplac.h) ------
#if ! defined ( COMMANDEDEPLAC_H_ )
#define COMMANDEDEPLAC_H_

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//--------------------------------------------------- Interfaces utilisées
#include "Commande.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <CommandeDeplac>
//
//
//------------------------------------------------------------------------ 

class CommandeDeplac : public Commande
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

	void Execute();

	void Redo();

	void Undo();

//------------------------------------------------- Surcharge d'opérateurs
    CommandeDeplac & operator = ( const CommandeDeplac & unCommandeDeplac );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    CommandeDeplac ( const CommandeDeplac & unCommandeDeplac );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    CommandeDeplac (vector <string *> para, ObjetGeometrique *unContexte, bool unStatus = true );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~CommandeDeplac ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    int deltaX;
    int deltaY;
    vector <EltGeometrique *> elementsDeplaces;
};

//--------------------------- Autres définitions dépendantes de <CommandeDeplac>

#endif // COMMANDEDEPLAC_H_
