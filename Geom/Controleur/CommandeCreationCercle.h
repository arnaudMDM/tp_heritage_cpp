/*************************************************************************
                           CommandeCreationCercle  -  description
                             -------------------
    début                : 3 févr. 2012
    copyright            : (C) 2012 par Pitou
*************************************************************************/

//---------- Interface de la classe <CommandeCreationCercle> (fichier CommandeCreationCercle.h) ------
#if ! defined ( COMMANDECREATIONCERCLE_H_ )
#define COMMANDECREATIONCERCLE_H_

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <string>
#include <queue>
//--------------------------------------------------- Interfaces utilisées
#include "CommandeCreation.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <CommandeCreationCercle>
//
//
//------------------------------------------------------------------------ 

class CommandeCreationCercle : public CommandeCreation
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
//    CommandeCreationCercle & operator = ( const CommandeCreationCercle & unCommandeCreationCercle );
//    // Mode d'emploi :
//    //
//    // Contrat :
//    //
//
//
////-------------------------------------------- Constructeurs - destructeur
//    CommandeCreationCercle ( const CommandeCreationCercle & unCommandeCreationCercle );
//    // Mode d'emploi (constructeur de copie) :
//    //
//    // Contrat :
//    //

    CommandeCreationCercle (vector < string *> para, ObjetGeometrique *unContexte);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~CommandeCreationCercle ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    int x1;
    int y1;
    int rayon;

};

//--------------------------- Autres définitions dépendantes de <CommandeCreationCercle>

#endif // COMMANDECREATIONCERCLE_H_
