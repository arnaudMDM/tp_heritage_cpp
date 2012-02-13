/*************************************************************************
 CommandeLoad  -  description
 -------------------
 d�but                : 13 f�vr. 2012
 copyright            : (C) 2012 par Pitou
 *************************************************************************/

//---------- Interface de la classe <CommandeLoad> (fichier CommandeLoad.h) ------
#if ! defined ( COMMANDELOAD_H_ )
#define COMMANDELOAD_H_

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me

//--------------------------------------------------- Interfaces utilis�es
#include "Commande.h"
#include "CommandeCreation.h"
//------------------------------------------------------------- Constantes 
static const string LOAD = "LOAD";
//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <CommandeLoad>
//
//
//------------------------------------------------------------------------ 

class CommandeLoad : public Commande
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
	// type M�thode ( liste des param�tres );
	// Mode d'emploi :
	//
	// Contrat :
	//
	void execute();

	void undo();

	void redo();
//------------------------------------------------- Surcharge d'op�rateurs
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
//----------------------------------------------------- M�thodes prot�g�es

//----------------------------------------------------- Attributs prot�g�s
	string nomFichier;

	vector <Commande *> commandesCreation;
};

//--------------------------- Autres d�finitions d�pendantes de <CommandeLoad>

#endif // COMMANDELOAD_H_
