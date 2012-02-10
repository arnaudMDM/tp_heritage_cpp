/*************************************************************************
                           CommandeDirect  -  description
                             -------------------
    d�but                : 10 f�vr. 2012
    copyright            : (C) 2012 par Pitou
*************************************************************************/

//---------- Interface de la classe <CommandeDirect> (fichier CommandeDirect.h) ------
#if ! defined ( COMMANDEDIRECT_H_ )
#define COMMANDEDIRECT_H_

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me

//--------------------------------------------------- Interfaces utilis�es
#include "Commande.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <CommandeDirect>
//
//
//------------------------------------------------------------------------ 

class CommandeDirect : public Commande
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
    // type M�thode ( liste des param�tres );
    // Mode d'emploi :
    //
    // Contrat :
    //
	void execute();

	void undo();

	void redo();

//------------------------------------------------- Surcharge d'op�rateurs
    CommandeDirect & operator = ( const CommandeDirect & unCommandeDirect );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
//    CommandeDirect ( const CommandeDirect & unCommandeDirect );
//    // Mode d'emploi (constructeur de copie) :
//    //
//    // Contrat :
//    //

    CommandeDirect (ObjetGeometrique * nouveauContexte, void (*)() );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~CommandeDirect ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- M�thodes prot�g�es

//----------------------------------------------------- Attributs prot�g�s
    void (*fct_commande)();
};

//--------------------------- Autres d�finitions d�pendantes de <CommandeDirect>

#endif // COMMANDEDIRECT_H_
