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

void CommandeCreationPoly::Execute()
{
	element = new PolyLigne(coordonneesX, coordonneesY);
	contexte->AjouterEltGeom(element);
	selectionElt();
}//----- Fin de Execute

//------------------------------------------------- Surcharge d'opérateurs

////-------------------------------------------- Constructeurs - destructeur

CommandeCreationPoly::CommandeCreationPoly(vector<int> abscisses,
		vector<int> ordonnees, ObjetGeometrique *unContexte,
		const string *requete) :
	CommandeCreation(unContexte), coordonneesX(abscisses), coordonneesY(
			ordonnees)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <CommandeCreationPoly>" << endl;
#endif
	texteCommande = OK + *requete;
} //----- Fin de CommandeCreationPoly

CommandeCreationPoly::~CommandeCreationPoly()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <CommandeCreationPoly>" << endl;
#endif
} //----- Fin de ~CommandeCreationPoly

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

