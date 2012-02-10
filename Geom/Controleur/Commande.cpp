/*************************************************************************
                           Commande  -  description
                             -------------------
    début                : 3 févr. 2012
    copyright            : (C) 2012 par Pitou
*************************************************************************/

//---------- Réalisation de la classe <Commande> (fichier Commande.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Commande.h"

//------------------------------------------------------------- Constantes
const string Commande::CHAINE_PARA_INVALIDE = "\n#invalid parameters";
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool Commande::IsOk()
{
	return status;
}

string Commande::getTexteCommande()
{
	return texteCommande;
}

//------------------------------------------------- Surcharge d'opérateurs
//Commande & Commande::operator = ( const Commande & unCommande )
//// Algorithme :
////
//{
//} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
//Commande::Commande ( const Commande & unCommande )
//// Algorithme :
////
//{
//#ifdef MAP
//    cout << "Appel au constructeur de copie de <Commande>" << endl;
//#endif
//} //----- Fin de Commande (constructeur de copie)


Commande::Commande (ObjetGeometrique *nouveauContexte, bool statusHistorique) :
		contexte(nouveauContexte), status(true)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Commande>" << endl;
#endif
    if(contexte == NULL)
    	{
    		cout<<"Erreur contexte vide"<<endl;
    	}
} //----- Fin de Commande


Commande::~Commande ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Commande>" << endl;
#endif
} //----- Fin de ~Commande


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

