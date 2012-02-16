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
#include <queue>
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <CommandeCreationLigne>
// Classe concr�te permettant de cr�er la commande correspondant � la
// cr�ation d'une Ligne.
//------------------------------------------------------------------------ 

class CommandeCreationLigne: public CommandeCreation {
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques

	void Execute();
	// Cr�e une nouvelle instance de Ligne et l'ajoute au contexte

	//------------------------------------------------- Surcharge d'op�rateurs
	CommandeCreationLigne & operator =(
			const CommandeCreationLigne & unCommandeCreationLigne);
	// Laiss� vide dans le fichier de r�alisation pour s'assurer du crash lors
	// d'appels implicites.


	//-------------------------------------------- Constructeurs - destructeur
			CommandeCreationLigne(
					const CommandeCreationLigne & unCommandeCreationLigne);
	// Laiss� vide dans le fichier de r�alisation pour s'assurer du crash lors
	// d'appels implicites.

	CommandeCreationLigne(vector<string *> para, ObjetGeometrique *leContexte,
			const string *requete);
	// Constructeur permettant d'initialiser les attributs d'instance en utilisant la list
	// pour r�cup�rer les �l�ments num�riques et la chaine de caract�res pour pr�parer
	// le message.
	// la validit� des donn�es numeriques ne sont pas verifiees dans le constructeur

	virtual ~CommandeCreationLigne();

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- M�thodes prot�g�es

	//----------------------------------------------------- Attributs prot�g�s
	int x1;
	//abscisse du 1er point
	int x2;
	//abscisse du 2eme point
	int y1;
	//ordonnee du 1er point
	int y2;
	//ordonnee du 2eme point

};

//--------------------------- Autres d�finitions d�pendantes de <CommandeCreationLigne>

#endif // COMMANDECREATIONLIGNE_H_
