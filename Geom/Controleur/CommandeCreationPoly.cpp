/*************************************************************************
 CommandeCreationPoly  -  description
 -------------------
 d�but                : 12 f�vr. 2012
 copyright            : (C) 2012 par Pitou
 *************************************************************************/

//---------- R�alisation de la classe <CommandeCreationPoly> (fichier CommandeCreationPoly.cpp) -------
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>
//------------------------------------------------------ Include personnel
#include "CommandeCreationPoly.h"
#include "../Modele/Service.h"
#include "../Modele/PolyLigne.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
// type CommandeCreationPoly::M�thode ( liste des param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode

void CommandeCreationPoly::Execute ( )
{
	if (status)
	{
		element = new PolyLigne(coordonneesX, coordonneesY);
		contexte->AjouterEltGeom(element);
	}
}

//------------------------------------------------- Surcharge d'op�rateurs
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

//----------------------------------------------------- M�thodes prot�g�es

