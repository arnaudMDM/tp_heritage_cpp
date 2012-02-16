/*************************************************************************
                           CommandeDeplac  -  description
                             -------------------
    début                : 12 févr. 2012
    copyright            : (C) 2012 par Pitou
*************************************************************************/

//---------- Interface de la classe <CommandeDeplac> (fichier CommandeDeplac.h) ------
#if ! defined ( COMMANDEDEPLAC_H_ )
#define COMMANDEDEPLAC_H_

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//--------------------------------------------------- Interfaces utilisées
#include "Commande.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <CommandeDeplac>
//Commande permettant de deplacer un ensemble d'ElementGeometrique. La valeur
// de deplacement est donne via 2 entiers - deplacement sur l'axe des
//abscisses et deplacement sur l'axe des ordonnees-
//
//------------------------------------------------------------------------ 

class CommandeDeplac : public Commande
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

	void Execute();
	//Recupere la liste des elements a deplacer (corresponds à ceux selectionnes)
	//et les translate.

	void Redo();
	//Redeplace les elements
	//doit etre execute apres un Undo()

	void Undo();
	//Annule le deplacement des elements.
	//Doit etre execute apres un Execute() ou un Redo()

//------------------------------------------------- Surcharge d'opérateurs
    CommandeDeplac & operator = ( const CommandeDeplac & unCommandeDeplac );
	// Laissé vide dans le fichier de réalisation pour s'assurer du crash lors
	// d'appels implicites.

//-------------------------------------------- Constructeurs - destructeur
    CommandeDeplac ( const CommandeDeplac & unCommandeDeplac );
	// Laissé vide dans le fichier de réalisation pour s'assurer du crash lors
	// d'appels implicites.

    CommandeDeplac (vector <string *> para, ObjetGeometrique *unContexte, const string *requete);
	// Constructeur permettant d'initialiser les attributs d'instance en utilisant la list
	// pour récupérer les éléments numériques et la chaine de caractères pour préparer
	// le message.
	// la validité des données numeriques ne sont pas verifiees dans le constructeur


    virtual ~CommandeDeplac ( );

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    int deltaX;
    //valeur de décalage voulu sur l'axe des abscisses
    int deltaY;
    //valeur de décalage voulu sur l'axe des ordonnees
    vector <EltGeometrique *> elementsDeplaces;
    //Liste de tous les éléments devant etre deplaces
};

//--------------------------- Autres définitions dépendantes de <CommandeDeplac>

#endif // COMMANDEDEPLAC_H_
