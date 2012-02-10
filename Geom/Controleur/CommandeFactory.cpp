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
#include "CommandeDirect.h"


//------------------------------------------------------------- Constantes
static const string COMMANDE_RECTANGLE = "R";
static const string COMMANDE_CERCLE = "C";
static const string COMMANDE_LIGNE = "L";
static const string COMMANDE_POLY = "PL";
static const string COMMANDE_LISTE = "LIST";
static const string COMMANDE_COUNT = "COUNT";
static const string COMMANDE_UNDO = "UNDO";
static const string COMMANDE_REDO = "REDO";
static const char COMMANDE_SEL = 'S';
static const string COMMANDE_LOAD = "LOAD";
static const string COMMANDE_SAVE = "SAVE";
static const string COMMANDE_CLEAR = "CLEAR";
static const string COMMANDE_DELETE = "DELETE";
static const string COMMANDE_MOVE = "MOVE";
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
// type CommandeFactory::M�thode ( liste des param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode

bool CommandeFactory::GetCommande ( queue<string *> para, Commande **laCommande,
		ObjetGeometrique *contexte, Controleur *ctrl )
// Mode d'emploi : Retourne l'instance d'une commande
// correspondant aux arguments pass�s en param�tre.
//
// Contrat : Les cas de LIST, COUNT, UNDO, REDO, S X1, Y1, X2, Y2
{
	bool status = false;

	string commande = *para.front();
	para.pop();

#ifdef MAP
	cout << commande << endl;
#endif

	if (commande.find(COMMANDE_LISTE) != string::npos)
	{
		cout << "tentative de listage non impl�ment�! " << endl;
//		string temp = contexte->DescriptionEltsTotal();
//		cout << temp << endl;
	}
	else if (commande.find(COMMANDE_COUNT) != string::npos)
	{
		cout << "Count non impl�ment�" << endl;
	}
	else if (commande.find(COMMANDE_UNDO) != string::npos)
	{
		cout << "undo non impl�ment�" << endl;
	}
	else if (commande.find(COMMANDE_REDO) != string::npos)
	{
		cout << "redo non impl�ment�" << endl;
	}
	else if (commande.at(0) == COMMANDE_SEL && commande.size() == 1)
	{
		cout << "Selection non impl�ment�" << endl;
	}
	if (commande.find(COMMANDE_LOAD) != string::npos)
	{
		cout << "Load non impl�ment�" << endl;
	}
	else if (commande.find(COMMANDE_SAVE) != string::npos)
	{
		cout << "Save non impl�ment�" << endl;
	}
	else if (commande.find(COMMANDE_MOVE) != string::npos)
	{
		cout << "Move non impl�ment�" << endl;
	}
	else if (commande.find(COMMANDE_CLEAR) != string::npos)
	{
		cout << "Clear non impl�ment�" << endl;
	}
	else if (commande.find(COMMANDE_DELETE) != string::npos)
	{
		cout << "Delete non impl�ment�" << endl;
	}
	else if (commande.find(COMMANDE_CERCLE) != string::npos)
	{
		*laCommande = new CommandeCreationCercle(para, contexte);
		status = true;
	}
	else if (commande.find(COMMANDE_RECTANGLE) != string::npos)
	{
		cout << "Rect non impl�ment�" << endl;
	}
	else if (commande.find(COMMANDE_LIGNE) != string::npos)
	{
		cout << "Ligne non impl�ment�" << endl;
	}
	else if (commande.find(COMMANDE_POLY) != string::npos)
	{
		cout << "Poly non impl�ment�" << endl;
	}

	return status;
}
//------------------------------------------------- Surcharge d'op�rateurs
CommandeFactory & CommandeFactory::operator = (
		const CommandeFactory & unCommandeFactory )
// Algorithme :
//
{
} //----- Fin de operator =

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

