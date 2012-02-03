/*************************************************************************
                           CommandeCreationPoly  -  description
                             -------------------
    d�but                : 3 f�vr. 2012
    copyright            : (C) 2012 par Pitou
*************************************************************************/

//---------- Interface de la classe <CommandeCreationPoly> (fichier CommandeCreationPoly.h) ------
#if ! defined ( COMMANDECREATIONPOLY_H_ )
#define COMMANDECREATIONPOLY_H_

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me

//--------------------------------------------------- Interfaces utilis�es
#include "CommandeCreation.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <CommandeCreationPoly>
//
//
//------------------------------------------------------------------------ 

class CommandeCreationPoly : public CommandeCreation
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
    // type M�thode ( liste des param�tres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'op�rateurs
    CommandeCreationPoly & operator = ( const CommandeCreationPoly & unCommandeCreationPoly );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    CommandeCreationPoly ( const CommandeCreationPoly & unCommandeCreationPoly );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    CommandeCreationPoly ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~CommandeCreationPoly ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- M�thodes prot�g�es

//----------------------------------------------------- Attributs prot�g�s

};

//--------------------------- Autres d�finitions d�pendantes de <CommandeCreationPoly>

#endif // COMMANDECREATIONPOLY_H_
