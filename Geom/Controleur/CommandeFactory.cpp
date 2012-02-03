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

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
// type CommandeFactory::M�thode ( liste des param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode

bool CommandeFactory::GetCommande ( queue <string> para, Commande **laCommande, ObjetGeometrique *contexte)
// Mode d'emploi : Retourne l'instance d'une commande
// correspondant aux arguments pass�s en param�tre.
//
// Contrat : Les cas de LIST, COUNT, UNDO, REDO, S X1, Y1, X2, Y2
// sont trait�s en amont par le controleur.
{
	bool status = false;

	string commande = para.front();
	cout<<commande<<endl;
	para.pop();

	if (commande.find("C") == 0)
	{
		cout<<"Construct"<<endl;
		*laCommande = new CommandeCreationCercle(para, contexte);
		status = true;
	}
	else if (commande.find("R") == 0)
	{

	}
	else if (commande.find("L") == 0)
	{

	}
	else if (commande.find("PL") == 0)
	{

	}
	else if (commande.find("LOAD") == 0)
	{

	}
	else if (commande.find("SAVE") == 0)
	{

	}
	else if(commande.find("CLEAR") == 0)
	{

	}
	else if(commande.find("DELETE") == 0)
	{

	}
	else if(commande.find("MOVE") == 0)
	{

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

