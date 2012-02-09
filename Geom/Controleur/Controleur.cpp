/*************************************************************************
                           Controleur  -  description
                             -------------------
    d�but                : 27 janv. 2012
    copyright            : (C) 2012 par Pitou
*************************************************************************/

//---------- R�alisation de la classe <Controleur> (fichier Controleur.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>
#include <sstream>

//------------------------------------------------------ Include personnel
#include "Controleur.h"
#include "Decomposeur.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
void Controleur::traitementCommande()
// Algorithme :
//
{


	cout<<"Bienvenue dans le programme Geom.\nVeulliez saisir votre commande : "<<endl;

	int i = 0;
	while (!quitter)
	{
		string temp;
		cin.clear();
		cin.seekg(0,ios::end);
		cin.clear();
		cin>>temp;
		Decompose(parametres, temp);

		while (!parametres.empty())
		{
			cout<<"Mot : "<<*(parametres.front())<<endl;
			parametres.pop();
		}
		i++;
		if (i==2) quitter = true;
	}

} //----- Fin de M�thode


//------------------------------------------------- Surcharge d'op�rateurs
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

//----------------------------------------------------- M�thodes prot�g�es

