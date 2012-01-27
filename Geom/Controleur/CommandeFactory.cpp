/*************************************************************************
                           CommandeFactory  -  description
                             -------------------
    début                : 27 janv. 2012
    copyright            : (C) 2012 par Pitou
*************************************************************************/

//---------- Réalisation de la classe <CommandeFactory> (fichier CommandeFactory.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "CommandeFactory.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type CommandeFactory::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


Commande *CommandeFactory::GetCommande()
{
	Commande commande = new CommandeCreation();


}
//------------------------------------------------- Surcharge d'opérateurs
CommandeFactory & CommandeFactory::operator = ( const CommandeFactory & unCommandeFactory )
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

//----------------------------------------------------- Méthodes protégées

