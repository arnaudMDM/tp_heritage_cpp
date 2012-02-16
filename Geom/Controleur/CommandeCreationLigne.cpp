/*************************************************************************
 CommandeCreationLigne  -  description
 -------------------
 début                : 10 févr. 2012
 copyright            : (C) 2012 par arnaud
 *************************************************************************/

//---------- Réalisation de la classe <CommandeCreationLigne> (fichier CommandeCreationLigne.cpp) -------
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstdlib>
//------------------------------------------------------ Include personnel
#include "CommandeCreationLigne.h"
#include "../Service.h"
#include "../Modele/Ligne.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques
void CommandeCreationLigne::Execute ( )
{
	element = new Ligne ( x1, y1, x2, y2 );
	contexte->AjouterEltGeom ( element );
	selectionElt ( );
}
//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

CommandeCreationLigne::CommandeCreationLigne ( vector<string *> para,
        ObjetGeometrique *leContexte, const string *requete ) :
		CommandeCreation ( leContexte )
{
#ifdef MAP
	cout << "Appel au constructeur de <CommandeCreationLigne>" << endl;
#endif

	x1 = atoi ( para.at ( 1 )->c_str ( ) );
	y1 = atoi ( para.at ( 2 )->c_str ( ) );
	x2 = atoi ( para.at ( 3 )->c_str ( ) );
	y2 = atoi ( para.at ( 4 )->c_str ( ) );

	texteCommande = OK + *requete;

} //----- Fin de CommandeCreationLigne

CommandeCreationLigne::~CommandeCreationLigne ( )
{
#ifdef MAP
	cout << "Appel au destructeur de <CommandeCreationLigne>" << endl;
#endif
} //----- Fin de ~CommandeCreationLigne

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
