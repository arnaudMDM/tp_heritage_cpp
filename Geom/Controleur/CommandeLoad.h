/*************************************************************************
 CommandeLoad  -  description
 -------------------
 début                : 13 févr. 2012
 copyright            : (C) 2012 par Pitou
 *************************************************************************/

//---------- Interface de la classe <CommandeLoad> (fichier CommandeLoad.h) ------
#if ! defined ( COMMANDELOAD_H_ )
#define COMMANDELOAD_H_

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//--------------------------------------------------- Interfaces utilisées
#include "Commande.h"
#include "CommandeCreation.h"
//------------------------------------------------------------- Constantes 
static const string LOAD = "LOAD ";
//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <CommandeLoad>
//
//
//------------------------------------------------------------------------ 

class CommandeLoad : public Commande
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	void Execute();
	// Mode d'emploi : Methode permettant d'executer l'ensemble des commandes
	// de creation.

	bool IsOk();
	// Mode d'emploi : permet de connaitre l'etat de l'attribut statusLecture



	void Undo();
	// Mode d'emploi : Permet d'annuler l'action effectuee par Execute() ou
	// Redo().
	// Doit etre execute apres ces derniers pour avoir un effet.

	void Redo();
	// Mode d'emploi : Permet d'effectuer de nouveau l'action annule par
	// un appel a Undo().
	// Doit etre execute apres ce dernier.

//------------------------------------------------- Surcharge d'opérateurs
	CommandeLoad & operator = ( const CommandeLoad & unCommandeLoad );
	// Laissé vide dans le fichier de réalisation pour s'assurer du crash lors
	// d'appels implicites.

//-------------------------------------------- Constructeurs - destructeur
	CommandeLoad ( const CommandeLoad & unCommandeLoad );
	// Laissé vide dans le fichier de réalisation pour s'assurer du crash lors
	// d'appels implicites.

	CommandeLoad (const string &unNomFichier, ObjetGeometrique *unContexte);
	// Constructeur permettant d'initialiser les attributs d'instance.
	// Le constructeur se charge egalement de la recuperation des descriptions
	// des commandes stockes dans le fichier de nom nomFichier.
	// Mise en garde : cette instance est exploitable ssi statusLecture vaut vrai.

	virtual ~CommandeLoad ( );


//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	string nomFichier;
	//Le nom du fichier contenant les descripteurs de commande de création

	bool statusLecture;
	//Vrai si la lecture dans le fichier s'est bien passé : pas de présence
	//de commande interdites...Faux sinon

	vector <Commande *> commandesCreation;
	//la liste de commandes de creation permettant d'effectuer la creation des
	//differents objets a ajouter au contexte.
};

//--------------------------- Autres définitions dépendantes de <CommandeLoad>

#endif // COMMANDELOAD_H_
