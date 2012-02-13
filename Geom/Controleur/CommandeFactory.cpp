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
static const string EXTENSION_FICHIER = ".txt";
static const unsigned int NB_PARAM_MOVE = 3;
static const unsigned int NB_PARAM_LOAD = 2;
static const unsigned int NB_PARAM_CLEAR = 1;
static const unsigned int NB_PARAM_DELETE = 1;

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type CommandeFactory::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

bool CommandeFactory::GetCommande ( vector<string *> para,
		Commande **laCommande,
		ObjetGeometrique *contexte, const string *requete )
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
		status = traitementMove(para, laCommande, contexte);
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
		*laCommande = new CommandeCreationCercle(para, contexte, requete);
	}
	else if (commande.compare(COMMANDE_RECTANGLE) == 0)
	{
		*laCommande = new CommandeCreationRectangle(para, contexte, requete);
	}
	else if (commande.compare(COMMANDE_LIGNE) == 0)
	{
		*laCommande = new CommandeCreationLigne(para, contexte, requete);
	}
	else if (commande.compare(COMMANDE_POLY) == 0)
	{
		*laCommande = new CommandeCreationPoly(para, contexte, requete);
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
		Commande ** laCommande, ObjetGeometrique * contexte )
{
	bool etat(true);

	if (para.size() == NB_PARAM_MOVE)
	{
		vector<string*>::iterator it = para.begin() + 1;

		while (it != para.end() && !etat)
		{
			if (!IsInteger(**it))
			{
				etat = false;
			}
			it++;
		}

		if (etat)
		{
			*laCommande = new CommandeDeplac(para, contexte);
		}
	}
	else
	{
		etat = false;
	}

	return etat;
}

bool CommandeFactory::traitementLoad( vector<string *> para,
		Commande ** laCommande, ObjetGeometrique * contexte )
{
	if(para.size() == NB_PARAM_LOAD && para.at(1)->find(EXTENSION_FICHIER) != string::npos)
	{
		*laCommande = new CommandeLoad(*(para.at(1)), contexte);
		return (*laCommande)->IsOk();
	}
	else
	{
		return false;
	}
}
//----------------------------------------------------- Méthodes protégées

