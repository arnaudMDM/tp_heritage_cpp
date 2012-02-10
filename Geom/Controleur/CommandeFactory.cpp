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

//------------------------------------------------------------- Constantes
static const string COMMANDE_RECTANGLE = "R";
static const string COMMANDE_CERCLE = "C";
static const string COMMANDE_LIGNE = "L";
static const string COMMANDE_POLY = "PL";
static const string COMMANDE_LOAD = "LOAD";
static const string COMMANDE_SAVE = "SAVE";
static const string COMMANDE_CLEAR = "CLEAR";
static const string COMMANDE_DELETE = "DELETE";
static const string COMMANDE_MOVE = "MOVE";
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type CommandeFactory::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

bool CommandeFactory::GetCommande ( vector<string *> para, Commande **laCommande,
		ObjetGeometrique *contexte)
// Mode d'emploi : Retourne l'instance d'une commande
// correspondant aux arguments passés en paramètre.
//
// Contrat : Les cas de LIST, COUNT, UNDO, REDO, S X1, Y1, X2, Y2
{
	bool status = true;

	string commande = *para.front();

#ifdef MAP
	cout << commande << endl;
#endif
	if (commande.find(COMMANDE_LOAD) != string::npos)
	{
		cout << "Load non implémenté" << endl;
	}
	else if (commande.find(COMMANDE_SAVE) != string::npos)
	{
		cout << "Save non implémenté" << endl;
	}
	else if (commande.find(COMMANDE_MOVE) != string::npos)
	{
		cout << "Move non implémenté" << endl;
	}
	else if (commande.find(COMMANDE_CLEAR) != string::npos)
	{
		cout << "Clear non implémenté" << endl;
	}
	else if (commande.find(COMMANDE_DELETE) != string::npos)
	{
		cout << "Delete non implémenté" << endl;
	}
	else if (commande.find(COMMANDE_CERCLE) != string::npos)
	{
		*laCommande = new CommandeCreationCercle(para, contexte);
	}
	else if (commande.find(COMMANDE_RECTANGLE) != string::npos)
	{
		cout << "Rect non implémenté" << endl;
	}
	else if (commande.find(COMMANDE_LIGNE) != string::npos)
	{
		cout << "Ligne non implémenté" << endl;
	}
	else if (commande.find(COMMANDE_POLY) != string::npos)
	{
		cout << "Poly non implémenté" << endl;
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
} //----- Fin de CommandeFactory (constructeur de copie)

CommandeFactory::CommandeFactory ( )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <CommandeFactory>" << endl;
#endif
} //----- Fin de CommandeFactory

CommandeFactory::~CommandeFactory ( )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <CommandeFactory>" << endl;
#endif
} //----- Fin de ~CommandeFactory

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

