/*************************************************************************
 Controleur  -  description
 -------------------
 début                : 27 janv. 2012
 copyright            : (C) 2012 par Pitou
 *************************************************************************/

//---------- Réalisation de la classe <Controleur> (fichier Controleur.cpp) -------
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <sstream>
#include <typeinfo>
#include <cstdlib>
#include <fstream>
#include <string>

//------------------------------------------------------ Include personnel
#include "Controleur.h"
#include "Decomposeur.h"
#include "CommandeFactory.h"
#include "..\Modele\Service.h"

#include "CommandeCreation.h"
//------------------------------------------------------------- Constantes

static const string COMMANDE_EXIT = "EXIT";
static const string COMMANDE_LIST = "LIST";
static const string COMMANDE_COUNT = "COUNT";
static const string COMMANDE_UNDO = "UNDO";
static const string COMMANDE_REDO = "REDO";
static const string COMMANDE_SEL = "S";
static const string COMMANDE_SAVE = "SAVE";

static const string CHAINE_PARA_INVALIDE = "\n#invalid parameters";
static const string LABEL_COUNT = "#number of objects:\n";

static const unsigned int NB_PARAM_SELECT = 5;
static const unsigned int NB_PARAM_LIST = 1;
static const unsigned int NB_PARAM_UNDO = 1;
static const unsigned int NB_PARAM_REDO = 1;
static const unsigned int NB_PARAM_SAVE = 2;
static const unsigned int NB_PARAM_COUNT = 1;
static const unsigned int NB_PARAM_EXIT = 1;

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Controleur::traitementCommande ( )
// Algorithme :
//
{
	Commande *laCommande;
	string reponse;
	string *nomCommande;
	while (!quitter)
	{
		LireCommande(parametres, &requete);

		laCommande = NULL;
		//Cas où l'utilisateur a juste fait entrée
		if (parametres.empty())
		{
			continue;
		}
		nomCommande = parametres.front();

		if (nomCommande->at(0) == CAR_COMMENTAIRE)
		{
			//Rien à faire
		}
		else if (nomCommande->compare(COMMANDE_EXIT) == 0)
		{
			if (parametres.size() == NB_PARAM_EXIT)
			{
				quitter = true;
			}
			else
			{
				cout << ERREUR << requete << endl;
			}
		}
		else if (nomCommande->compare(COMMANDE_LIST) == 0)
		{
			if (parametres.size() == NB_PARAM_LIST)
			{
				reponse = contexte->DescriptionEltsSelect();
			}
			else
			{
				reponse = ERREUR + requete + "\n";
			}
			cout << reponse << flush;
		}
		else if (nomCommande->compare(COMMANDE_COUNT) == 0)
		{
			if (parametres.size() == NB_PARAM_COUNT)
			{
				stringstream convertisseur;
				convertisseur << contexte->NbEltsTotals();
				reponse = LABEL_COUNT + convertisseur.str();
			}
			else
			{
				reponse = ERREUR + requete;
			}
			cout << reponse << endl;
		}
		else if (nomCommande->compare(COMMANDE_UNDO) == 0)
		{
			cout << defaire() << endl;
		}
		else if (nomCommande->compare(COMMANDE_REDO) == 0)
		{
			cout << refaire() << endl;
		}
		else if (nomCommande->compare(COMMANDE_SAVE) == 0)
		{
			cout << save() << endl;
		}
		else if (nomCommande->compare(COMMANDE_SEL) == 0)
		{
			cout << selectionner() << endl;
		}
		else
		{
			//Récupération de la bonne commande
			traitementCommande(laCommande);
		}
		//Vidage des paramètres
		parametres.clear();
	}
	delete laCommande;
	delete nomCommande;
}    //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
//Controleur & Controleur::operator = ( const Controleur & unControleur )
//// Algorithme :
////
//{
//} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
//Controleur::Controleur ( const Controleur & unControleur )
//// Algorithme :
////
//{
//#ifdef MAP
//	cout << "Appel au constructeur de copie de <Controleur>" << endl;
//#endif
//} //----- Fin de Controleur (constructeur de copie)

Controleur::Controleur ( ) :
		quitter(false), contexte(new ObjetGeometrique())
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Controleur>" << endl;
#endif
}    //----- Fin de Controleur

Controleur::~Controleur ( )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Controleur>" << endl;
#endif
	delete contexte;
	for (vector<string *>::iterator it = parametres.begin();
			it != parametres.end(); it++)
			{
		delete *it;
	}

	while(!commandesExec.empty())
	{
		delete commandesExec.top();
		commandesExec.pop();
	}

	while(!commandesHistorique.empty())
	{
		delete commandesHistorique.top();
		commandesHistorique.pop();
	}

	parametres.clear();
//	commandesExec.pop();
}    //----- Fin de ~Controleur

//------------------------------------------------------------------ PRIVE

string Controleur::defaire ( )
{
	string reponse;
	if (parametres.size() == NB_PARAM_UNDO)
	{
		if (!commandesExec.empty())
		{
			Commande *laCommande = NULL;
			laCommande = commandesExec.top();
			laCommande->Undo();
			commandesHistorique.push(laCommande);
			commandesExec.pop();
			reponse = OK + requete;
			return reponse;
		}
	}

	reponse = ERREUR + requete;
	return reponse;
}

string Controleur::refaire ( )
{
	string reponse;
	if (parametres.size() == NB_PARAM_REDO)
	{
		if (!commandesHistorique.empty())
		{
			Commande *laCommande = NULL;
			laCommande = commandesHistorique.top();
			laCommande->Redo();
			commandesExec.push(laCommande);
			commandesHistorique.pop();
			reponse = OK + requete;
			return reponse;
		}
	}
	reponse = ERREUR + requete;
	return reponse;
}

string Controleur::selectionner ( )
// Algorithme :
//
{
	vector<int> nombres;
	string reponse;
	ostringstream os;

	if (parametres.size() == NB_PARAM_SELECT)
	{
		vector<string*>::iterator it = parametres.begin();
		it++;
		while (it != parametres.end())
		{
			if (!IsInteger(**it))
			{
				reponse = ERREUR + requete;
				return reponse;
			}
			nombres.push_back(atoi((*it)->c_str()));
			it++;
		}
	}

	os
	<< contexte->SelectionnerElts(nombres.at(0), nombres.at(1),
			nombres.at(2), nombres.at(3));
	return os.str();

}    //----- Fin de Méthode

string Controleur::save ( )
// Algorithme :
//
{
	string reponse = ERREUR + requete;

	if (parametres.size() != NB_PARAM_SAVE
			|| parametres.at(1)->find(CommandeFactory::EXTENSION_FICHIER)
					== string::npos)
	{
		return reponse;
	}

	fstream fichier(parametres.at(1)->c_str(), fstream::out);

	if (!fichier.is_open())
	{
		return reponse;
	}

	string lesDescripteurs(contexte->DescriptionEltsTotal());

	fichier.write(lesDescripteurs.c_str(), lesDescripteurs.size());
	string texte("#fin du fichier de création");
	fichier.write(texte.c_str(), texte.size());
	fichier.close();

	if (fichier.fail())
	{
		return reponse;
	}

	return OK + requete;

}    //----- Fin de Méthode

void Controleur::traitementCommande ( Commande *laCommande )
{
	//Récupération de la bonne commande
	bool statusCommande;

	statusCommande = CommandeFactory::GetCommande(parametres, &laCommande,
			contexte, &requete);

	if (statusCommande)
	{
		//Historisation des commandes
		laCommande->Execute();
		while (!commandesHistorique.empty())
		{
			delete commandesHistorique.top();
			commandesHistorique.pop();
		}
		commandesExec.push(laCommande);
		cout << laCommande->getTexteCommande() << endl;
	}
	else
	{
		cout << ERREUR << requete << CHAINE_PARA_INVALIDE << endl;
	}
}

//----------------------------------------------------- Méthodes protégées

