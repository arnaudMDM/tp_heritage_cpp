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
#include <ctype.h>
#include <cstdlib>

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

		Commande *laCommande = NULL;

		//Cas o� l'utilisateur a juste fait entr�e
		if(parametres.empty())
		{
			continue;
		}
		string *commande = parametres.front();

		//Traitement particulier dans le cas du exit
		if (commande->find(COMMANDE_EXIT) != string::npos)
		{
			cout<<"Exit non impl�ment� (nettoyage n�cessaire) "<<endl;
			quitter = true;
		}else if (commande->find(COMMANDE_LISTE) != string::npos)
		{
			//cout << "tentative de listage non impl�ment�! " << endl;
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
		else if (commande->at(0) == COMMANDE_SEL && commande->size() == 1)
		{
			//cout << "Selection non impl�ment�" << endl;
			cout << Selectionner() << endl;
		}
		else
		{
			//R�cup�ration de la bonne commande
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
				cout<<laCommande->getTexteCommande();
			}
			else
			{
				cout<<"Commande inconnue"<<endl;
			}
		}

		//Vidage des param�tres
	    ViderParametres();
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
void Controleur::ViderParametres()
{
    //Vidage des param�tres
    while(!parametres.empty()){
        parametres.pop();
    }
}

string Controleur::Defaire()
{
	string msg;
	if (!commandesExec.empty())
	{
		Commande *laCommande = NULL;
		laCommande = commandesExec.pop();
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
		laCommande = commandesHistorique.pop();
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
	vector<int> nombres = NULL;
	bool valide = true;
	int n = 0;
	if(parametres.size() == 5)
	{
		parametres.pop();
		while(parametres.size() > 0)
		{

			string temp = parametres.front ( );

			while(n < temp.size() || valide == false)
			{
			if ( !isdigit ( temp.at(n) ) )
				{
					valide = false;
				}
			n +=1;
			}
			nombres.push_back(atoi(temp.c_str()));
			parametres.pop();
		}

	}


} //----- Fin de M�thode


//----------------------------------------------------- M�thodes prot�g�es

