/*************************************************************************
                           Decomposeur  -  description
                             -------------------
    d�but                : 9 f�vr. 2012
    copyright            : (C) 2012 par Pitou
*************************************************************************/

//---------- Interface du module <Decomposeur> (fichier Decomposeur.h) ---------
#if ! defined ( DECOMPOSEUR_H_ )
#define DECOMPOSEUR_H_

//------------------------------------------------------------------------ 
// R�le du module <Decomposeur>
//
//
//------------------------------------------------------------------------ 

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilis�es
#include <string>
#include <vector>
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques

void LireCommande(vector <string *> &para, string *requete);
void DecomposerCommande(vector <string *> &para, string *requete);
#endif // DECOMPOSEUR_H_
