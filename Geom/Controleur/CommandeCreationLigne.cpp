/*************************************************************************
                           CommandeCreationLigne  -  description
                             -------------------
    d�but                : 10 f�vr. 2012
    copyright            : (C) 2012 par arnaud
*************************************************************************/

//---------- R�alisation de la classe <CommandeCreationLigne> (fichier CommandeCreationLigne.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "CommandeCreationLigne.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
// type CommandeCreationLigne::M�thode ( liste des param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode


//------------------------------------------------- Surcharge d'op�rateurs
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

//----------------------------------------------------- M�thodes prot�g�es
