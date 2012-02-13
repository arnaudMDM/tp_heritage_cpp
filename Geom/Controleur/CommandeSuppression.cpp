/*************************************************************************
 CommandeSuppression  -  description
 -------------------
 d�but                : 12 f�vr. 2012
 copyright            : (C) 2012 par Pitou
 *************************************************************************/

//---------- R�alisation de la classe <CommandeSuppression> (fichier CommandeSuppression.cpp) -------
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>
#include <sstream>
//------------------------------------------------------ Include personnel
#include "CommandeSuppression.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
// type CommandeSuppression::M�thode ( liste des param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode
void CommandeSuppression::Execute()
{
	contexte->Deselectionner();
	contexte->SupprimerElts(elementsSupprimes);
}

void CommandeSuppression::Redo()
{
	Execute();
}

void CommandeSuppression::Undo()
{
	contexte->AjouterEltGeom(elementsSupprimes);
}
//------------------------------------------------- Surcharge d'op�rateurs
//CommandeSuppression & CommandeSuppression::operator = ( const CommandeSuppression & unCommandeSuppression )
//// Algorithme :
////
//{
//} //----- Fin de operator =
//
//
////-------------------------------------------- Constructeurs - destructeur
//CommandeSuppression::CommandeSuppression ( const CommandeSuppression & unCommandeSuppression )
//// Algorithme :
////
//{
//#ifdef MAP
//    cout << "Appel au constructeur de copie de <CommandeSuppression>" << endl;
//#endif
//} //----- Fin de CommandeSuppression (constructeur de copie)

CommandeSuppression::CommandeSuppression (ObjetGeometrique *nouveauContexte,
		typeEtatSuppression etat) :
		Commande(nouveauContexte), etatSuppression(etat)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <CommandeSuppression>" << endl;
#endif
	stringstream convertisseur;
	switch (etat)
	{
		case DELETE:
			elementsSupprimes = nouveauContexte->getListeEltsGeomSelect();
			convertisseur << elementsSupprimes.size();
			texteCommande = convertisseur.str();
			break;

		case CLEAR:
			elementsSupprimes = nouveauContexte->getListeEltsGeomTotal();
			texteCommande = OK + "CLEAR";
			break;
	}
}    //----- Fin de CommandeSuppression

CommandeSuppression::~CommandeSuppression ( )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <CommandeSuppression>" << endl;
#endif
}    //----- Fin de ~CommandeSuppression

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

