/*************************************************************************
                           CommandeFactory  -  description
                             -------------------
    d�but                : 27 janv. 2012
    copyright            : (C) 2012 par Pitou
*************************************************************************/

//---------- R�alisation de la classe <CommandeFactory> (fichier CommandeFactory.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "CommandeFactory.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
// type CommandeFactory::M�thode ( liste des param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode


Commande *CommandeFactory::GetCommande()
{
	Commande commande = new CommandeCreation();


}
//------------------------------------------------- Surcharge d'op�rateurs
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

//----------------------------------------------------- M�thodes prot�g�es

