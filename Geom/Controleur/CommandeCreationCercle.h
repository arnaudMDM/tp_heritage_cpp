/*************************************************************************
                           CommandeCreationCercle  -  description
                             -------------------
    début                : 3 févr. 2012
    copyright            : (C) 2012 par Pitou
*************************************************************************/

//---------- Interface de la classe <CommandeCreationCercle> (fichier CommandeCreationCercle.h) ------
#if ! defined ( COMMANDECREATIONCERCLE_H_ )
#define COMMANDECREATIONCERCLE_H_

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <string>
#include <queue>
//--------------------------------------------------- Interfaces utilisées
#include "CommandeCreation.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <CommandeCreationCercle>
// Classe concrète permettant de créer la commande correspondant à la
// création d'un cercle.
//
//------------------------------------------------------------------------ 

class CommandeCreationCercle : public CommandeCreation
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	void Execute();
	// Crée une nouvelle instance de Cercle et l'ajoute au contexte

//------------------------------------------------- Surcharge d'opérateurs
    CommandeCreationCercle & operator = ( const CommandeCreationCercle & unCommandeCreationCercle );
    // Laissé vide dans le fichier de réalisation pour s'assurer du crash lors
    // d'appels implicites.

////-------------------------------------------- Constructeurs - destructeur
    CommandeCreationCercle ( const CommandeCreationCercle & unCommandeCreationCercle );
    // Laissé vide dans le fichier de réalisation pour s'assurer du crash lors
    // d'appels implicites.

    CommandeCreationCercle (vector < string *> para, ObjetGeometrique *unContexte, const string *requete);
    // Constructeur permettant d'initialiser les attributs d'instance en utilisant la list
    // pour récupérer les éléments numériques et la chaine de caractères pour préparer
    // le message.
    // la validité des données numeriques ne sont pas verifiees dans le constructeur

    virtual ~CommandeCreationCercle ( );


//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    int x1;
    //abscisse du centre du cercle

    int y1;
    //ordonnée du centre du cercle

    int rayon;
    //rayon du cercle
};

//--------------------------- Autres définitions dépendantes de <CommandeCreationCercle>

#endif // COMMANDECREATIONCERCLE_H_
