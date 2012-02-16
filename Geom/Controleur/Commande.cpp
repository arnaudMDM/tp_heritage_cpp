/*************************************************************************
 Commande  -  description
 -------------------
 d�but                : 3 f�vr. 2012
 copyright            : (C) 2012 par Pitou
 *************************************************************************/

//---------- R�alisation de la classe <Commande> (fichier Commande.cpp) -------
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Commande.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
string Commande::getTexteCommande ( )
{
	return texteCommande;
}

//------------------------------------------------- Surcharge d'op�rateurs

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

//----------------------------------------------------- M�thodes prot�g�es

