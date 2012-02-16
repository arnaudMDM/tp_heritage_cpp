/*************************************************************************
 CommandeFactory  -  description
 -------------------
 d�but                : 27 janv. 2012
 copyright            : (C) 2012 par Pitou
 *************************************************************************/

//---------- Interface de la classe <CommandeFactory> (fichier CommandeFactory.h) ------
#if ! defined ( COMMANDEFACTORY_H_ )
#define COMMANDEFACTORY_H_

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
#include <string>
#include <vector>
//--------------------------------------------------- Interfaces utilis�es
#include "Commande.h"
#include "../Service.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 
//------------------------------------------------------------------------ 
// R�le de la classe <CommandeFactory>
// Classe statique jouant le role d'une Fabrique de Commande.
//
//------------------------------------------------------------------------ 

class CommandeFactory
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
	static const string EXTENSION_FICHIER;
	//Chaine de caracteres d�finissant l'extension du fichier de sauvegarde

	static bool GetCommande ( vector<string *> para, Commande **laCommande,
			ObjetGeometrique *contexte, string *requete, TypeCommande unTypeCommande = ToutesCommandes);
	// Mode d'emploi : Retourne un booleen valant vrai si l'instance d'une commande
	// correspondant aux arguments pass�s en param�tre a ete cree.
	// Faux sinon.
	//
	// Contrat : Les cas de LIST, COUNT, UNDO, REDO, S X1, Y1, X2, Y2
	// sont trait�s en amont par le controleur.
	//

//------------------------------------------------- Surcharge d'op�rateurs
	CommandeFactory & operator = ( const CommandeFactory & unCommandeFactory );
	// Laiss� vide dans le fichier de r�alisation pour s'assurer du crash lors
	// d'appels implicites.

//-------------------------------------------- Constructeurs - destructeur
	CommandeFactory ( const CommandeFactory & unCommandeFactory );
	// Laiss� vide dans le fichier de r�alisation pour s'assurer du crash lors
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
	//Methode permettant de traiter le cas de la cr�ation du Rectangle.
	//Verifie la validite de la commande et le cas echeant cree la commande
	// correspondante.
	//Renvoie vrai si la commande a ete cree. faux sinon

	static bool traitementPoly ( vector<string *> para, Commande ** laCommande,
			ObjetGeometrique * contexte, const string *requete );
	//Methode permettant de traiter le cas de la cr�ation de la PolyLigne.
	//Verifie la validite de la commande et le cas echeant cree la commande
	// correspondante.
	//Renvoie vrai si la commande a ete cree. faux sinon

	static bool traitementCercle ( vector<string *> para, Commande ** laCommande,
			ObjetGeometrique * contexte, const string *requete );
	//Methode permettant de traiter le cas de la cr�ation du Cercle.
	//Verifie la validite de la commande et le cas echeant cree la commande
	// correspondante.
	//Renvoie vrai si la commande a ete cree. faux sinon

	static bool traitementLigne ( vector<string *> para, Commande ** laCommande,
			ObjetGeometrique * contexte, const string *requete );
	//Methode permettant de traiter le cas de la cr�ation du Rectangle.
	//Verifie la validite de la commande et le cas echeant cree la commande
	// correspondante.
	//Renvoie vrai si la commande a ete cree. faux sinon
};

//--------------------------- Autres d�finitions d�pendantes de <CommandeFactory>

#endif // COMMANDEFACTORY_H_
