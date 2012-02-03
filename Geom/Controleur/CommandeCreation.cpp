/*************************************************************************
                           CommandeCreation  -  description
                             -------------------
    début                : 27 janv. 2012
    copyright            : (C) 2012 par Pitou
*************************************************************************/

//---------- Réalisation de la classe <CommandeCreation> (fichier CommandeCreation.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "CommandeCreation.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type CommandeCreation::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
CommandeCreation & CommandeCreation::operator = ( const CommandeCreation & unCommandeCreation )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
CommandeCreation::CommandeCreation ( const CommandeCreation & unCommandeCreation )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <CommandeCreation>" << endl;
#endif
} //----- Fin de CommandeCreation (constructeur de copie)


CommandeCreation::CommandeCreation ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <CommandeCreation>" << endl;
#endif
} //----- Fin de CommandeCreation


CommandeCreation::~CommandeCreation ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CommandeCreation>" << endl;
#endif
} //----- Fin de ~CommandeCreation


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

