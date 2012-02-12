/*************************************************************************
 CommandeFactory  -  description
 -------------------
 d�but                : 27 janv. 2012
 copyright            : (C) 2012 par Pitou
 *************************************************************************/

//---------- R�alisation de la classe <CommandeFactory> (fichier CommandeFactory.cpp) -------
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include syst�me
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
static const string COMMANDE_CLEAR = "CLEAR";
static const string COMMANDE_DELETE = "DELETE";
static const string COMMANDE_MOVE = "MOVE";

static const unsigned int NB_PARAM_CLEAR = 1;
static const unsigned int NB_PARAM_DELETE = 1;
static const unsigned int NB_PARAM_MOVE = 3;
static const unsigned int NB_PARAM_LOAD = 2;

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
// type CommandeFactory::M�thode ( liste des param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode

bool CommandeFactory::GetCommande ( vector<string *> para, Commande **laCommande,
		ObjetGeometrique *contexte, const string *requete)
// Mode d'emploi : Retourne l'instance d'une commande
// correspondant aux arguments pass�s en param�tre.
//
// Contrat : Les cas de LIST, COUNT, UNDO, REDO, S X1, Y1, X2, Y2
{
	bool status(true);

	string commande(*para.front());

#ifdef MAP
	cout << commande << endl;
#endif
	if (commande.compare(COMMANDE_LOAD) == 0)
	{
		cout << "Load non impl�ment�" << endl;
	}
	else if (commande.compare(COMMANDE_MOVE) == 0)
	{
		cout << "Move non impl�ment�" << endl;
	}
	else if (commande.compare(COMMANDE_CLEAR) == 0)
	{
		cout << "Clear non impl�ment�" << endl;
	}
	else if (commande.compare(COMMANDE_DELETE) == 0)
	{
		cout << "Delete non impl�ment�" << endl;
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
//------------------------------------------------- Surcharge d'op�rateurs
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

//----------------------------------------------------- M�thodes prot�g�es

