/*************************************************************************
                           CommandeCreationLigne  -  description
                             -------------------
    début                : 10 févr. 2012
    copyright            : (C) 2012 par arnaud
*************************************************************************/

//---------- Réalisation de la classe <CommandeCreationLigne> (fichier CommandeCreationLigne.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "CommandeCreationLigne.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type CommandeCreationLigne::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
CommandeCreationLigne & CommandeCreationLigne::operator = ( const CommandeCreationLigne & unCommandeCreationLigne )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
CommandeCreationLigne::CommandeCreationLigne ( const CommandeCreationLigne & unCommandeCreationLigne )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <CommandeCreationLigne>" << endl;
#endif
} //----- Fin de CommandeCreationLigne (constructeur de copie)


CommandeCreationLigne::CommandeCreationLigne ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <CommandeCreationLigne>" << endl;
#endif
} //----- Fin de CommandeCreationLigne


CommandeCreationLigne::~CommandeCreationLigne ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CommandeCreationLigne>" << endl;
#endif
} //----- Fin de ~CommandeCreationLigne


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
