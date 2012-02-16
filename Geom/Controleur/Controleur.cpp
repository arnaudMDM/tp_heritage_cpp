/*************************************************************************
 Controleur  -  description
 -------------------
 dï¿½but                : 27 janv. 2012
 copyright            : (C) 2012 par Pitou
 *************************************************************************/

//---------- Rï¿½alisation de la classe <Controleur> (fichier Controleur.cpp) -------
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include systï¿½me
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

//----------------------------------------------------- Mï¿½thodes publiques
void Controleur::TraitementCommande ( )
{
	Commande *laCommande;
	string *nomCommande;
	string reponse;

	while (!quitter)
	{
		//Recuperation de la requete de l'utilisateur
		LireCommande(parametres, requete);

		laCommande = NULL;

		//Cas oï¿½ l'utilisateur a juste fait entrï¿½e
		if (parametres.empty())
		{
			continue;
		}

		nomCommande = parametres.front();

		cout << CAR_COMMENTAIRE << requete << endl;

		//Deroulement des differents cas de figure
		if (nomCommande->at(0) == CAR_COMMENTAIRE)
		{
			//Rien ï¿½ faire
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
			//Rï¿½cupï¿½ration de la bonne commande
			traitementCommande(laCommande);
		}
		//Vidage des paramï¿½tres
		vidagePara();
		delete laCommande;
		delete nomCommande;
	}

}    //----- Fin de TraitementCommande()

//------------------------------------------------- Surcharge d'opï¿½rateurs

//-------------------------------------------- Constructeurs - destructeur

Controleur::Controleur ( ) :
		quitter(false), contexte(new ObjetGeometrique())
{
#ifdef MAP
	cout << "Appel au constructeur de <Controleur>" << endl;
#endif
}    //----- Fin de Controleur

Controleur::~Controleur ( )
// Algorithme : désalloue la mémoire utiliser par les pointeurs stockes
// dans les piles de Commandes
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
// Appel le Undo() de la commande sur le dessus de la pile de commandes
// executees et change cet element de pile.
{
	string reponse;
	if (parametres.size() == NB_PARAM_UNDO)
	{
		reponse = OK + requete;
		//Undo possible si des commandes ont etes precedemment executees
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
}//----- Fin de defaire

string Controleur::refaire ( )
// Appel le Redo() de la commande sur le dessus de la pile de commandes
// undo-ees et change cet element de pile.
{
	string reponse;
	if (parametres.size() == NB_PARAM_REDO)
	{
		reponse = OK + requete;
		//Redo possible si des commandes ont etes precedemment Undo-ees
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
}//----- Fin de refaire

string Controleur::save ( )
// Methode permettant de traiter le cas du SAVE
// Verifie la validite du fichier passe en argument
// et le cas echeant le rempli par les descripteurs des
// commandes de creation
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
	string texte("#fin du fichier de creation");
	fichier.write(texte.c_str(), texte.size());
	fichier.close();

	if (fichier.fail())
	{
		return reponse;
	}

	return OK + requete;

}    //----- Fin de save

string Controleur::selectionner ( )
// Methode permettant de traiter le cas du S X X X X
// Verifie que les arguments de la commande sont correctes
// et le cas echeant realise la selection des elements
{
	vector<int> nombres;
	string reponse;
	ostringstream os;

	//Verification du nombre d'arguments
	if (parametres.size() == NB_PARAM_SELECT)
	{
		//Verification de leur validite numerique
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

	//Selection &R ecuperation du nombre d'elements selectionnes
	os << contexte->SelectionnerElts(nombres.at(0), nombres.at(1),
			nombres.at(2), nombres.at(3));

	return os.str();

}//----- Fin de selectionner



void Controleur::traitementCommande ( Commande *laCommande )
// Methode permettant de traiter le cas des commandes necessittant
// une historisation c'est a dire le cas ou le undo/redo est possible:
// Appel a la fabrique.
{
	bool statusCommande;

	//Recuperation de la bonne commande
	statusCommande = CommandeFactory::GetCommande(parametres, &laCommande,
			contexte, &requete);

	if (statusCommande)
	{
		//Historisation des commandes
		laCommande->Execute();
		//Si des elements existaient dans la pile de undo, alors purge de cette derniere
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
	//Vidage des parametres

	parametres.clear();

}
//----------------------------------------------------- Methodes protï¿½gï¿½es

