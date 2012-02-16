/*************************************************************************
 CommandeCreationPoly  -  description
 -------------------
 début                : 3 févr. 2012
 copyright            : (C) 2012 par Pitou
 *************************************************************************/

//---------- Interface de la classe <CommandeCreationPoly> (fichier CommandeCreationPoly.h) ------
#if ! defined ( COMMANDECREATIONPOLY_H_ )
#define COMMANDECREATIONPOLY_H_

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//--------------------------------------------------- Interfaces utilisées
#include "CommandeCreation.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <CommandeCreationPoly>
// Classe concrète permettant de créer la commande correspondant à la
// création d'une PolyLigne.
//------------------------------------------------------------------------ 

class CommandeCreationPoly: public CommandeCreation {
public:

	void Execute();
	// Crée une nouvelle instance de PolyLigne et l'ajoute au contexte

	CommandeCreationPoly & operator =(
			const CommandeCreationPoly & unCommandeCreationPoly);
	// Laissé vide dans le fichier de réalisation pour s'assurer du crash lors
	// d'appels implicites.

	CommandeCreationPoly(const CommandeCreationPoly & unCommandeCreationPoly);
	// Laissé vide dans le fichier de réalisation pour s'assurer du crash lors
	// d'appels implicites.

	CommandeCreationPoly(vector<int> abscisses, vector<int> ordonnees,
			ObjetGeometrique *unContexte, const string *requete);
	// Constructeur permettant d'initialiser les attributs d'instance en utilisant la list
	// pour récupérer les éléments numériques et la chaine de caractères pour préparer
	// le message.
	// la validité des données numeriques ne sont pas verifiees dans le constructeur


	virtual ~CommandeCreationPoly();

protected:
	vector<int> coordonneesX;
	//Vector des abscisses des points de la PolyLigne
	vector<int> coordonneesY;
	//Vector des ordonnees des points de la PolyLigne
};

//--------------------------- Autres définitions dépendantes de <CommandeCreationPoly>

#endif // COMMANDECREATIONPOLY_H_
