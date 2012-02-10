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
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Controleur::traitementCommande ( )
// Algorithme :
//
{
	while (!quitter)
	{
		LireCommande(parametres);

		Commande *laCommande;

		//Traitement particulier dans le cas du exit
		if (parametres.front()->find(COMMANDE_EXIT) != string::npos)
		{
			cout<<"Exit non implémenté (nettoyage nécessaire) "<<endl;
			quitter = true;
		}
		else
		{
			//Récupération de la bonne commande
			CommandeFactory::GetCommande(parametres, &laCommande, contexte, this);

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

		//Vidage des paramètres
	    viderParametres();
	}

} //----- Fin de Méthode

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
//----------------------------------------------------- Méthodes protégées

