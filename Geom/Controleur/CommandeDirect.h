/*************************************************************************
                           CommandeDirect  -  description
                             -------------------
    début                : 10 févr. 2012
    copyright            : (C) 2012 par Pitou
*************************************************************************/

//---------- Interface de la classe <CommandeDirect> (fichier CommandeDirect.h) ------
#if ! defined ( COMMANDEDIRECT_H_ )
#define COMMANDEDIRECT_H_

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//--------------------------------------------------- Interfaces utilisées
#include "Commande.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <CommandeDirect>
//
//
//------------------------------------------------------------------------ 

class CommandeDirect : public Commande
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
	void execute();

	void undo();

	void redo();

//------------------------------------------------- Surcharge d'opérateurs
    CommandeDirect & operator = ( const CommandeDirect & unCommandeDirect );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
//    CommandeDirect ( const CommandeDirect & unCommandeDirect );
//    // Mode d'emploi (constructeur de copie) :
//    //
//    // Contrat :
//    //

    CommandeDirect (ObjetGeometrique * nouveauContexte, void (*)() );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~CommandeDirect ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    void (*fct_commande)();
};

//--------------------------- Autres définitions dépendantes de <CommandeDirect>

#endif // COMMANDEDIRECT_H_
