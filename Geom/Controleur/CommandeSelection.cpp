/*************************************************************************
                           CommandeSelection  -  description
                             -------------------
    d�but                : 27 janv. 2012
    copyright            : (C) 2012 par Pitou
*************************************************************************/

//---------- R�alisation de la classe <CommandeSelection> (fichier CommandeSelection.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "CommandeSelection.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
// type CommandeSelection::M�thode ( liste des param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode


//------------------------------------------------- Surcharge d'op�rateurs
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

//----------------------------------------------------- M�thodes prot�g�es

