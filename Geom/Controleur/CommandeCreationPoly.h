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
//
//
//------------------------------------------------------------------------ 

class CommandeCreationPoly: public CommandeCreation
{
public:

	void Execute();

	CommandeCreationPoly & operator = (
			const CommandeCreationPoly & unCommandeCreationPoly );


	CommandeCreationPoly (
			const CommandeCreationPoly & unCommandeCreationPoly );


	CommandeCreationPoly (vector < int> abscisses, vector <int> ordonnees, ObjetGeometrique *unContexte,
			const string *requete );

	virtual ~CommandeCreationPoly ( );


protected:
	vector<int> coordonneesX;
	vector<int> coordonneesY;

};

//--------------------------- Autres d�finitions d�pendantes de <CommandeCreationPoly>

#endif // COMMANDECREATIONPOLY_H_
