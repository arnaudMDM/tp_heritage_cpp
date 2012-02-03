/*************************************************************************
                           CommandeCreationCercle  -  description
                             -------------------
    début                : 3 févr. 2012
    copyright            : (C) 2012 par Pitou
*************************************************************************/

//---------- Réalisation de la classe <CommandeCreationCercle> (fichier CommandeCreationCercle.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <cstdlib>
//------------------------------------------------------ Include personnel
#include "CommandeCreationCercle.h"
#include "../Modele/Cercle.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type CommandeCreationCercle::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void CommandeCreationCercle::execute()
{
	element = new Cercle(x1,y1,rayon);
	contexte->getListeEltsGeom().push_back(element);
}

void CommandeCreationCercle::undo()
{

}

void CommandeCreationCercle::redo()
{

}
//------------------------------------------------- Surcharge d'opérateurs
//CommandeCreationCercle & CommandeCreationCercle::operator = ( const CommandeCreationCercle & unCommandeCreationCercle )
//// Algorithme :
////
//{
//} //----- Fin de operator =
//
//
////-------------------------------------------- Constructeurs - destructeur
//CommandeCreationCercle::CommandeCreationCercle ( const CommandeCreationCercle & unCommandeCreationCercle )
//// Algorithme :
////
//{
//#ifdef MAP
//    cout << "Appel au constructeur de copie de <CommandeCreationCercle>" << endl;
//#endif
//} //----- Fin de CommandeCreationCercle (constructeur de copie)


CommandeCreationCercle::CommandeCreationCercle (char *abs, char *ord, char *ray, ObjetGeometrique *leContexte) : CommandeCreation(leContexte)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <CommandeCreationCercle>" << endl;
#endif
    x1 = atoi(abs);
    y1 = atoi(ord);
    rayon = atoi(ray);
} //----- Fin de CommandeCreationCercle


CommandeCreationCercle::~CommandeCreationCercle ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CommandeCreationCercle>" << endl;
#endif
} //----- Fin de ~CommandeCreationCercle


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

