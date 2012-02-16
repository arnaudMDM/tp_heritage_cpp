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
// Classe concr�te permettant de cr�er la commande correspondant � la
// cr�ation d'un cercle.
//
//------------------------------------------------------------------------ 

class CommandeCreationCercle : public CommandeCreation
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
	void Execute();
	// Cr�e une nouvelle instance de Cercle et l'ajoute au contexte

//------------------------------------------------- Surcharge d'op�rateurs
    CommandeCreationCercle & operator = ( const CommandeCreationCercle & unCommandeCreationCercle );
    // Laiss� vide dans le fichier de r�alisation pour s'assurer du crash lors
    // d'appels implicites.

////-------------------------------------------- Constructeurs - destructeur
    CommandeCreationCercle ( const CommandeCreationCercle & unCommandeCreationCercle );
    // Laiss� vide dans le fichier de r�alisation pour s'assurer du crash lors
    // d'appels implicites.

    CommandeCreationCercle (vector < string *> para, ObjetGeometrique *unContexte, const string *requete);
    // Constructeur permettant d'initialiser les attributs d'instance en utilisant la list
    // pour r�cup�rer les �l�ments num�riques et la chaine de caract�res pour pr�parer
    // le message.
    // la validit� des donn�es numeriques ne sont pas verifiees dans le constructeur

    virtual ~CommandeCreationCercle ( );


//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- M�thodes prot�g�es

//----------------------------------------------------- Attributs prot�g�s
    int x1;
    //abscisse du centre du cercle

    int y1;
    //ordonn�e du centre du cercle

    int rayon;
    //rayon du cercle
};

//--------------------------- Autres d�finitions d�pendantes de <CommandeCreationCercle>

#endif // COMMANDECREATIONCERCLE_H_
