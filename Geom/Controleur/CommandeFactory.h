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

//--------------------------------------------------- Interfaces utilis�es
#include "Commande.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <CommandeFactory>
//
//
//------------------------------------------------------------------------ 

class CommandeFactory
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
    // type M�thode ( liste des param�tres );
    // Mode d'emploi :
    //
    // Contrat :
    //

	static bool GetCommande(char * argv[], Commande* laCommande, ObjetGeometrique *contexte);
    // Mode d'emploi : Retourne l'instance d'une commande
	// correspondant aux arguments pass�s en param�tre.
    //
    // Contrat : Les cas de LIST, COUNT, UNDO, REDO, S X1, Y1, X2, Y2
	// sont trait�s en amont par le controleur.
    //

//------------------------------------------------- Surcharge d'op�rateurs
    CommandeFactory & operator = ( const CommandeFactory & unCommandeFactory );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    CommandeFactory ( const CommandeFactory & unCommandeFactory );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    CommandeFactory ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~CommandeFactory ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- M�thodes prot�g�es

//----------------------------------------------------- Attributs prot�g�s

};

//--------------------------- Autres d�finitions d�pendantes de <CommandeFactory>

#endif // COMMANDEFACTORY_H_
