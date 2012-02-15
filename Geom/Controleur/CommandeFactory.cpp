/*************************************************************************
 CommandeFactory  -  description
 -------------------
 début                : 27 janv. 2012
 copyright            : (C) 2012 par Pitou
 *************************************************************************/

//---------- Réalisation de la classe <CommandeFactory> (fichier CommandeFactory.cpp) -------
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
#include <exception>
#include <cstdlib>
using namespace std;
//------------------------------------------------------ Include personnel
#include "CommandeFactory.h"
#include "CommandeCreationCercle.h"
#include "CommandeCreationLigne.h"
#include "CommandeCreationRectangle.h"
#include "CommandeCreationPoly.h"
#include "CommandeSuppression.h"
#include "CommandeDeplac.h"
#include "CommandeLoad.h"

//------------------------------------------------------------- Constantes
static const string COMMANDE_RECTANGLE = "R";
static const string COMMANDE_CERCLE = "C";
static const string COMMANDE_LIGNE = "L";
static const string COMMANDE_POLY = "PL";
static const string COMMANDE_LOAD = "LOAD";
static const string COMMANDE_CLEAR = "CLEAR";
static const string COMMANDE_DELETE = "DELETE";
static const string COMMANDE_MOVE = "MOVE";

static const unsigned int NB_PARAM_MOVE = 3;
static const unsigned int NB_PARAM_LOAD = 2;
static const unsigned int NB_PARAM_CLEAR = 1;
static const unsigned int NB_PARAM_DELETE = 1;
static const unsigned int NB_PARAM_CREAT_RECT = 5;
static const unsigned int NB_PARA_INVARIANT_PL = 1;
static const unsigned int NB_PARA_PAR_POINT = 2;
static const unsigned int NB_PARAM_CREAT_CERCLE = 4;
static const unsigned int TAILLE_COMMANDE_LIGNE = 5;
//----------------------------------------------------------------- PUBLIC
const string CommandeFactory::EXTENSION_FICHIER = ".txt";
//----------------------------------------------------- Méthodes publiques
// type CommandeFactory::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

bool CommandeFactory::GetCommande ( vector<string *> para,
		Commande **laCommande,
		ObjetGeometrique *contexte, string *requete )
// Mode d'emploi : Retourne l'instance d'une commande
// correspondant aux arguments passés en paramètre.
//
{
	bool status(true);

	string commande(*para.front());

#ifdef MAP
	cout << commande << endl;
#endif
	if (commande.compare(COMMANDE_LOAD) == 0)
	{
		status = traitementLoad(para, laCommande, contexte);
	}
	else if (commande.compare(COMMANDE_MOVE) == 0)
	{
		status = traitementMove(para, laCommande, contexte, requete);
	}
	else if (commande.compare(COMMANDE_CLEAR) == 0)
	{
		if (para.size() == NB_PARAM_CLEAR)
		{
			*laCommande = new CommandeSuppression(contexte,
					CommandeSuppression::CLEAR);
		}
		else
		{
			status = false;
		}
	}
	else if (commande.compare(COMMANDE_DELETE) == 0)
	{
		if (para.size() == NB_PARAM_DELETE)
		{
			*laCommande = new CommandeSuppression(contexte,
					CommandeSuppression::DELETE);
		}
		else
		{
			status = false;
		}
	}
	else if (commande.find(COMMANDE_CERCLE) == 0)
	{
		status = traitementCercle(para, laCommande, contexte, requete);
	}
	else if (commande.compare(COMMANDE_RECTANGLE) == 0)
	{
		status = traitementRect(para, laCommande, contexte, requete);
	}
	else if (commande.compare(COMMANDE_LIGNE) == 0)
	{
		status = traitementLigne(para, laCommande, contexte, requete);
	}
	else if (commande.compare(COMMANDE_POLY) == 0)
	{
		status = traitementPoly(para, laCommande, contexte, requete);
	}
	else
	{
		status = false;
	}

	return status;
}
//------------------------------------------------- Surcharge d'opérateurs
//CommandeFactory & CommandeFactory::operator = (
//		const CommandeFactory & unCommandeFactory )
//// Algorithme :
////
//{
//} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
CommandeFactory::CommandeFactory ( const CommandeFactory & unCommandeFactory )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <CommandeFactory>" << endl;
#endif
}    //----- Fin de CommandeFactory (constructeur de copie)

CommandeFactory::CommandeFactory ( )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <CommandeFactory>" << endl;
#endif
}    //----- Fin de CommandeFactory

CommandeFactory::~CommandeFactory ( )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <CommandeFactory>" << endl;
#endif
}    //----- Fin de ~CommandeFactory

//------------------------------------------------------------------ PRIVE
bool CommandeFactory::traitementMove ( vector<string *> para,
		Commande ** laCommande, ObjetGeometrique * contexte, const string *requete )
{
	bool etat(true);

	if (para.size() == NB_PARAM_MOVE)
	{
		vector<string*>::iterator it = para.begin() + 1;

		while (it != para.end() && etat)
		{
			if (!IsInteger(**it))
			{
				etat = false;
			}
			it++;
		}

		if (etat)
		{
			*laCommande = new CommandeDeplac(para, contexte, requete);
		}
	}
	else
	{
		etat = false;
	}

	return etat;
}

bool CommandeFactory::traitementLoad ( vector<string *> para,
		Commande ** laCommande, ObjetGeometrique * contexte )
{
	if (para.size() == NB_PARAM_LOAD
			&& para.at(1)->find(EXTENSION_FICHIER) != string::npos)
	{
		CommandeLoad *ptrLoad = new CommandeLoad(*(para.at(1)), contexte);
		*laCommande = ptrLoad;
		return ((CommandeLoad *)(*laCommande))->IsOk();
		return ptrLoad->IsOk();
	}
	else
	{
		return false;
	}
}

bool CommandeFactory::traitementRect ( vector<string *> para,
		Commande ** laCommande,
		ObjetGeometrique * contexte, const string *requete )
{
	bool correct(false);

	if (para.size() == NB_PARAM_CREAT_RECT)
	{
		correct = true;

		vector<string*>::iterator it = para.begin() + 1;

		while (it != para.end() && correct)
		{
			if (!IsInteger(**it))
			{
				correct = false;
			}
			it++;
		}

		if (correct)
		{
			*laCommande = new CommandeCreationRectangle(para, contexte,
					requete);
		}
	}
	return correct;
}

bool CommandeFactory::traitementPoly ( vector<string *> para,
		Commande ** laCommande,
		ObjetGeometrique * contexte, const string *requete )
{
	vector<int> tempX;
	vector<int> tempY;

	bool correct(true);

	if ((para.size() - NB_PARA_INVARIANT_PL) % NB_PARA_PAR_POINT != 0)
	{
		correct = false;
	}
	else
	{
		vector<string *>::iterator itX = para.begin() + 1;
		vector<string *>::iterator itY = para.begin() + 2;

		while (itX != para.end() && correct)
		{
			if (!IsInteger((*itY)->c_str()) || !IsInteger((*itX)->c_str()))
			{
				correct = false;
			}
			else
			{
				tempX.push_back(atoi((*itX)->c_str()));
				tempY.push_back(atoi((*itY)->c_str()));
			}

			itX += NB_PARA_PAR_POINT;
			itY += NB_PARA_PAR_POINT;
		}
	}

	if (correct)
	{
		*laCommande = new CommandeCreationPoly(tempX, tempY, contexte, requete);
	}
	return correct;
}

bool CommandeFactory::traitementCercle ( vector<string *> para,
		Commande ** laCommande,
		ObjetGeometrique * contexte, const string *requete )
{
	bool correct(true);

	if (para.size() == NB_PARAM_CREAT_CERCLE)
	{
		vector<string*>::iterator it = para.begin() + 1;
		while (it != para.end() && correct)
		{
			if (!IsInteger(**it))
			{
				correct = false;
			}
			it++;
		}

		if (correct && atoi((para.at(3))->c_str()) > 0)
		{
			*laCommande = new CommandeCreationCercle(para, contexte, requete);
		}
		else
		{
			correct = false;
		}
	}
	else
	{
		correct = false;
	}

	return correct;
}

bool CommandeFactory::traitementLigne ( vector<string *> para,
		Commande ** laCommande,
		ObjetGeometrique * contexte, const string *requete )
{

	string tmp;
	bool correct(true);

	if (para.size() == TAILLE_COMMANDE_LIGNE)
	{
		vector<string *>::iterator it = para.begin() + 1;

		while (it != para.end() && correct)
		{
			if (!IsInteger((*it)->c_str()))
			{
				correct = false;
			}
			it++;
		}

		if (correct)
		{
			*laCommande = new CommandeCreationLigne(para, contexte, requete);
		}
	}
	else
	{
		correct = false;
	}

	return correct;
}
//----------------------------------------------------- Méthodes protégées

