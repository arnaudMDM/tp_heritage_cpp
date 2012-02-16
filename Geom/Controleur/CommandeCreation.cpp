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
void CommandeCreation::Undo ( )
{
	contexte->SupprimerEltParticulier ( element );
	contexte->Deselectionner ( );
}

void CommandeCreation::Redo ( )
{
	contexte->AjouterEltGeom ( element );
	contexte->Deselectionner ( );
}

//------------------------------------------------- Surcharge d'opérateurs

////-------------------------------------------- Constructeurs - destructeur

CommandeCreation::CommandeCreation ( ObjetGeometrique *unContexte ) :
		Commande ( unContexte ), element ( NULL )
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
	delete element;
} //----- Fin de ~CommandeCreation

//------------------------------------------------------------------ PRIVE
void CommandeCreation::selectionElt ( )
{
	contexte->Deselectionner ( );
	contexte->SelectionnerElt ( element );
}
//----------------------------------------------------- Méthodes protégées

