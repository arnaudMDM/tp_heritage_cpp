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

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
string Commande::getTexteCommande ( )
{
	return texteCommande;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Commande::Commande ( ObjetGeometrique *nouveauContexte ) :
		contexte ( nouveauContexte )
{
#ifdef MAP
	cout << "Appel au constructeur de <Commande>" << endl;
#endif
	if ( contexte == NULL )
	{
		cout << "Erreur contexte vide" << endl;
	}
} //----- Fin de Commande

Commande::~Commande ( )
{
#ifdef MAP
	cout << "Appel au destructeur de <Commande>" << endl;
#endif

} //----- Fin de ~Commande

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

