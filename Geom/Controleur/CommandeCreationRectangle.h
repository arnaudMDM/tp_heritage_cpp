/*************************************************************************
                           CommandeCreationRectangle  -  description
                             -------------------
    début                : 3 févr. 2012
    copyright            : (C) 2012 par Pitou
*************************************************************************/

//---------- Interface de la classe <CommandeCreationRectangle> (fichier CommandeCreationRectangle.h) ------
#if ! defined ( COMMANDECREATIONRECTANGLE_H_ )
#define COMMANDECREATIONRECTANGLE_H_

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//--------------------------------------------------- Interfaces utilisées
#include "CommandeCreation.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <CommandeCreationRectangle>
//
//
//------------------------------------------------------------------------ 

class CommandeCreationRectangle : public CommandeCreation
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
    CommandeCreationRectangle & operator = ( const CommandeCreationRectangle & unCommandeCreationRectangle );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    CommandeCreationRectangle ( const CommandeCreationRectangle & unCommandeCreationRectangle );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    CommandeCreationRectangle ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~CommandeCreationRectangle ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//--------------------------- Autres définitions dépendantes de <CommandeCreationRectangle>

#endif // COMMANDECREATIONRECTANGLE_H_
