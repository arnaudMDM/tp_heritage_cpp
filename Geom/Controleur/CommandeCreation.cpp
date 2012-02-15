/*************************************************************************
 CommandeCreation  -  description
 -------------------
 d�but                : 27 janv. 2012
 copyright            : (C) 2012 par Pitou
 *************************************************************************/

//---------- R�alisation de la classe <CommandeCreation> (fichier CommandeCreation.cpp) -------
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "CommandeCreation.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
// type CommandeCreation::M�thode ( liste des param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode
void CommandeCreation::Undo ( )
{
	contexte->SupprimerEltParticulier(element);
	contexte->Deselectionner();
}

void CommandeCreation::Redo ( )
{
	contexte->AjouterEltGeom(element);
	contexte->Deselectionner();
}

//------------------------------------------------- Surcharge d'op�rateurs
//CommandeCreation & CommandeCreation::operator = ( const CommandeCreation & unCommandeCreation )
//// Algorithme :
////
//{
//} //----- Fin de operator =
//
//
////-------------------------------------------- Constructeurs - destructeur
//CommandeCreation::CommandeCreation ( const CommandeCreation & unCommandeCreation )
//// Algorithme :
////
//{
//#ifdef MAP
//    cout << "Appel au constructeur de copie de <CommandeCreation>" << endl;
//#endif
//    throw string("CommandeCreation::CommandeCreation ( const CommandeCreation & unCommandeCreation )");
//} //----- Fin de CommandeCreation (constructeur de copie)

CommandeCreation::CommandeCreation ( ObjetGeometrique *unContexte ) :
		Commande(unContexte), element(NULL)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <CommandeCreation>" << endl;
#endif
}    //----- Fin de CommandeCreation

CommandeCreation::~CommandeCreation ( )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <CommandeCreation>" << endl;
#endif
	delete element;
}    //----- Fin de ~CommandeCreation

//------------------------------------------------------------------ PRIVE
void CommandeCreation::selectionElt()
{
	contexte->Deselectionner();
	contexte->SelectionnerElt(element);
}
//----------------------------------------------------- M�thodes prot�g�es

