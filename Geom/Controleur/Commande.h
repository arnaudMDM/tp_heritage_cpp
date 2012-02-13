/*************************************************************************
                           Commande  -  description
                             -------------------
    d�but                : 27 janv. 2012
    copyright            : (C) 2012 par Pitou
*************************************************************************/

//---------- Interface de la classe <Commande> (fichier Commande.h) ------
#if ! defined ( COMMANDE_H_ )
#define COMMANDE_H_

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me

//--------------------------------------------------- Interfaces utilis�es
#include "../Modele/ObjetGeometrique.h"
#include <string>
//------------------------------------------------------------- Constantes 

static const string ERREUR = "ERR ";
static const string OK = "OK ";
//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <Commande>
//
//
//------------------------------------------------------------------------ 

class Commande
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
    //
    // Contrat :
    //

    string getTexteCommande();

	virtual void Execute() = 0;

	virtual void Undo() = 0;

	virtual void Redo() = 0;

//------------------------------------------------- Surcharge d'op�rateurs
    Commande & operator = ( const Commande & unCommande );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Commande ( const Commande & unCommande );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Commande (ObjetGeometrique *nouveauContexte);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Commande ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- M�thodes prot�g�es

//----------------------------------------------------- Attributs prot�g�s
    ObjetGeometrique *contexte;
    string texteCommande;
};

//--------------------------- Autres d�finitions d�pendantes de <Commande>

#endif // COMMANDE_H_
