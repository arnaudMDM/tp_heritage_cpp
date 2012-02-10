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

//------------------------------------------------------ Include personnel
#include "Controleur.h"
#include "Decomposeur.h"
#include "CommandeFactory.h"
#include "..\Modele\Service.h"

#include "CommandeCreation.h"
//------------------------------------------------------------- Constantes
static const string COMMANDE_EXIT = "EXIT";
static const string COMMANDE_LISTE = "LIST";
static const string COMMANDE_COUNT = "COUNT";
static const string COMMANDE_UNDO = "UNDO";
static const string COMMANDE_REDO = "REDO";
static const char COMMANDE_SEL = 'S';
static const string COMMANDE_SAVE = "SAVE";
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Controleur::traitementCommande ( )
// Algorithme :
//
{
	while (!quitter)
	{
		LireCommande(parametres);

		Commande *laCommande = NULL;

		//Cas où l'utilisateur a juste fait entrée
		if(parametres.empty())
		{
			continue;
		}
		string *commande = parametres.front();

		//Traitement particulier dans le cas du exit
		if (commande->find(COMMANDE_EXIT) != string::npos)
		{
			cout<<"Exit non implémenté (nettoyage nécessaire) "<<endl;
			quitter = true;
		}else if (commande->find(COMMANDE_LISTE) != string::npos)
		{
			//cout << "tentative de listage non implémenté! " << endl;
			string temp = contexte->DescriptionEltsTotal();
			cout << temp << endl;
		}
		else if (commande->find(COMMANDE_COUNT) != string::npos)
		{
			cout << contexte->NbEltsTotals() << endl;
		}
		else if (commande->find(COMMANDE_UNDO) != string::npos)
		{
			cout<<Defaire()<<endl;
		}
		else if (commande->find(COMMANDE_REDO) != string::npos)
		{
			cout<<Refaire()<<endl;
		}
		else if (commande->find(COMMANDE_SAVE) != string::npos)
		{
			cout<<Save()<<endl;
		}
		else if (commande->at(0) == COMMANDE_SEL && commande->size() == 1)
		{
			//cout << "Selection non implémenté" << endl;
			cout << Selectionner() << endl;
		}
		else
		{
			//Récupération de la bonne commande
			CommandeFactory::GetCommande(parametres, &laCommande, contexte);

			if (laCommande)
			{
				//Historisation des commandes

				if(laCommande->IsOk())
				{
					laCommande->execute();

					while(!commandesHistorique.empty())
					{
						commandesHistorique.pop();
					}
					commandesExec.push(laCommande);
				}
				cout<<laCommande->getTexteCommande()<<endl;
			}
			else
			{
				cout<<"Commande inconnue"<<endl;
			}
		}

		//Vidage des paramètres
	    ViderParametres();
	}

} //----- Fin de Méthode



//------------------------------------------------- Surcharge d'opérateurs
Controleur & Controleur::operator = ( const Controleur & unControleur )
// Algorithme :
//
{
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
Controleur::Controleur ( const Controleur & unControleur )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <Controleur>" << endl;
#endif
} //----- Fin de Controleur (constructeur de copie)

Controleur::Controleur ( ) :
		quitter(false), contexte(new ObjetGeometrique())
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Controleur>" << endl;
#endif
} //----- Fin de Controleur

Controleur::~Controleur ( )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Controleur>" << endl;
#endif
} //----- Fin de ~Controleur

//------------------------------------------------------------------ PRIVE
void Controleur::ViderParametres()
{
    //Vidage des paramètres
	parametres.clear();
    }

string Controleur::Defaire()
{
	string msg;
	if (!commandesExec.empty())
	{
		Commande *laCommande = NULL;
		laCommande = commandesExec.top();
		commandesHistorique.pop();
		laCommande->undo();
		commandesHistorique.push(laCommande);
		msg = "OK UNDO";
	}
	else
	{
		msg = "ERR UNDO";
	}

	return msg;
}

string Controleur::Refaire()
{
	string msg;
	if (!commandesHistorique.empty())
	{
		Commande *laCommande = NULL;
		laCommande = commandesHistorique.top();
		commandesHistorique.pop();
		laCommande->redo();
		commandesExec.push(laCommande);
		msg = "OK REDO";
	}
	else
	{
		msg = "ERR REDO";
	}

	return msg;
}

string Controleur::Selectionner()
// Algorithme :
//
{
	vector<int> nombres;
	string reponse;
	ostringstream os;
	reponse ="ERR ";
	for(vector<string*>::iterator it = parametres.begin() ; it != parametres.end() ; it++)
	{
		reponse += " ";
		reponse += **it;
	}


	if(parametres.size() == 5)
	{
		vector<string*>::iterator it = parametres.begin();
		while(it != parametres.end())
		{
			if(!IsDigit(**it))
			{
				return reponse;
			}
			nombres.push_back(atoi((*it)->c_str()));
			it++;
		}
	}


		os << contexte->SelectionnerElts(nombres.at(0),nombres.at(1),nombres.at(2),nombres.at(3));
		return os.str();

} //----- Fin de Méthode

string Controleur::Save()
// Algorithme :
//
{
	string reponse;
	reponse ="ERR";
	string temp;
	for(vector<string*>::iterator it = parametres.begin() ; it != parametres.end() ; it++)
	{
		temp += " ";
		temp += **it;
	}
	reponse += temp;

	if(parametres.size() != 2)
	{
		return reponse;
	}

	fstream fichier (parametres.at(1)->c_str(), fstream::in | fstream::app);

	if(!fichier.is_open())
	{
		return reponse;
	}

	fichier.write(contexte->DescriptionEltsTotal().c_str(),contexte->DescriptionEltsTotal().size());

	fichier.close();

	if(fichier.fail())
	{
		return reponse;
	}

	reponse = "OK";
	reponse += temp;
	return reponse;

	contexte->Deselectionner();

} //----- Fin de Méthode

//----------------------------------------------------- Méthodes protégées

