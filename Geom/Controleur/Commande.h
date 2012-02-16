/*************************************************************************
                           Commande  -  description
                             -------------------
    début                : 27 janv. 2012
    copyright            : (C) 2012 par Pitou
*************************************************************************/

//---------- Interface de la classe <Commande> (fichier Commande.h) ------
#if ! defined ( COMMANDE_H_ )
#define COMMANDE_H_

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//--------------------------------------------------- Interfaces utilisées
#include "../Modele/ObjetGeometrique.h"
#include <string>
//------------------------------------------------------------- Constantes 

static const string ERREUR = "ERR ";
static const string OK = "OK ";
//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Commande>
// Cette Interface est la mère de la hiérarchie CommandeXXX dont le but est
// d'implémenter le design pattern <code>Commande</code>. Elle permet de
// l'execution, le "undo" et le "redo" des commandes héritant.
//
//------------------------------------------------------------------------ 

class Commande
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    string getTexteCommande();
    // Mode d'emploi :
    //
    // Contrat :
    //

	virtual void Execute() = 0;
    // Mode d'emploi :
    //	A implémenter dans chaque sous-classe concrète
	// Comportement correspondant à la première exécution de la commande.
    // Contrat :
    //

	virtual void Undo() = 0;
    // Mode d'emploi :
    //	A implémenter dans chaque sous-classe concrète
	// Remet le modèle dans l'état précédent l'exécution de la méthode
	// Execute()
    // Contrat : doit être appelé après un Execute()
    //

	virtual void Redo() = 0;
    // Mode d'emploi :
    //	A implémenter dans chaque sous-classe concrète
	// remet le modèle dans l'état correspondant à celui après une exécution
	// de la méthode Execute()
    // Contrat : doit être appelé après un Undo()
    //

//------------------------------------------------- Surcharge d'opérateurs
    Commande & operator = ( const Commande & unCommande );
    // Laissé vide dans le fichier de réalisation pour s'assurer du crash lors
    // d'appels implicites.


//-------------------------------------------- Constructeurs - destructeur
    Commande ( const Commande & unCommande );
    // Laissé vide dans le fichier de réalisation pour s'assurer du crash lors
    // d'appels implicites.

    Commande (ObjetGeometrique *nouveauContexte);
    // Constructeur à 1 argument permettant d'initialiser l'attribut d'instance
    // contexte

    virtual ~Commande ( );

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    ObjetGeometrique *contexte;
    // Le contexte dans lequel tous les éléments graphiques seront ajoutés
    // Contient également les éléments de status "selectionne"

    string texteCommande;
    // Le texte de la commande utilisé pour sa création.
};

//--------------------------- Autres définitions dépendantes de <Commande>

#endif // COMMANDE_H_
