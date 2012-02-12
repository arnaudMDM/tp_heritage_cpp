/*************************************************************************
                           CommandeSuppression  -  description
                             -------------------
    début                : 12 févr. 2012
    copyright            : (C) 2012 par Pitou
*************************************************************************/

//---------- Interface de la classe <CommandeSuppression> (fichier CommandeSuppression.h) ------
#if ! defined ( COMMANDESUPPRESSION_H_ )
#define COMMANDESUPPRESSION_H_

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//--------------------------------------------------- Interfaces utilisées
#include "Commande.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <CommandeSuppression>
//
//
//------------------------------------------------------------------------ 

class CommandeSuppression : public Commande
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
	enum typeEtatSuppression {DELETE, CLEAR};

	void execute();

	void redo();

	void undo();

//------------------------------------------------- Surcharge d'opérateurs
    CommandeSuppression & operator = ( const CommandeSuppression & unCommandeSuppression );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    CommandeSuppression ( const CommandeSuppression & unCommandeSuppression );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    CommandeSuppression (ObjetGeometrique *nouveauContexte,typeEtatSuppression, bool statusHistorique = true );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~CommandeSuppression ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    vector<EltGeometrique *> elementsSupprimes;

    typeEtatSuppression etatSuppression;

};

//--------------------------- Autres définitions dépendantes de <CommandeSuppression>

#endif // COMMANDESUPPRESSION_H_
