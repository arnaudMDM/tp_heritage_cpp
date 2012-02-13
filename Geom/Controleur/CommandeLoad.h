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
static const string LOAD = "LOAD";
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
	// type Méthode ( liste des paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	//
	void execute();

	void undo();

	void redo();
//------------------------------------------------- Surcharge d'opérateurs
	CommandeLoad & operator = ( const CommandeLoad & unCommandeLoad );
	// Mode d'emploi :
	//
	// Contrat :
	//

//-------------------------------------------- Constructeurs - destructeur
	CommandeLoad ( const CommandeLoad & unCommandeLoad );
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	CommandeLoad (const string &unNomFichier, ObjetGeometrique *unContexte, bool statusHistorique = true );
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~CommandeLoad ( );
	// Mode d'emploi :
	//
	// Contrat :
	//

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	string nomFichier;

	vector <Commande *> commandesCreation;
};

//--------------------------- Autres définitions dépendantes de <CommandeLoad>

#endif // COMMANDELOAD_H_
