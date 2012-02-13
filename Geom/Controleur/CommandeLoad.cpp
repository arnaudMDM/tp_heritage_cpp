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
#include "Controleur.h"
//------------------------------------------------------------- Constantes
static const unsigned int MAXSIZE = 20;
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type CommandeLoad::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

bool CommandeLoad::IsOk()
{
	return statusLecture;
}

void CommandeLoad::Execute ( )
{
	for(vector <Commande *>::iterator it = commandesCreation.begin(); it != commandesCreation.end(); it++)
	{
		(*it)->Execute();
	}
}

void CommandeLoad::Undo ( )
{
	for(vector <Commande *>::iterator it = commandesCreation.begin(); it != commandesCreation.end(); it++)
	{
		(*it)->Undo();
	}
}

void CommandeLoad::Redo ( )
{
	for(vector <Commande *>::iterator it = commandesCreation.begin(); it != commandesCreation.end(); it++)
	{
		(*it)->Redo();
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
		ObjetGeometrique *unContexte) :
		Commande(unContexte), nomFichier(unNomFichier), statusLecture(true)
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
		fichier.open(nomFichier.c_str());

		while (fichier.getline(bufferDesc, MAXSIZE) && statusLecture)
		{
			if (*bufferDesc != Controleur::CAR_COMMENTAIRE)
			{
				uneRequete = new string(bufferDesc);

				DecomposerCommande(lesRequetes, uneRequete);

				statusLecture = CommandeFactory::GetCommande(lesRequetes,
						laCommande, contexte, uneRequete);


				lesCommandesCrees.push_back(*laCommande);
				lesRequetes.clear();
			}
		}
		fichier.close();

		if(statusLecture)
		{
			commandesCreation = lesCommandesCrees;
			texteCommande = OK + LOAD + nomFichier;
		}
		else
		{
			texteCommande = ERREUR + LOAD + nomFichier;
		}
	}
	catch (ifstream::failure &e)
	{
		texteCommande = ERREUR + LOAD + nomFichier;
		statusLecture = false;
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

