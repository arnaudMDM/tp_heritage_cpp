/*************************************************************************
                           CommandeSuppression  -  description
                             -------------------
    d�but                : 12 f�vr. 2012
    copyright            : (C) 2012 par Pitou
*************************************************************************/

//---------- Interface de la classe <CommandeSuppression> (fichier CommandeSuppression.h) ------
#if ! defined ( COMMANDESUPPRESSION_H_ )
#define COMMANDESUPPRESSION_H_

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me

//--------------------------------------------------- Interfaces utilis�es
#include "Commande.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <CommandeSuppression>
//
//
//------------------------------------------------------------------------ 

class CommandeSuppression : public Commande
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
    // type M�thode ( liste des param�tres );
    // Mode d'emploi :
    //
    // Contrat :
    //
	enum typeEtatSuppression {DELETE, CLEAR};

	void execute();

	void redo();

	void undo();

//------------------------------------------------- Surcharge d'op�rateurs
    CommandeSuppression & operator = ( const CommandeSuppression & unCommandeSuppression );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    CommandeSuppression ( const CommandeSuppression & unCommandeSuppression );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    CommandeSuppression (ObjetGeometrique *nouveauContexte,typeEtatSuppression, bool statusHistorique = true );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~CommandeSuppression ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- M�thodes prot�g�es

//----------------------------------------------------- Attributs prot�g�s
    vector<EltGeometrique *> elementsSupprimes;

    typeEtatSuppression etatSuppression;

};

//--------------------------- Autres d�finitions d�pendantes de <CommandeSuppression>

#endif // COMMANDESUPPRESSION_H_
