/*************************************************************************
 Controleur  -  description
 -------------------
 d�but                : 27 janv. 2012
 copyright            : (C) 2012 par Pitou
 *************************************************************************/

//---------- R�alisation de la classe <Controleur> (fichier Controleur.cpp) -------
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include syst�me
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
#include "../Modele/Service.h"

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
static const char FIN_LIGNE = '\n';

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
void Controleur::traitementCommande ( )
// Algorithme :
//
{
	Commande *laCommande;
	string *nomCommande;
	string reponse;

	while (!quitter)
	{
		LireCommande(parametres, requete);

		laCommande = NULL;
		//Cas o� l'utilisateur a juste fait entr�e
		if (parametres.empty())
		{
			continue;
		}
		nomCommande = parametres.front();

		cout << CAR_COMMENTAIRE << requete << endl;

		if (nomCommande->at(0) == CAR_COMMENTAIRE)
		{
			//Rien � faire
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
				reponse = ERREUR + requete + FIN_LIGNE;
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
			//R�cup�ration de la bonne commande
			traitementCommande(laCommande);
		}
		//Vidage des param�tres
		vidagePara();
		delete laCommande;
		delete nomCommande;
	}

}    //----- Fin de M�thode

//------------------------------------------------- Surcharge d'op�rateurs
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

	while (!commandesExec.empty())
	{
		delete commandesExec.top();
		commandesExec.pop();
	}

	while (!commandesHistorique.empty())
	{
		delete commandesHistorique.top();
		commandesHistorique.pop();
	}

	parametres.clear();
}    //----- Fin de ~Controleur

//------------------------------------------------------------------ PRIVE

string Controleur::defaire ( )
{
	string reponse;
	if (parametres.size() == NB_PARAM_UNDO)
	{
		reponse = OK + requete;
		if (!commandesExec.empty())
		{
			Commande *laCommande = NULL;
			laCommande = commandesExec.top();
			laCommande->Undo();
			commandesHistorique.push(laCommande);
			commandesExec.pop();
		}
	}
	else
	{
		reponse = ERREUR + requete;
	}
	return reponse;
}

string Controleur::refaire ( )
{
	string reponse;
	if (parametres.size() == NB_PARAM_REDO)
	{
		reponse = OK + requete;
		if (!commandesHistorique.empty())
		{
			Commande *laCommande = NULL;
			laCommande = commandesHistorique.top();
			laCommande->Redo();
			commandesExec.push(laCommande);
			commandesHistorique.pop();
		}
	}
	else
	{
		reponse = ERREUR + requete;
	}

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

	os << contexte->SelectionnerElts(nombres.at(0), nombres.at(1),
			nombres.at(2), nombres.at(3));

	return os.str();

}    //----- Fin de M�thode

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
	string texte("#fin du fichier de cr�ation");
	fichier.write(texte.c_str(), texte.size());
	fichier.close();

	if (fichier.fail())
	{
		return reponse;
	}

	return OK + requete;

}    //----- Fin de M�thode

void Controleur::traitementCommande ( Commande *laCommande )
{
	//R�cup�ration de la bonne commande
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

void Controleur::vidagePara ( )
{
	//Vidage des param�tres

	parametres.clear();

}
//----------------------------------------------------- M�thodes prot�g�es

