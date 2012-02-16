/*************************************************************************
                           CommandeCreation  -  description
                             -------------------
    dï¿½but                : 27 janv. 2012
    copyright            : (C) 2012 par Pitou
*************************************************************************/

//---------- Interface de la classe <CommandeCreation> (fichier CommandeCreation.h) ------
#if ! defined ( COMMANDECREATION_H_ )
#define COMMANDECREATION_H_

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include systï¿½me

//--------------------------------------------------- Interfaces utilisï¿½es
#include "../Modele/EltGeometrique.h"
#include "../Modele/Service.h"
#include "Commande.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rï¿½le de la classe <CommandeCreation>
// Cette classe hérite de Commande et permet de créer des objets à
// attacher au modèle. Implémente les méthodes Undo() et Redo() et laisse
// le soin aux classes filles concrètes d'implémenter Execute().
//L'élément nouvellement créé a le status "selectionne"
//
//------------------------------------------------------------------------ 

class CommandeCreation : public Commande
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Mï¿½thodes publiques
	virtual void Execute() = 0;

	virtual void Undo();
	// Méthode permettant de défaire une action de création d'éléments dans le
	// contexte attribut.

	virtual void Redo();
	// Méthode permettant de refaire l'action de création annulé par l'appel à
	// Undo()

//------------------------------------------------- Surcharge d'opï¿½rateurs
    CommandeCreation & operator = ( const CommandeCreation & unCommandeCreation );
    // Laissé vide dans le fichier de réalisation pour s'assurer du crash lors
    // d'appels implicites.

////-------------------------------------------- Constructeurs - destructeur
    CommandeCreation ( const CommandeCreation & unCommandeCreation );
    // Laissé vide dans le fichier de réalisation pour s'assurer du crash lors
    // d'appels implicites.

    CommandeCreation (ObjetGeometrique *unContexte);
    // Constructeur à 1 argument permettant d'initialiser l'attribut d'instance
    // contexte via l'appel au constructeur parent. l'attribut d'instance element
    // n'est pas valorisé ici mais lors de l'Execute()

    virtual ~CommandeCreation ( );

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Mï¿½thodes protï¿½gï¿½es

    void selectionElt();
    // Méthode permettant de sélectionner l'attribut element au sein du contexte

//----------------------------------------------------- Attributs protï¿½gï¿½s

    EltGeometrique *element;
    // L'élément que CommandeCreation (précisement ses filles concrètes)
    // crée et ajoute au contexte.
};

//--------------------------- Autres dï¿½finitions dï¿½pendantes de <CommandeCreation>

#endif // COMMANDECREATION_H_
