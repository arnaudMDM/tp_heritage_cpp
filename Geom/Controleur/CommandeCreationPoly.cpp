/*************************************************************************
 CommandeCreationPoly  -  description
 -------------------
 début                : 12 févr. 2012
 copyright            : (C) 2012 par Pitou
 *************************************************************************/

//---------- Réalisation de la classe <CommandeCreationPoly> (fichier CommandeCreationPoly.cpp) -------
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
//------------------------------------------------------ Include personnel
#include "CommandeCreationPoly.h"
#include "../Modele/Service.h"
#include "../Modele/PolyLigne.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type CommandeCreationPoly::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void CommandeCreationPoly::Execute ( )
{
	if (status)
	{
		element = new PolyLigne(coordonneesX, coordonneesY);
		contexte->AjouterEltGeom(element);
	}
}

//------------------------------------------------- Surcharge d'opérateurs
//CommandeCreationPoly & CommandeCreationPoly::operator = ( const CommandeCreationPoly & unCommandeCreationPoly )
//// Algorithme :
////
//{
//} //----- Fin de operator =
//
//
////-------------------------------------------- Constructeurs - destructeur
//CommandeCreationPoly::CommandeCreationPoly ( const CommandeCreationPoly & unCommandeCreationPoly )
//// Algorithme :
////
//{
//#ifdef MAP
//    cout << "Appel au constructeur de copie de <CommandeCreationPoly>" << endl;
//#endif
//} //----- Fin de CommandeCreationPoly (constructeur de copie)

CommandeCreationPoly::CommandeCreationPoly ( vector<int> abscisses,
		vector<int> ordonnees, ObjetGeometrique *unContexte,
		const string *requete ) :
		CommandeCreation(unContexte), coordonneesX(abscisses), coordonneesY(
				ordonnees)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <CommandeCreationPoly>" << endl;
#endif
	texteCommande = OK + *requete;
}    //----- Fin de CommandeCreationPoly

CommandeCreationPoly::~CommandeCreationPoly ( )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <CommandeCreationPoly>" << endl;
#endif
}    //----- Fin de ~CommandeCreationPoly

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

