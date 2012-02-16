/*************************************************************************
 Controleur  -  description
 -------------------
 d�but                : 27 janv. 2012
 copyright            : (C) 2012 par Pitou
 *************************************************************************/

//---------- Interface de la classe <Controleur> (fichier Controleur.h) ------
#if ! defined ( CONTROLEUR_H_ )
#define CONTROLEUR_H_

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
#include <string>
#include <stack>
#include <vector>
//--------------------------------------------------- Interfaces utilis�es
#include "../Modele/ObjetGeometrique.h"
#include "Commande.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <Controleur>
// Controleur de l'application Geom permettant de gerer l'interaction entre
// l'utilisateur et le modele. Cette classe obtient les requetes de ce
// dernier et demande leurs realisations au sous-ensemble CommandeXXX.
// La partie Vue a ete internalise dans cette classe.
//------------------------------------------------------------------------ 

class Controleur
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
	void test();

	void TraitementCommande ( );
	// Mode d'emploi : methode principale permettant la recuperation et
	// la bonne execution de la commande.

	static const char CAR_COMMENTAIRE = '#';
	//Caractere de commentaire de l'application. Doit etre ignore dans tous
	//les traitements.

//------------------------------------------------- Surcharge d'op�rateurs
	Controleur & operator = ( const Controleur & unControleur );
	// Laiss� vide dans le fichier de r�alisation pour s'assurer du crash lors
	// d'appels implicites.

//-------------------------------------------- Constructeurs - destructeur
	Controleur ( const Controleur & unControleur );
	// Laiss� vide dans le fichier de r�alisation pour s'assurer du crash lors
	// d'appels implicites.

	Controleur ( );
	// Constructeur sans parametre permettant de preparer le controleur :
	// Creation d'un nouveau contexte d'execution.

	virtual ~Controleur ( );
	//Destructeur lib�rant la m�moire utilis�e par les pointeurs et les
	//conteneurs de pointeur

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- M�thodes prot�g�es

//----------------------------------------------------- Attributs prot�g�s
	bool quitter;
	//Permet de quitter la boucle principale de TraitementCommande() en cas
	//de valeur fausse.
	string requete;
	//Chaine de caractre contenant la requete courante de l'utilisateur
	vector<string *> parametres;
	//Liste de paramtres correspondant a la separation de la requete en
	//token (spearateur : espace)
	ObjetGeometrique * contexte;
	//Le contexte d'execution de l'application. Cet element contient tous
	//les elements present dans le modele.
	stack<Commande *> commandesExec;
	//Pile de commandes dont le status est execute.
	stack<Commande *> commandesHistorique;
	//Pile de commandes dont le status est undo.

private:

// Les methodes priv�es de cette classe retourne pour la plus part des
// chaines de caractres qui correspondent a la bonne ou mauvaise execution
// de la commande associee. il s'agit d'un retour a destination de l'utilisateur

	string defaire ( );
	// Methode permettant de traiter le cas du UNDO
	// Correspond � un appel a Undo() sur la tete de la
	// pile de commandes executees
	string refaire ( );
	// Methode permettant de traiter le cas du REDO
	// Correspond � un appel a Redo() sur la tete de la
	// pile de commandes undo-ees

	string save ( );
	// Methode permettant de traiter le cas du SAVE
	// Verifie la validite du fichier passe en argument
	// et le cas echeant le rempli par les descripteurs des
	// commandes de creation

	string selectionner ( );
	// Methode permettant de traiter le cas du S X X X X
	// Verifie que les arguments de la commande sont correctes
	// et le cas echeant realise la selection des elements

	void traitementCommande ( Commande *laCommande );
	// Methode permettant de traiter le cas des commandes necessittant
	// une historisation c'est a dire le cas ou le undo/redo est possible:
	// Appel a la fabrique.

	void vidagePara ( );
	//Permet de vider l'attribut parametres de tous ses elements
	// et de correctement desallouer la memoire.
};

//--------------------------- Autres d�finitions d�pendantes de <Controleur>

#endif // CONTROLEUR_H_
