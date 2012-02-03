/*************************************************************************
                           CommandeFactory  -  description
                             -------------------
    début                : 27 janv. 2012
    copyright            : (C) 2012 par Pitou
*************************************************************************/

//---------- Interface de la classe <CommandeFactory> (fichier CommandeFactory.h) ------
#if ! defined ( COMMANDEFACTORY_H_ )
#define COMMANDEFACTORY_H_

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//--------------------------------------------------- Interfaces utilisées
#include "Commande.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <CommandeFactory>
//
//
//------------------------------------------------------------------------ 

class CommandeFactory
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

	static bool GetCommande(char * argv[], Commande* laCommande, ObjetGeometrique *contexte);
    // Mode d'emploi : Retourne l'instance d'une commande
	// correspondant aux arguments passés en paramètre.
    //
    // Contrat : Les cas de LIST, COUNT, UNDO, REDO, S X1, Y1, X2, Y2
	// sont traités en amont par le controleur.
    //

//------------------------------------------------- Surcharge d'opérateurs
    CommandeFactory & operator = ( const CommandeFactory & unCommandeFactory );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    CommandeFactory ( const CommandeFactory & unCommandeFactory );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    CommandeFactory ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~CommandeFactory ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//--------------------------- Autres définitions dépendantes de <CommandeFactory>

#endif // COMMANDEFACTORY_H_
