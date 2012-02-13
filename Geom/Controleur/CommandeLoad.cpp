/*************************************************************************
 CommandeLoad  -  description
 -------------------
 début                : 13 févr. 2012
 copyright            : (C) 2012 par Pitou
 *************************************************************************/

//---------- Réalisation de la classe <CommandeLoad> (fichier CommandeLoad.cpp) -------
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>
#include <sstream>
//------------------------------------------------------ Include personnel
#include "CommandeLoad.h"
#include "Decomposeur.h"
#include "CommandeFactory.h"

//------------------------------------------------------------- Constantes
static const unsigned int MAXSIZE = 20;
static const char CAR_COMMENTAIRE = '#';
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type CommandeLoad::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
void CommandeLoad::execute ( )
{
	for(vector <Commande *>::iterator it = commandesCreation.begin(); it != commandesCreation.end(); it++)
	{
		(*it)->execute();
	}
}

void CommandeLoad::undo ( )
{
	for(vector <Commande *>::iterator it = commandesCreation.begin(); it != commandesCreation.end(); it++)
	{
		(*it)->undo();
	}
}

void CommandeLoad::redo ( )
{
	for(vector <Commande *>::iterator it = commandesCreation.begin(); it != commandesCreation.end(); it++)
	{
		(*it)->redo();
	}
}

//------------------------------------------------- Surcharge d'opérateurs
//CommandeLoad & CommandeLoad::operator = ( const CommandeLoad & unCommandeLoad )
//// Algorithme :
////
//{
//} //----- Fin de operator =
//
//
////-------------------------------------------- Constructeurs - destructeur
//CommandeLoad::CommandeLoad ( const CommandeLoad & unCommandeLoad )
//// Algorithme :
////
//{
//#ifdef MAP
//    cout << "Appel au constructeur de copie de <CommandeLoad>" << endl;
//#endif
//} //----- Fin de CommandeLoad (constructeur de copie)

CommandeLoad::CommandeLoad ( const string &unNomFichier,
		ObjetGeometrique *unContexte, bool statusHistorique ) :
		Commande(unContexte, statusHistorique), nomFichier(unNomFichier)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <CommandeLoad>" << endl;
#endif

	ifstream fichier;
	char *bufferDesc = new char[MAXSIZE];
	vector<string *> lesRequetes;
	vector <Commande*> lesCommandesCrees;
	string *uneRequete = NULL;
	Commande **laCommande = new Commande *();

	fichier.exceptions(ifstream::badbit);

	try
	{
		bool statusCommande(true);

		fichier.open(nomFichier.c_str());

		while (fichier.getline(bufferDesc, MAXSIZE) && statusCommande)
		{
			if (*bufferDesc != CAR_COMMENTAIRE)
			{
				uneRequete = new string(bufferDesc);

				DecomposerCommande(lesRequetes, uneRequete);

				statusCommande = CommandeFactory::GetCommande(lesRequetes,
						laCommande, contexte, uneRequete);


				lesCommandesCrees.push_back(*laCommande);
				lesRequetes.clear();
			}
		}
		fichier.close();

		if(statusCommande)
		{
			commandesCreation = lesCommandesCrees;
			texteCommande = OK + LOAD;
		}
		else
		{
			texteCommande = ERREUR + LOAD;
			status = false;
		}
	}
	catch (ifstream::failure &e)
	{
		texteCommande = ERREUR + LOAD;
		status = false;
	}

}    //----- Fin de CommandeLoad

CommandeLoad::~CommandeLoad ( )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <CommandeLoad>" << endl;
#endif
}    //----- Fin de ~CommandeLoad

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

