/*************************************************************************
                           CommandeDeplac  -  description
                             -------------------
    d�but                : 12 f�vr. 2012
    copyright            : (C) 2012 par Pitou
*************************************************************************/

//---------- R�alisation de la classe <CommandeDeplac> (fichier CommandeDeplac.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>
#include <cstdlib>
#include <sstream>
//------------------------------------------------------ Include personnel
#include "CommandeDeplac.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
// type CommandeDeplac::M�thode ( liste des param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode

void CommandeDeplac::Execute()
{
	contexte->Translater(deltaX, deltaY);
}

void CommandeDeplac::Redo()
{
	contexte->SelectionnerElts(elementsDeplaces);
	contexte->Translater(deltaX, deltaY);
}

void CommandeDeplac::Undo()
{
	contexte->SelectionnerElts(elementsDeplaces);
	contexte->Translater(-deltaX, -deltaY);
	contexte->Deselectionner();
}
//------------------------------------------------- Surcharge d'op�rateurs
//CommandeDeplac & CommandeDeplac::operator = ( const CommandeDeplac & unCommandeDeplac )
//// Algorithme :
////
//{
//} //----- Fin de operator =
//
//
////-------------------------------------------- Constructeurs - destructeur
//CommandeDeplac::CommandeDeplac ( const CommandeDeplac & unCommandeDeplac )
//// Algorithme :
////
//{
//#ifdef MAP
//    cout << "Appel au constructeur de copie de <CommandeDeplac>" << endl;
//#endif
//} //----- Fin de CommandeDeplac (constructeur de copie)


CommandeDeplac::CommandeDeplac (vector <string *> para, ObjetGeometrique *unContexte, const string *requete):
		Commande (unContexte)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <CommandeDeplac>" << endl;
#endif

    deltaX = atoi(para.at(1)->c_str());
    deltaY = atoi(para.at(2)->c_str());

    texteCommande = OK + *requete;
} //----- Fin de CommandeDeplac


CommandeDeplac::~CommandeDeplac ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CommandeDeplac>" << endl;
#endif
} //----- Fin de ~CommandeDeplac


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

