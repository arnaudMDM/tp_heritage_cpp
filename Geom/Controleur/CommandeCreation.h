/*************************************************************************
                           CommandeCreation  -  description
                             -------------------
    début                : 27 janv. 2012
    copyright            : (C) 2012 par Pitou
*************************************************************************/

//---------- Interface de la classe <CommandeCreation> (fichier CommandeCreation.h) ------
#if ! defined ( COMMANDECREATION_H_ )
#define COMMANDECREATION_H_

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <CommandeCreation>
//
//
//------------------------------------------------------------------------ 

class CommandeCreation
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

	CommandeCreation(EltGeometrique(*f)());

//------------------------------------------------- Surcharge d'opérateurs
    CommandeCreation & operator = ( const CommandeCreation & unCommandeCreation );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    CommandeCreation ( const CommandeCreation & unCommandeCreation );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    CommandeCreation ( );
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
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
EltGeometrique (pointeurFonction)(int,int,int...);

};

//--------------------------- Autres définitions dépendantes de <CommandeCreation>

#endif // COMMANDECREATION_H_
