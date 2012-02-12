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
#include <cstdlib>
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

void CommandeCreationPoly::execute()
{
	if(status)
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


CommandeCreationPoly::CommandeCreationPoly (vector < string *> para, ObjetGeometrique *unContexte, const string *requete):
		CommandeCreation(unContexte)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <CommandeCreationPoly>" << endl;
#endif
	vector<int> tempX;
	vector<int> tempY;

	bool correct(true);

	if((para.size() - NB_PARA_INVARIANT) % NB_PARA_PAR_POINT != 0)
    {
    	correct = false;
    }
    else
    {
		vector<string *>::iterator itX = para.begin() + 1;
		vector<string *>::iterator itY = para.begin() + 2;

		while (itX != para.end() && correct)
		{
			if(!IsInteger((*itY)->c_str()) || !IsInteger((*itX)->c_str()))
			{
				correct = false;
			}
			else
			{
				tempX.push_back(atoi((*itX)->c_str()));
				tempY.push_back(atoi((*itY)->c_str()));
			}

			itX += NB_PARA_PAR_POINT;
			itY += NB_PARA_PAR_POINT;
		}
    }

    if(correct)
    {
    	coordonneesX = tempX;
    	coordonneesY = tempY;
    	status = true;
    	texteCommande = OK + *requete;
    }
    else
    {
    	status = false;
    	texteCommande = ERREUR + *requete + CHAINE_PARA_INVALIDE;
    }

} //----- Fin de CommandeCreationPoly


CommandeCreationPoly::~CommandeCreationPoly ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CommandeCreationPoly>" << endl;
#endif
} //----- Fin de ~CommandeCreationPoly


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

