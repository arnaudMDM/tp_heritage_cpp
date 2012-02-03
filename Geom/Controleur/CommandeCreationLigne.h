/*************************************************************************
                           CommandeCreationLigne  -  description
                             -------------------
    d�but                : 3 f�vr. 2012
    copyright            : (C) 2012 par Pitou
*************************************************************************/

//---------- Interface de la classe <CommandeCreationLigne> (fichier CommandeCreationLigne.h) ------
#if ! defined ( COMMANDECREATIONLIGNE_H_ )
#define COMMANDECREATIONLIGNE_H_

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me

//--------------------------------------------------- Interfaces utilis�es
#include "CommandeCreation.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <CommandeCreationLigne>
//
//
//------------------------------------------------------------------------ 

class CommandeCreationLigne : public CommandeCreation
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
    CommandeCreationLigne & operator = ( const CommandeCreationLigne & unCommandeCreationLigne );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    CommandeCreationLigne ( const CommandeCreationLigne & unCommandeCreationLigne );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    CommandeCreationLigne ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~CommandeCreationLigne ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- M�thodes prot�g�es

//----------------------------------------------------- Attributs prot�g�s

};

//--------------------------- Autres d�finitions d�pendantes de <CommandeCreationLigne>

#endif // COMMANDECREATIONLIGNE_H_
