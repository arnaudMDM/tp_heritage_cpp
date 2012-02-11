/*************************************************************************
 CommandeCreationCercle  -  description
 -------------------
 début                : 3 févr. 2012
 copyright            : (C) 2012 par Pitou
 *************************************************************************/

//---------- Réalisation de la classe <CommandeCreationCercle> (fichier CommandeCreationCercle.cpp) -------
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
#include <cstdlib>
#include <vector>
//------------------------------------------------------ Include personnel
#include "CommandeCreationCercle.h"
#include "../Modele/Cercle.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type CommandeCreationCercle::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void CommandeCreationCercle::execute ( )
{
	if (status)
	{
		element = new Cercle(x1, y1, rayon);
		contexte->AjouterEltGeom(element);
	}
}

void CommandeCreationCercle::undo ( )
{
	if (status)
	{
		contexte->SupprimerEltParticulier(element);
		contexte->Deselectionner();
		cout << "Cet élément : " << element->Description()
				<< " vient d'etre dépilé" << endl;
	}
}

void CommandeCreationCercle::redo ( )
{
	if (status)
	{
		contexte->AjouterEltGeom(element);
		contexte->Deselectionner();
	}
}
//------------------------------------------------- Surcharge d'opérateurs
//CommandeCreationCercle & CommandeCreationCercle::operator = ( const CommandeCreationCercle & unCommandeCreationCercle )
//// Algorithme :
////
//{
//} //----- Fin de operator =
//
//
////-------------------------------------------- Constructeurs - destructeur
//CommandeCreationCercle::CommandeCreationCercle ( const CommandeCreationCercle & unCommandeCreationCercle )
//// Algorithme :
////
//{
//#ifdef MAP
//    cout << "Appel au constructeur de copie de <CommandeCreationCercle>" << endl;
//#endif
//} //----- Fin de CommandeCreationCercle (constructeur de copie)

CommandeCreationCercle::CommandeCreationCercle ( vector<string *> para, ObjetGeometrique *leContexte, string *requete ) :
		CommandeCreation(leContexte)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <CommandeCreationCercle>" << endl;
#endif


	if (para.size() == NB_PARAM_CREAT_CERCLE)
	{
		for(vector<string*>::iterator it = para.begin() ; it != para.end() ; it++)
		{
			if(!IsInteger(**it))
			{
				status = false;
			}
		}
		x1 = atoi((para.at(1))->c_str());

		y1 = atoi((para.at(2))->c_str());

		int rayonTemporaire;
		rayonTemporaire = atoi((para.at(3))->c_str());
		// Le rayon ne peut pas etre négatif

		rayon = atoi((para.at(3)->c_str()));

	}
	else
	{
		status = false;
	}

	if (!status)
	{
		texteCommande = ERREUR + *requete;
	}
	else
	{
		texteCommande = OK + *requete;
	}

} //----- Fin de CommandeCreationCercle

CommandeCreationCercle::~CommandeCreationCercle ( )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <CommandeCreationCercle>" << endl;
#endif
} //----- Fin de ~CommandeCreationCercle

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

