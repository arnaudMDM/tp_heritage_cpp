/*************************************************************************
                           CommandeDirect  -  description
                             -------------------
    début                : 10 févr. 2012
    copyright            : (C) 2012 par Pitou
*************************************************************************/

//---------- Réalisation de la classe <CommandeDirect> (fichier CommandeDirect.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "CommandeDirect.h"
#include "../Modele/ObjetGeometrique.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type CommandeDirect::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
void CommandeDirect::execute()
{
	fct_commande();
}

void CommandeDirect::undo()
{
	cout<<"undo impossible sur cette commande"<<endl;
}

void CommandeDirect::redo()
{
	cout<<"redo impossible sur cette commande"<<endl;
}

//------------------------------------------------- Surcharge d'opérateurs
CommandeDirect & CommandeDirect::operator = ( const CommandeDirect & unCommandeDirect )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
//CommandeDirect::CommandeDirect ( const CommandeDirect & unCommandeDirect )
//// Algorithme :
////
//{
//#ifdef MAP
//    cout << "Appel au constructeur de copie de <CommandeDirect>" << endl;
//#endif
//} //----- Fin de CommandeDirect (constructeur de copie)


CommandeDirect::CommandeDirect (ObjetGeometrique  * nouveauContexte, void (*commandeAExecuter) () ) :
		Commande(nouveauContexte, false)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <CommandeDirect>" << endl;
#endif
} //----- Fin de CommandeDirect


CommandeDirect::~CommandeDirect ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CommandeDirect>" << endl;
#endif
} //----- Fin de ~CommandeDirect


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

