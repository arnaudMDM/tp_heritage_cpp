/*************************************************************************
 CommandeCreationPoly  -  description
 -------------------
 d�but                : 3 f�vr. 2012
 copyright            : (C) 2012 par Pitou
 *************************************************************************/

//---------- Interface de la classe <CommandeCreationPoly> (fichier CommandeCreationPoly.h) ------
#if ! defined ( COMMANDECREATIONPOLY_H_ )
#define COMMANDECREATIONPOLY_H_

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me

//--------------------------------------------------- Interfaces utilis�es
#include "CommandeCreation.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <CommandeCreationPoly>
// Classe concr�te permettant de cr�er la commande correspondant � la
// cr�ation d'une PolyLigne.
//------------------------------------------------------------------------ 

class CommandeCreationPoly: public CommandeCreation {
public:

	void Execute();
	// Cr�e une nouvelle instance de PolyLigne et l'ajoute au contexte

	CommandeCreationPoly & operator =(
			const CommandeCreationPoly & unCommandeCreationPoly);
	// Laiss� vide dans le fichier de r�alisation pour s'assurer du crash lors
	// d'appels implicites.

	CommandeCreationPoly(const CommandeCreationPoly & unCommandeCreationPoly);
	// Laiss� vide dans le fichier de r�alisation pour s'assurer du crash lors
	// d'appels implicites.

	CommandeCreationPoly(vector<int> abscisses, vector<int> ordonnees,
			ObjetGeometrique *unContexte, const string *requete);
	// Constructeur permettant d'initialiser les attributs d'instance en utilisant la list
	// pour r�cup�rer les �l�ments num�riques et la chaine de caract�res pour pr�parer
	// le message.
	// la validit� des donn�es numeriques ne sont pas verifiees dans le constructeur


	virtual ~CommandeCreationPoly();

protected:
	vector<int> coordonneesX;
	//Vector des abscisses des points de la PolyLigne
	vector<int> coordonneesY;
	//Vector des ordonnees des points de la PolyLigne
};

//--------------------------- Autres d�finitions d�pendantes de <CommandeCreationPoly>

#endif // COMMANDECREATIONPOLY_H_
