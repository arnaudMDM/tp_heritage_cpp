/*************************************************************************
                           CommandeSelection  -  description
                             -------------------
    début                : 27 janv. 2012
    copyright            : (C) 2012 par Pitou
*************************************************************************/

//---------- Réalisation de la classe <CommandeSelection> (fichier CommandeSelection.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "CommandeSelection.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type CommandeSelection::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
CommandeSelection & CommandeSelection::operator = ( const CommandeSelection & unCommandeSelection )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
CommandeSelection::CommandeSelection ( const CommandeSelection & unCommandeSelection )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <CommandeSelection>" << endl;
#endif
} //----- Fin de CommandeSelection (constructeur de copie)


CommandeSelection::CommandeSelection ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <CommandeSelection>" << endl;
#endif
} //----- Fin de CommandeSelection


CommandeSelection::~CommandeSelection ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CommandeSelection>" << endl;
#endif
} //----- Fin de ~CommandeSelection


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

