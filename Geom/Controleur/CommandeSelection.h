/*************************************************************************
                           CommandeSelection  -  description
                             -------------------
    début                : 27 janv. 2012
    copyright            : (C) 2012 par Pitou
*************************************************************************/

//---------- Interface de la classe <CommandeSelection> (fichier CommandeSelection.h) ------
#if ! defined ( COMMANDESELECTION_H_ )
#define COMMANDESELECTION_H_

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <CommandeSelection>
//
//
//------------------------------------------------------------------------ 

class CommandeSelection
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
    CommandeSelection & operator = ( const CommandeSelection & unCommandeSelection );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    CommandeSelection ( const CommandeSelection & unCommandeSelection );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    CommandeSelection ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~CommandeSelection ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//--------------------------- Autres définitions dépendantes de <CommandeSelection>

#endif // COMMANDESELECTION_H_
