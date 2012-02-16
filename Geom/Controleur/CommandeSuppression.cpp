/*************************************************************************
 CommandeSuppression  -  description
 -------------------
 début                : 12 févr. 2012
 copyright            : (C) 2012 par Pitou
 *************************************************************************/

//---------- Réalisation de la classe <CommandeSuppression> (fichier CommandeSuppression.cpp) -------
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <sstream>
//------------------------------------------------------ Include personnel
#include "CommandeSuppression.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void CommandeSuppression::Execute ( )
{
	contexte->Deselectionner ( );
	contexte->SupprimerElts ( elementsSupprimes );
} //----- Fin de Execute

void CommandeSuppression::Redo ( )
{
	Execute ( );
} //----- Fin de Redo

void CommandeSuppression::Undo ( )
{
	contexte->AjouterEltGeom ( elementsSupprimes );
} //----- Fin de Undo
//------------------------------------------------- Surcharge d'opérateurs

////-------------------------------------------- Constructeurs - destructeur

CommandeSuppression::CommandeSuppression ( ObjetGeometrique *nouveauContexte,
        typeEtatSuppression etat ) :
		Commande ( nouveauContexte ), etatSuppression ( etat )
// Algorithme : selon la valeur de l'enumeration, retenu des EltGeometrique
// selectionnes ou la totalite
//
{
#ifdef MAP
	cout << "Appel au constructeur de <CommandeSuppression>" << endl;
#endif
	stringstream convertisseur;
	switch (etat)
	{
		case DELETE:
			elementsSupprimes = nouveauContexte->getListeEltsGeomSelect ( );
			convertisseur << elementsSupprimes.size ( );
			texteCommande = convertisseur.str ( );
			break;

		case CLEAR:
			elementsSupprimes = nouveauContexte->getListeEltsGeomTotal ( );
			texteCommande = OK + "CLEAR";
			break;
	}
} //----- Fin de CommandeSuppression

CommandeSuppression::~CommandeSuppression ( )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <CommandeSuppression>" << endl;
#endif
} //----- Fin de ~CommandeSuppression

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

