/*************************************************************************
                           CommandeCreationLigne  -  description
                             -------------------
    début                : 3 févr. 2012
    copyright            : (C) 2012 par Pitou
*************************************************************************/

//---------- Interface de la classe <CommandeCreationLigne> (fichier CommandeCreationLigne.h) ------
#if ! defined ( COMMANDECREATIONLIGNE_H_ )
#define COMMANDECREATIONLIGNE_H_

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//--------------------------------------------------- Interfaces utilisées
#include "CommandeCreation.h"
#include <queue>
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <CommandeCreationLigne>
//
//
//------------------------------------------------------------------------ 

class CommandeCreationLigne : public CommandeCreation
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

//------------------------------------------------- Surcharge d'opérateurs
    CommandeCreationLigne & operator = ( const CommandeCreationLigne & unCommandeCreationLigne );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    CommandeCreationLigne ( const CommandeCreationLigne & unCommandeCreationLigne );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    CommandeCreationLigne (vector < string *> para, ObjetGeometrique *leContexte, const string *requete);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~CommandeCreationLigne ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    int x1;
    int x2;
    int y1;
    int y2;

};

//--------------------------- Autres définitions dépendantes de <CommandeCreationLigne>

#endif // COMMANDECREATIONLIGNE_H_
