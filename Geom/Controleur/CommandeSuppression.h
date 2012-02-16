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
// Classe permettant d'effectuer tous les traitements de suppression sur le
// modele. Le comportement choisi est effectue via une enumeration, utilise
// uniquement dans le constructeur (les comportements derrière Execute(), Undo()
// et Redo() restent les meme).
//
//------------------------------------------------------------------------ 

class CommandeSuppression: public Commande
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

	enum typeEtatSuppression
	{
		DELETE, CLEAR
	};

	void Execute ( );
	//Supprime les elements de elementsSupprimes du contexte

	void Redo ( );
	//Effectue de nouveau une suppression, correspond a Execute()
	//Doit etre appele apres un Undo()

	void Undo ( );
	//Annule l'action sur le modele de Execute() ou Redo() :
	//Rajoute les elements supprimes.

//------------------------------------------------- Surcharge d'opérateurs
	CommandeSuppression & operator = (
			const CommandeSuppression & unCommandeSuppression );
	// Laissé vide dans le fichier de réalisation pour s'assurer du crash lors
	// d'appels implicites.

//-------------------------------------------- Constructeurs - destructeur
	CommandeSuppression ( const CommandeSuppression & unCommandeSuppression );
	// Laissé vide dans le fichier de réalisation pour s'assurer du crash lors
	// d'appels implicites.

	CommandeSuppression ( ObjetGeometrique *nouveauContexte,
			typeEtatSuppression );
	// Constructeur permettant de valoriser les attributs d'instance
	// l'enumeration permet de choisir, qui des elements selectionnes du contexte
	// ou de tous les elements du contexte seront retenus pour effectuer l'action
	// de suppression.

	virtual ~CommandeSuppression ( );

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	vector<EltGeometrique *> elementsSupprimes;
	//Liste des elements a supprimer du modele

	typeEtatSuppression etatSuppression;
	//Attribut permettant de savoir quel type de suppression est effectue.
	//A un role de trace car cet attribut n'est utilise que dans le
	//constructeur

};

//--------------------------- Autres définitions dépendantes de <CommandeSuppression>

#endif // COMMANDESUPPRESSION_H_
