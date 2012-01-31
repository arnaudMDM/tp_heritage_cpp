/*************************************************************************
                           ObjetGeometrique  -  description
                             -------------------
    d�but                : 31 janv. 2012
    copyright            : (C) 2012 par arnaud
*************************************************************************/

//---------- R�alisation de la classe <ObjetGeometrique> (fichier ObjetGeometrique.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>
#include <vector>

//------------------------------------------------------ Include personnel
#include "ObjetGeometrique.h"
#include "EltGeometrique.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
// type ObjetGeometrique::M�thode ( liste des param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode


//------------------------------------------------- Surcharge d'op�rateurs
ObjetGeometrique & ObjetGeometrique::operator = ( const ObjetGeometrique & unObjetGeometrique )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
ObjetGeometrique::ObjetGeometrique ( const ObjetGeometrique & unObjetGeometrique )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <ObjetGeometrique>" << endl;
#endif
} //----- Fin de ObjetGeometrique (constructeur de copie)


ObjetGeometrique::ObjetGeometrique ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <ObjetGeometrique>" << endl;
#endif
} //----- Fin de ObjetGeometrique


ObjetGeometrique::~ObjetGeometrique ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <ObjetGeometrique>" << endl;
#endif
}

vector<EltGeometrique> ObjetGeometrique::getListeEltsGeom() const
{
    return listeEltsGeom;
}

 //----- Fin de ~ObjetGeometrique


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es
