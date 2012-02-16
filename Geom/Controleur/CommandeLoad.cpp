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
void CommandeLoad::Execute ( )
{
	for(vector <Commande *>::iterator it = commandesCreation.begin(); it != commandesCreation.end(); it++)
	{
		(*it)->Execute();
	}
	contexte->Deselectionner();
}//----- Fin de Execute

bool CommandeLoad::IsOk()
{
	return statusLecture;
}//----- Fin de IsOk

void CommandeLoad::Redo ( )
{
	for(vector <Commande *>::iterator it = commandesCreation.begin(); it != commandesCreation.end(); it++)
	{
		(*it)->Redo();
	}
}//----- Fin de Redo

void CommandeLoad::Undo ( )
{
	for(vector <Commande *>::iterator it = commandesCreation.begin(); it != commandesCreation.end(); it++)
	{
		(*it)->Undo();
	}
}//----- Fin de Undo

//------------------------------------------------- Surcharge d'opérateurs

////-------------------------------------------- Constructeurs - destructeur

CommandeLoad::CommandeLoad ( const string &unNomFichier,
		ObjetGeometrique *unContexte) :
		Commande(unContexte), nomFichier(unNomFichier), statusLecture(true)
// Algorithme :Ouverture du fichier et lecture de ce dernier afin d'en extraire
// les descripteurs de commande
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

	//Preparation du fichier : ce dernier lancera une exception si
	//le flag badbit est positionne
	fichier.exceptions(ifstream::badbit);

	try
	{
		fichier.open(nomFichier.c_str());

		while (fichier.getline(bufferDesc, MAXSIZE) && statusLecture)
		{
			//Pour chaque ligne presente du fichier, ignorance des commentaires et vide
			if ((*bufferDesc != Controleur::CAR_COMMENTAIRE) && (*bufferDesc != '\0'))
			{
				uneRequete = new string(bufferDesc);

				//Permet de briser uneRequete en token, range dans la liste
				DecomposerCommande(lesRequetes, uneRequete);

				//Recuperation de la commande correspondante, le booleen permet de savoir
				//si tout s'est bien passe
				statusLecture = CommandeFactory::GetCommande(lesRequetes,
						laCommande, contexte, uneRequete);

				lesCommandesCrees.push_back(*laCommande);

				// Suppression du contenu de la liste
				for(vector<string *>::iterator it = lesRequetes.begin(); it != lesRequetes.end(); it++)
				{
					delete *it;
				}
				lesRequetes.clear();
			}
		}
		fichier.close();

		//Permet de preparer le message de status de la commande
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
//		fichier.close();
		texteCommande = ERREUR + LOAD + nomFichier;
		statusLecture = false;

	}
	delete uneRequete;
}    //----- Fin de CommandeLoad

CommandeLoad::~CommandeLoad ( )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <CommandeLoad>" << endl;
#endif
	for(vector<Commande *>::iterator it = commandesCreation.begin(); it != commandesCreation.end(); it ++)
	{
		delete *it;
	}
	commandesCreation.clear();
}    //----- Fin de ~CommandeLoad

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

