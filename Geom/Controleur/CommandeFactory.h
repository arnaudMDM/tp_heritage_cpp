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
#include <string>
#include <vector>
//--------------------------------------------------- Interfaces utilisées
#include "Commande.h"
#include "../Service.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 
//------------------------------------------------------------------------ 
// Rôle de la classe <CommandeFactory>
// Classe statique jouant le role d'une Fabrique de Commande.
//
//------------------------------------------------------------------------ 

class CommandeFactory
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	static const string EXTENSION_FICHIER;
	//Chaine de caracteres définissant l'extension du fichier de sauvegarde

	static bool GetCommande ( vector<string *> para, Commande **laCommande,
			ObjetGeometrique *contexte, string *requete, TypeCommande unTypeCommande = ToutesCommandes);
	// Mode d'emploi : Retourne un booleen valant vrai si l'instance d'une commande
	// correspondant aux arguments passés en paramètre a ete cree.
	// Faux sinon.
	//
	// Contrat : Les cas de LIST, COUNT, UNDO, REDO, S X1, Y1, X2, Y2
	// sont traités en amont par le controleur.
	//

//------------------------------------------------- Surcharge d'opérateurs
	CommandeFactory & operator = ( const CommandeFactory & unCommandeFactory );
	// Laissé vide dans le fichier de réalisation pour s'assurer du crash lors
	// d'appels implicites.

//-------------------------------------------- Constructeurs - destructeur
	CommandeFactory ( const CommandeFactory & unCommandeFactory );
	// Laissé vide dans le fichier de réalisation pour s'assurer du crash lors
	// d'appels implicites.



	virtual ~CommandeFactory ( );

//------------------------------------------------------------------ PRIVE 

protected:

	CommandeFactory ( );
	// S'assure que personne n'essaiera de creer une instance de CommandeFactory

private:
	static bool traitementMove ( vector<string *> para, Commande ** laCommande,
			ObjetGeometrique * contexte, const string *requete );
	//Methode permettant de traiter le cas du MOVE. Verifie la validite de la
	// commande et le cas echeant cree la commande correspondante.
	//Renvoie vrai si la commande a ete cree faux sinon

	static bool traitementLoad ( vector<string *> para, Commande ** laCommande,
			ObjetGeometrique * contexte );
	//Methode permettant de traiter le cas du LOAD. Verifie la validite de la
	// commande et le cas echeant cree la commande correspondante.
	//Renvoie vrai si la commande a ete cree ET si cette commande est valide.
	// Une commande LOAD valide est une commande dont la lecture dans le
	// fichier s'est bien passe.
	//Retourne faux sinon.

	static bool traitementRect ( vector<string *> para, Commande ** laCommande,
			ObjetGeometrique * contexte, const string *requete );
	//Methode permettant de traiter le cas de la création du Rectangle.
	//Verifie la validite de la commande et le cas echeant cree la commande
	// correspondante.
	//Renvoie vrai si la commande a ete cree. faux sinon

	static bool traitementPoly ( vector<string *> para, Commande ** laCommande,
			ObjetGeometrique * contexte, const string *requete );
	//Methode permettant de traiter le cas de la création de la PolyLigne.
	//Verifie la validite de la commande et le cas echeant cree la commande
	// correspondante.
	//Renvoie vrai si la commande a ete cree. faux sinon

	static bool traitementCercle ( vector<string *> para, Commande ** laCommande,
			ObjetGeometrique * contexte, const string *requete );
	//Methode permettant de traiter le cas de la création du Cercle.
	//Verifie la validite de la commande et le cas echeant cree la commande
	// correspondante.
	//Renvoie vrai si la commande a ete cree. faux sinon

	static bool traitementLigne ( vector<string *> para, Commande ** laCommande,
			ObjetGeometrique * contexte, const string *requete );
	//Methode permettant de traiter le cas de la création du Rectangle.
	//Verifie la validite de la commande et le cas echeant cree la commande
	// correspondante.
	//Renvoie vrai si la commande a ete cree. faux sinon
};

//--------------------------- Autres définitions dépendantes de <CommandeFactory>

#endif // COMMANDEFACTORY_H_
