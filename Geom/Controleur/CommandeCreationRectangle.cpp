/*************************************************************************
 CommandeCreationRectangle  -  description
 -------------------
 début                : 12 févr. 2012
 copyright            : (C) 2012 par Pitou
 *************************************************************************/

//---------- Réalisation de la classe <CommandeCreationRectangle> (fichier CommandeCreationRectangle.cpp) -------
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstdlib>
//------------------------------------------------------ Include personnel
#include "CommandeCreationRectangle.h"
#include "../Modele/Rectangle.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void CommandeCreationRectangle::Execute ( )
{
	element = new Rectangle ( x1, y1, x2, y2 );
	contexte->AjouterEltGeom ( element );
	selectionElt ( );
} //----- Fin de Execute

//------------------------------------------------- Surcharge d'opérateurs

////-------------------------------------------- Constructeurs - destructeur

CommandeCreationRectangle::CommandeCreationRectangle ( vector<string *> para,
        ObjetGeometrique *unContexte, const string *requete ) :
		CommandeCreation ( unContexte )
{
#ifdef MAP
	cout << "Appel au constructeur de <CommandeCreationRectangle>" << endl;
#endif

	x1 = atoi ( (para.at ( 1 ))->c_str ( ) );

	y1 = atoi ( (para.at ( 2 ))->c_str ( ) );

	x2 = atoi ( (para.at ( 3 ))->c_str ( ) );

	y2 = atoi ( (para.at ( 4 ))->c_str ( ) );

	texteCommande = OK + *requete;

} //----- Fin de CommandeCreationRectangle

CommandeCreationRectangle::~CommandeCreationRectangle ( )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <CommandeCreationRectangle>" << endl;
#endif
} //----- Fin de ~CommandeCreationRectangle

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

