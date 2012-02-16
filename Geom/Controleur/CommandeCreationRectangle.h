/*************************************************************************
 CommandeCreationRectangle  -  description
 -------------------
 début                : 3 févr. 2012
 copyright            : (C) 2012 par Pitou
 *************************************************************************/

//---------- Interface de la classe <CommandeCreationRectangle> (fichier CommandeCreationRectangle.h) ------
#if ! defined ( COMMANDECREATIONRECTANGLE_H_ )
#define COMMANDECREATIONRECTANGLE_H_

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//--------------------------------------------------- Interfaces utilisées
#include "CommandeCreation.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <CommandeCreationRectangle>
// Classe concrète permettant de créer la commande correspondant à la
// création d'un Rectangle.
//------------------------------------------------------------------------ 

class CommandeCreationRectangle : public CommandeCreation
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

	void Execute ( );
	// Crée une nouvelle instance de Rectangle et l'ajoute au contexte

//------------------------------------------------- Surcharge d'opérateurs
	CommandeCreationRectangle & operator = (
	        const CommandeCreationRectangle & unCommandeCreationRectangle );
	// Laissé vide dans le fichier de réalisation pour s'assurer du crash lors
	// d'appels implicites.

//-------------------------------------------- Constructeurs - destructeur
	CommandeCreationRectangle (
	        const CommandeCreationRectangle & unCommandeCreationRectangle );
	// Laissé vide dans le fichier de réalisation pour s'assurer du crash lors
	// d'appels implicites.

	CommandeCreationRectangle ( vector<string *> para,
	        ObjetGeometrique *unContexte, const string *requete );
	// Constructeur permettant d'initialiser les attributs d'instance en utilisant la list
	// pour récupérer les éléments numériques et la chaine de caractères pour préparer
	// le message.
	// la validité des données numeriques ne sont pas verifiees dans le constructeur

	virtual ~CommandeCreationRectangle ( );

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

//--------------------------- Autres définitions dépendantes de <CommandeCreationRectangle>

#endif // COMMANDECREATIONRECTANGLE_H_
