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
// Cette Interface est la m�re de la hi�rarchie CommandeXXX dont le but est
// d'impl�menter le design pattern <code>Commande</code>. Elle permet de
// l'execution, le "undo" et le "redo" des commandes h�ritant.
//
//------------------------------------------------------------------------ 

class Commande
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques

    string getTexteCommande();
    // Mode d'emploi :
    //
    // Contrat :
    //

	virtual void Execute() = 0;
    // Mode d'emploi :
    //	A impl�menter dans chaque sous-classe concr�te
	// Comportement correspondant � la premi�re ex�cution de la commande.
    // Contrat :
    //

	virtual void Undo() = 0;
    // Mode d'emploi :
    //	A impl�menter dans chaque sous-classe concr�te
	// Remet le mod�le dans l'�tat pr�c�dent l'ex�cution de la m�thode
	// Execute()
    // Contrat : doit �tre appel� apr�s un Execute()
    //

	virtual void Redo() = 0;
    // Mode d'emploi :
    //	A impl�menter dans chaque sous-classe concr�te
	// remet le mod�le dans l'�tat correspondant � celui apr�s une ex�cution
	// de la m�thode Execute()
    // Contrat : doit �tre appel� apr�s un Undo()
    //

//------------------------------------------------- Surcharge d'op�rateurs
    Commande & operator = ( const Commande & unCommande );
    // Laiss� vide dans le fichier de r�alisation pour s'assurer du crash lors
    // d'appels implicites.


//-------------------------------------------- Constructeurs - destructeur
    Commande ( const Commande & unCommande );
    // Laiss� vide dans le fichier de r�alisation pour s'assurer du crash lors
    // d'appels implicites.

    Commande (ObjetGeometrique *nouveauContexte);
    // Constructeur � 1 argument permettant d'initialiser l'attribut d'instance
    // contexte

    virtual ~Commande ( );

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- M�thodes prot�g�es

//----------------------------------------------------- Attributs prot�g�s
    ObjetGeometrique *contexte;
    // Le contexte dans lequel tous les �l�ments graphiques seront ajout�s
    // Contient �galement les �l�ments de status "selectionne"

    string texteCommande;
    // Le texte de la commande utilis� pour sa cr�ation.
};

//--------------------------- Autres d�finitions d�pendantes de <Commande>

#endif // COMMANDE_H_
