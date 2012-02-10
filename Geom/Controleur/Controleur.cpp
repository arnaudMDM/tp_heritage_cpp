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

//------------------------------------------------------ Include personnel
#include "Controleur.h"
#include "Decomposeur.h"
#include "CommandeFactory.h"

#include "CommandeCreation.h"
//------------------------------------------------------------- Constantes
static const string COMMANDE_EXIT = "EXIT";
static const string COMMANDE_LISTE = "LIST";
static const string COMMANDE_COUNT = "COUNT";
static const string COMMANDE_UNDO = "UNDO";
static const string COMMANDE_REDO = "REDO";
static const char COMMANDE_SEL = 'S';
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
			cout << "tentative de listage non implémenté! " << endl;
			string temp = contexte->DescriptionEltsTotal();
			cout << temp << endl;
		}
		else if (commande->find(COMMANDE_COUNT) != string::npos)
		{
			cout << "Count non implémenté" << endl;
		}
		else if (commande->find(COMMANDE_UNDO) != string::npos)
		{
			cout<<defaire()<<endl;
		}
		else if (commande->find(COMMANDE_REDO) != string::npos)
		{
			cout<<refaire()<<endl;
		}
		else if (commande->at(0) == COMMANDE_SEL && commande->size() == 1)
		{
			cout << "Selection non implémenté" << endl;
		}
		else
		{
			//Récupération de la bonne commande
			CommandeFactory::GetCommande(parametres, &laCommande, contexte);

			if (laCommande)
			{
				laCommande->execute();

				//Historisation des commandes
				if(laCommande->isHistorisable())
				{
					while(!commandesHistorique.empty())
					{
						commandesHistorique.pop();
					}
					commandesExec.push(laCommande);
				}
			}
			else
			{
				cout<<"Commande inconnue"<<endl;
			}
		}

		//Vidage des paramètres
	    viderParametres();
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
void Controleur::viderParametres()
{
    //Vidage des paramètres
    while(!parametres.empty()){
        parametres.pop();
    }
}

string Controleur::defaire()
{
	string msg;
	if (!commandesExec.empty())
	{
		Commande *laCommande = NULL;
		laCommande = commandesExec.front();
		commandesExec.pop();
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

string Controleur::refaire()
{
	string msg;
	if (!commandesHistorique.empty())
	{
		Commande *laCommande = NULL;
		laCommande = commandesHistorique.front();
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
//----------------------------------------------------- Méthodes protégées

