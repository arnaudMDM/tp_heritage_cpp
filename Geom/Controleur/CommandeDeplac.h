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

	void Execute();

	void Redo();

	void Undo();

//------------------------------------------------- Surcharge d'op�rateurs
    CommandeDeplac & operator = ( const CommandeDeplac & unCommandeDeplac );
	// Laiss� vide dans le fichier de r�alisation pour s'assurer du crash lors
	// d'appels implicites.

//-------------------------------------------- Constructeurs - destructeur
    CommandeDeplac ( const CommandeDeplac & unCommandeDeplac );
	// Laiss� vide dans le fichier de r�alisation pour s'assurer du crash lors
	// d'appels implicites.

    CommandeDeplac (vector <string *> para, ObjetGeometrique *unContexte, const string *requete);
	// Constructeur permettant d'initialiser les attributs d'instance en utilisant la list
	// pour r�cup�rer les �l�ments num�riques et la chaine de caract�res pour pr�parer
	// le message.
	// la validit� des donn�es numeriques ne sont pas verifiees dans le constructeur


    virtual ~CommandeDeplac ( );

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- M�thodes prot�g�es

//----------------------------------------------------- Attributs prot�g�s
    int deltaX;
    //
    int deltaY;
    //
    vector <EltGeometrique *> elementsDeplaces;
    //
};

//--------------------------- Autres d�finitions d�pendantes de <CommandeDeplac>

#endif // COMMANDEDEPLAC_H_
