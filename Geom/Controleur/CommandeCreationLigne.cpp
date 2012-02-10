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
#include "cstdlib"
//------------------------------------------------------ Include personnel
#include "CommandeCreationLigne.h"
#include "../Modele/Service.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC
void CommandeCreationLigne::execute()
{

}

void CommandeCreationLigne::undo()
{

}

void CommandeCreationLigne::redo()
{

}
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
//CommandeCreationLigne::CommandeCreationLigne ( const CommandeCreationLigne & unCommandeCreationLigne )
//// Algorithme :
////
//{
//#ifdef MAP
//    cout << "Appel au constructeur de copie de <CommandeCreationLigne>" << endl;
//#endif
//} //----- Fin de CommandeCreationLigne (constructeur de copie)

bool IsDigit(string nom);
CommandeCreationLigne::CommandeCreationLigne (vector < string *> para, ObjetGeometrique *leContexte) :
		CommandeCreation(leContexte)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <CommandeCreationLigne>" << endl;
#endif

    string tmp;
	bool sontEntiers(true);

	vector<string *>::iterator it = para.begin();
	tmp += (*it)->c_str();
	it++;

	for(; it == para.end(); it++)
	{

		tmp +=" ";
		tmp +=(*it)->c_str();
		if(!IsDigit((*it)->c_str()))
		{
			sontEntiers = false;
		}
	}

	if(para.size() == TAILLE_COMMANDE_LIGNE && sontEntiers)
	{
		x1 = atoi(para.at(1)->c_str());
		x2 = atoi(para.at(2)->c_str());
		y1 = atoi(para.at(3)->c_str());
		y2 = atoi(para.at(4)->c_str());
		tmp +=" OK\n";
	}
	else
	{
		tmp += "\n";
		tmp += CHAINE_PARA_INVALIDE;
		texteCommande += "Err ";
	}

	texteCommande += tmp;

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
