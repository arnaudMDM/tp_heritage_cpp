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

//----------------------------------------------------- M�thodes publiques
void Controleur::traitementCommande ( )
// Algorithme :
//
{
	while (!quitter)
	{
		LireCommande(parametres);

		Commande *laCommande;
		string *commande = parametres.front();

		//Traitement particulier dans le cas du exit
		if (commande->find(COMMANDE_EXIT) != string::npos)
		{
			cout<<"Exit non impl�ment� (nettoyage n�cessaire) "<<endl;
			quitter = true;
		}else if (commande->find(COMMANDE_LISTE) != string::npos)
		{
			cout << "tentative de listage non impl�ment�! " << endl;
	//		string temp = contexte->DescriptionEltsTotal();
	//		cout << temp << endl;
		}
		else if (commande->find(COMMANDE_COUNT) != string::npos)
		{
			cout << "Count non impl�ment�" << endl;
		}
		else if (commande->find(COMMANDE_UNDO) != string::npos)
		{
			undo();
		}
		else if (commande->find(COMMANDE_REDO) != string::npos)
		{
			redo();
		}
		else if (commande->at(0) == COMMANDE_SEL && commande->size() == 1)
		{
			cout << "Selection non impl�ment�" << endl;
		}
		else
		{
			//R�cup�ration de la bonne commande
			CommandeFactory::GetCommande(parametres, &laCommande, contexte);

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

		//Vidage des param�tres
	    viderParametres();
	}

} //----- Fin de M�thode



//------------------------------------------------- Surcharge d'op�rateurs
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
    //Vidage des param�tres
    while(!parametres.empty()){
        parametres.pop();
    }
}

void Controleur::undo()
{
	cout<<"Undo"<<endl;
	if (!commandesExec.empty())
	{
		Commande *laCommande = NULL;
		laCommande = commandesExec.front();
		commandesExec.pop();
		laCommande->undo();
		commandesHistorique.push(laCommande);
	}
}

void Controleur::redo()
{
	cout<<"Redo"<<endl;
	if (!commandesHistorique.empty())
	{
		Commande *laCommande = NULL;
		laCommande = commandesHistorique.front();
		commandesHistorique.pop();
		laCommande->redo();
		commandesExec.push(laCommande);
	}
}
//----------------------------------------------------- M�thodes prot�g�es

