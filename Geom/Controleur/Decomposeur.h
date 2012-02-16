/*************************************************************************
                           Decomposeur  -  description
                             -------------------
    début                : 9 févr. 2012
    copyright            : (C) 2012 par Pitou
*************************************************************************/

//---------- Interface du module <Decomposeur> (fichier Decomposeur.h) ---------
#if ! defined ( DECOMPOSEUR_H_ )
#define DECOMPOSEUR_H_

//------------------------------------------------------------------------ 
// Rôle du module <Decomposeur>
//
//
//------------------------------------------------------------------------ 

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <vector>
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques

void LireCommande(vector <string *> &para, string &requete);
//Lit sur l'entre standard et valorise la liste et la chaine avec le contenu
void DecomposerCommande(vector <string *> &para, string *requete);
//Decompose la chaine en une liste de chaine, le separateur est l'espace
#endif // DECOMPOSEUR_H_
