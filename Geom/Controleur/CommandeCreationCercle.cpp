/*************************************************************************
                           CommandeCreationCercle  -  description
                             -------------------
    d�but                : 3 f�vr. 2012
    copyright            : (C) 2012 par Pitou
*************************************************************************/

//---------- R�alisation de la classe <CommandeCreationCercle> (fichier CommandeCreationCercle.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <cstdlib>
//------------------------------------------------------ Include personnel
#include "CommandeCreationCercle.h"
#include "../Modele/Cercle.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
// type CommandeCreationCercle::M�thode ( liste des param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode

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
//------------------------------------------------- Surcharge d'op�rateurs
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

//----------------------------------------------------- M�thodes prot�g�es

