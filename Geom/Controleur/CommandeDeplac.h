/*************************************************************************
                           CommandeDeplac  -  description
                             -------------------
    d�but                : 12 f�vr. 2012
    copyright            : (C) 2012 par Pitou
*************************************************************************/

//---------- Interface de la classe <CommandeDeplac> (fichier CommandeDeplac.h) ------
#if ! defined ( COMMANDEDEPLAC_H_ )
#define COMMANDEDEPLAC_H_

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me

//--------------------------------------------------- Interfaces utilis�es
#include "Commande.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <CommandeDeplac>
//
//
//------------------------------------------------------------------------ 

class CommandeDeplac : public Commande
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
    // type M�thode ( liste des param�tres );
    // Mode d'emploi :
    //
    // Contrat :
    //

	void Execute();

	void Redo();

	void Undo();

//------------------------------------------------- Surcharge d'op�rateurs
    CommandeDeplac & operator = ( const CommandeDeplac & unCommandeDeplac );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    CommandeDeplac ( const CommandeDeplac & unCommandeDeplac );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    CommandeDeplac (vector <string *> para, ObjetGeometrique *unContexte, bool unStatus = true );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~CommandeDeplac ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- M�thodes prot�g�es

//----------------------------------------------------- Attributs prot�g�s
    int deltaX;
    int deltaY;
    vector <EltGeometrique *> elementsDeplaces;
};

//--------------------------- Autres d�finitions d�pendantes de <CommandeDeplac>

#endif // COMMANDEDEPLAC_H_
