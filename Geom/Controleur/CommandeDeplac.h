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

	void Execute();

	void Redo();

	void Undo();

//------------------------------------------------- Surcharge d'opérateurs
    CommandeDeplac & operator = ( const CommandeDeplac & unCommandeDeplac );
	// Laissé vide dans le fichier de réalisation pour s'assurer du crash lors
	// d'appels implicites.

//-------------------------------------------- Constructeurs - destructeur
    CommandeDeplac ( const CommandeDeplac & unCommandeDeplac );
	// Laissé vide dans le fichier de réalisation pour s'assurer du crash lors
	// d'appels implicites.

    CommandeDeplac (vector <string *> para, ObjetGeometrique *unContexte, const string *requete);
	// Constructeur permettant d'initialiser les attributs d'instance en utilisant la list
	// pour récupérer les éléments numériques et la chaine de caractères pour préparer
	// le message.
	// la validité des données numeriques ne sont pas verifiees dans le constructeur


    virtual ~CommandeDeplac ( );

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    int deltaX;
    //
    int deltaY;
    //
    vector <EltGeometrique *> elementsDeplaces;
    //
};

//--------------------------- Autres définitions dépendantes de <CommandeDeplac>

#endif // COMMANDEDEPLAC_H_
