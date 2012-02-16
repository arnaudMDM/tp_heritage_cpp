/*************************************************************************
 CommandeCreationRectangle  -  description
 -------------------
 d�but                : 3 f�vr. 2012
 copyright            : (C) 2012 par Pitou
 *************************************************************************/

//---------- Interface de la classe <CommandeCreationRectangle> (fichier CommandeCreationRectangle.h) ------
#if ! defined ( COMMANDECREATIONRECTANGLE_H_ )
#define COMMANDECREATIONRECTANGLE_H_

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me

//--------------------------------------------------- Interfaces utilis�es
#include "CommandeCreation.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <CommandeCreationRectangle>
// Classe concr�te permettant de cr�er la commande correspondant � la
// cr�ation d'un Rectangle.
//------------------------------------------------------------------------ 

class CommandeCreationRectangle : public CommandeCreation
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques

	void Execute ( );
	// Cr�e une nouvelle instance de Rectangle et l'ajoute au contexte

//------------------------------------------------- Surcharge d'op�rateurs
	CommandeCreationRectangle & operator = (
	        const CommandeCreationRectangle & unCommandeCreationRectangle );
	// Laiss� vide dans le fichier de r�alisation pour s'assurer du crash lors
	// d'appels implicites.

//-------------------------------------------- Constructeurs - destructeur
	CommandeCreationRectangle (
	        const CommandeCreationRectangle & unCommandeCreationRectangle );
	// Laiss� vide dans le fichier de r�alisation pour s'assurer du crash lors
	// d'appels implicites.

	CommandeCreationRectangle ( vector<string *> para,
	        ObjetGeometrique *unContexte, const string *requete );
	// Constructeur permettant d'initialiser les attributs d'instance en utilisant la list
	// pour r�cup�rer les �l�ments num�riques et la chaine de caract�res pour pr�parer
	// le message.
	// la validit� des donn�es numeriques ne sont pas verifiees dans le constructeur

	virtual ~CommandeCreationRectangle ( );

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

//--------------------------- Autres d�finitions d�pendantes de <CommandeCreationRectangle>

#endif // COMMANDECREATIONRECTANGLE_H_
