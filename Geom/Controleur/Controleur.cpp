/*************************************************************************
                           Controleur  -  description
                             -------------------
    début                : 27 janv. 2012
    copyright            : (C) 2012 par Pitou
*************************************************************************/

//---------- Réalisation de la classe <Controleur> (fichier Controleur.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <sstream>

//------------------------------------------------------ Include personnel
#include "Controleur.h"
#include "Decomposeur.h"
//------------------------------------------------------------- Constantes
static const string COMMANDE_LISTE = "LIST";
static const string COMMANDE_COUNT = "COUNT";
static const string COMMANDE_EXIT = "EXIT";
static const string COMMANDE_UNDO = "UNDO";
static const string COMMANDE_REDO = "REDO";
static const char COMMANDE_SEL = 'S';
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Controleur::traitementCommande()
// Algorithme :
//
{
	cout<<"Bienvenue dans le programme Geom.\nVeuilliez saisir votre commande : "<<endl;

	while (!quitter)
	{
		LireCommande(parametres);

		string nomCommande = *(parametres.front());
		if(nomCommande.find(COMMANDE_LISTE) != string::npos)
		{
			cout<<"tentative de listage ! "<<endl;
		} else if (nomCommande.find(COMMANDE_COUNT) != string::npos)
		{
			cout<<"Count"<<endl;
		}else if (nomCommande.find(COMMANDE_EXIT) != string::npos)
		{
			cout<<"Quitter"<<endl;
			quitter = true;
		}else if (nomCommande.find(COMMANDE_UNDO) != string::npos)
		{
			cout<<"Un Undo"<<endl;
		}else if (nomCommande.find(COMMANDE_REDO) != string::npos)
		{
			cout<<"Un Redo"<<endl;
		}else if (nomCommande.at(0)==COMMANDE_SEL && nomCommande.size() == 1)
		{
			cout<<"Selection"<<endl;
		}

		while(!parametres.empty())
		{
			parametres.pop();
		}
	}
	cout<<"Sortie du prg"<<endl;

} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
Controleur & Controleur::operator = ( const Controleur & unControleur )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Controleur::Controleur ( const Controleur & unControleur )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Controleur>" << endl;
#endif
} //----- Fin de Controleur (constructeur de copie)


Controleur::Controleur ( ):
		quitter(false)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Controleur>" << endl;
#endif
} //----- Fin de Controleur


Controleur::~Controleur ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Controleur>" << endl;
#endif
} //----- Fin de ~Controleur


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

