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
//
//
//------------------------------------------------------------------------ 

class CommandeCreation : public Commande
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
    // type M�thode ( liste des param�tres );
    // Mode d'emploi :
    //
    // Contrat :
    //
	virtual void Execute() = 0;

	virtual void Undo();

	virtual void Redo();
//------------------------------------------------- Surcharge d'op�rateurs
//    CommandeCreation & operator = ( const CommandeCreation & unCommandeCreation );
//    // Mode d'emploi :
//    //
//    // Contrat :
//    //
//
//
////-------------------------------------------- Constructeurs - destructeur
//    CommandeCreation ( const CommandeCreation & unCommandeCreation );
//    // Mode d'emploi (constructeur de copie) :
//    //
//    // Contrat :
//    //

    CommandeCreation (ObjetGeometrique *unContexte);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~CommandeCreation ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- M�thodes prot�g�es

    void selectionElt();
//----------------------------------------------------- Attributs prot�g�s

    EltGeometrique *element;
};

//--------------------------- Autres d�finitions d�pendantes de <CommandeCreation>

#endif // COMMANDECREATION_H_
