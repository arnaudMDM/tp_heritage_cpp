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
// Classe concrète permettant de créer la commande correspondant à la
// création d'une Ligne.
//------------------------------------------------------------------------ 

class CommandeCreationLigne: public CommandeCreation {
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques

	void Execute();
	// Crée une nouvelle instance de Ligne et l'ajoute au contexte

	//------------------------------------------------- Surcharge d'opérateurs
	CommandeCreationLigne & operator =(
			const CommandeCreationLigne & unCommandeCreationLigne);
	// Laissé vide dans le fichier de réalisation pour s'assurer du crash lors
	// d'appels implicites.


	//-------------------------------------------- Constructeurs - destructeur
			CommandeCreationLigne(
					const CommandeCreationLigne & unCommandeCreationLigne);
	// Laissé vide dans le fichier de réalisation pour s'assurer du crash lors
	// d'appels implicites.

	CommandeCreationLigne(vector<string *> para, ObjetGeometrique *leContexte,
			const string *requete);
	// Constructeur permettant d'initialiser les attributs d'instance en utilisant la list
	// pour récupérer les éléments numériques et la chaine de caractères pour préparer
	// le message.
	// la validité des données numeriques ne sont pas verifiees dans le constructeur

	virtual ~CommandeCreationLigne();

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- Méthodes protégées

	//----------------------------------------------------- Attributs protégés
	int x1;
	//abscisse du 1er point
	int x2;
	//abscisse du 2eme point
	int y1;
	//ordonnee du 1er point
	int y2;
	//ordonnee du 2eme point

};

//--------------------------- Autres définitions dépendantes de <CommandeCreationLigne>

#endif // COMMANDECREATIONLIGNE_H_
