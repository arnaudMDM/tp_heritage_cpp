/*************************************************************************
                           CommandeCreationCercle  -  description
                             -------------------
    d�but                : 3 f�vr. 2012
    copyright            : (C) 2012 par Pitou
*************************************************************************/

//---------- Interface de la classe <CommandeCreationCercle> (fichier CommandeCreationCercle.h) ------
#if ! defined ( COMMANDECREATIONCERCLE_H_ )
#define COMMANDECREATIONCERCLE_H_

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
#include <string>
#include <queue>
//--------------------------------------------------- Interfaces utilis�es
#include "CommandeCreation.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <CommandeCreationCercle>
//
//
//------------------------------------------------------------------------ 

class CommandeCreationCercle : public CommandeCreation
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
//    CommandeCreationCercle & operator = ( const CommandeCreationCercle & unCommandeCreationCercle );
//    // Mode d'emploi :
//    //
//    // Contrat :
//    //
//
//
////-------------------------------------------- Constructeurs - destructeur
//    CommandeCreationCercle ( const CommandeCreationCercle & unCommandeCreationCercle );
//    // Mode d'emploi (constructeur de copie) :
//    //
//    // Contrat :
//    //

    CommandeCreationCercle (vector < string *> para, ObjetGeometrique *unContexte);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~CommandeCreationCercle ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- M�thodes prot�g�es

//----------------------------------------------------- Attributs prot�g�s
    int x1;
    int y1;
    int rayon;

};

//--------------------------- Autres d�finitions d�pendantes de <CommandeCreationCercle>

#endif // COMMANDECREATIONCERCLE_H_
