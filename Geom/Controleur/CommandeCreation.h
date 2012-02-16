/*************************************************************************
                           CommandeCreation  -  description
                             -------------------
    d�but                : 27 janv. 2012
    copyright            : (C) 2012 par Pitou
*************************************************************************/

//---------- Interface de la classe <CommandeCreation> (fichier CommandeCreation.h) ------
#if ! defined ( COMMANDECREATION_H_ )
#define COMMANDECREATION_H_

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me

//--------------------------------------------------- Interfaces utilis�es
#include "../Modele/EltGeometrique.h"
#include "../Modele/Service.h"
#include "Commande.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <CommandeCreation>
// Cette classe h�rite de Commande et permet de cr�er des objets �
// attacher au mod�le. Impl�mente les m�thodes Undo() et Redo() et laisse
// le soin aux classes filles concr�tes d'impl�menter Execute().
//L'�l�ment nouvellement cr�� a le status "selectionne"
//
//------------------------------------------------------------------------ 

class CommandeCreation : public Commande
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
	virtual void Execute() = 0;

	virtual void Undo();
	// M�thode permettant de d�faire une action de cr�ation d'�l�ments dans le
	// contexte attribut.

	virtual void Redo();
	// M�thode permettant de refaire l'action de cr�ation annul� par l'appel �
	// Undo()

//------------------------------------------------- Surcharge d'op�rateurs
    CommandeCreation & operator = ( const CommandeCreation & unCommandeCreation );
    // Laiss� vide dans le fichier de r�alisation pour s'assurer du crash lors
    // d'appels implicites.

////-------------------------------------------- Constructeurs - destructeur
    CommandeCreation ( const CommandeCreation & unCommandeCreation );
    // Laiss� vide dans le fichier de r�alisation pour s'assurer du crash lors
    // d'appels implicites.

    CommandeCreation (ObjetGeometrique *unContexte);
    // Constructeur � 1 argument permettant d'initialiser l'attribut d'instance
    // contexte via l'appel au constructeur parent. l'attribut d'instance element
    // n'est pas valoris� ici mais lors de l'Execute()

    virtual ~CommandeCreation ( );

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- M�thodes prot�g�es

    void selectionElt();
    // M�thode permettant de s�lectionner l'attribut element au sein du contexte

//----------------------------------------------------- Attributs prot�g�s

    EltGeometrique *element;
    // L'�l�ment que CommandeCreation (pr�cisement ses filles concr�tes)
    // cr�e et ajoute au contexte.
};

//--------------------------- Autres d�finitions d�pendantes de <CommandeCreation>

#endif // COMMANDECREATION_H_
