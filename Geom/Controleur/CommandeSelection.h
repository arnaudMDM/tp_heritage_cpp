/*************************************************************************
                           CommandeSelection  -  description
                             -------------------
    d�but                : 27 janv. 2012
    copyright            : (C) 2012 par Pitou
*************************************************************************/

//---------- Interface de la classe <CommandeSelection> (fichier CommandeSelection.h) ------
#if ! defined ( COMMANDESELECTION_H_ )
#define COMMANDESELECTION_H_

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me

//--------------------------------------------------- Interfaces utilis�es

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <CommandeSelection>
//
//
//------------------------------------------------------------------------ 

class CommandeSelection
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
    CommandeSelection & operator = ( const CommandeSelection & unCommandeSelection );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    CommandeSelection ( const CommandeSelection & unCommandeSelection );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    CommandeSelection ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~CommandeSelection ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- M�thodes prot�g�es

//----------------------------------------------------- Attributs prot�g�s

};

//--------------------------- Autres d�finitions d�pendantes de <CommandeSelection>

#endif // COMMANDESELECTION_H_
