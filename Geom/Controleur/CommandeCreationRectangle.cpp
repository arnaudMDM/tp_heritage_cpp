/*************************************************************************
 CommandeCreationRectangle  -  description
 -------------------
 début                : 12 févr. 2012
 copyright            : (C) 2012 par Pitou
 *************************************************************************/

//---------- Réalisation de la classe <CommandeCreationRectangle> (fichier CommandeCreationRectangle.cpp) -------
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstdlib>
//------------------------------------------------------ Include personnel
#include "CommandeCreationRectangle.h"
#include "../Modele/Rectangle.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type CommandeCreationRectangle::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void CommandeCreationRectangle::execute ( )
{
	if (status)
	{
		element = new Rectangle(x1, y1, x2, y2);
		contexte->AjouterEltGeom(element);
	}
}

//------------------------------------------------- Surcharge d'opérateurs
//CommandeCreationRectangle & CommandeCreationRectangle::operator = ( const CommandeCreationRectangle & unCommandeCreationRectangle )
//// Algorithme :
////
//{
//} //----- Fin de operator =
//
//
////-------------------------------------------- Constructeurs - destructeur
//CommandeCreationRectangle::CommandeCreationRectangle ( const CommandeCreationRectangle & unCommandeCreationRectangle )
//// Algorithme :
////
//{
//#ifdef MAP
//    cout << "Appel au constructeur de copie de <CommandeCreationRectangle>" << endl;
//#endif
//} //----- Fin de CommandeCreationRectangle (constructeur de copie)

CommandeCreationRectangle::CommandeCreationRectangle ( vector<string *> para,
		ObjetGeometrique *unContexte, const string *requete ) :
		CommandeCreation(unContexte)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <CommandeCreationRectangle>" << endl;
#endif
	bool correct(true);

	if (para.size() == NB_PARAM_CREAT_RECT)
	{

		vector<string*>::iterator it = para.begin() + 1;

		while (it != para.end() && correct)
		{
			if (!IsInteger(**it))
			{
				correct = false;
			}
			it++;
		}
	}

	if(correct)
	{
		x1 = atoi((para.at(1))->c_str());

		y1 = atoi((para.at(2))->c_str());

		x2 = atoi((para.at(3))->c_str());

		y2 = atoi((para.at(4))->c_str());

		texteCommande = OK + *requete;
	}
	else
	{
		texteCommande = ERREUR + *requete;
		status = false;
	}
}    //----- Fin de CommandeCreationRectangle

CommandeCreationRectangle::~CommandeCreationRectangle ( )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <CommandeCreationRectangle>" << endl;
#endif
}    //----- Fin de ~CommandeCreationRectangle

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

