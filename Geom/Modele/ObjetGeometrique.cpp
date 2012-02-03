/*************************************************************************
                           ObjetGeometrique  -  description
                             -------------------
    début                : 31 janv. 2012
    copyright            : (C) 2012 par arnaud
*************************************************************************/

//---------- Réalisation de la classe <ObjetGeometrique> (fichier ObjetGeometrique.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <vector>

//------------------------------------------------------ Include personnel
#include "ObjetGeometrique.h"
#include "EltGeometrique.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type ObjetGeometrique::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
ObjetGeometrique & ObjetGeometrique::operator = ( const ObjetGeometrique & unObjetGeometrique )
// Algorithme :
//
{
	listeEltsGeom.assign(unObjetGeometrique.getListeEltsGeom().begin(),unObjetGeometrique.getListeEltsGeom().end());
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
ObjetGeometrique::ObjetGeometrique ( const ObjetGeometrique & unObjetGeometrique )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <ObjetGeometrique>" << endl;
#endif
    listeEltsGeom.assign(unObjetGeometrique.getListeEltsGeom().begin(),unObjetGeometrique.getListeEltsGeom().end());
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


ObjetGeometrique::ObjetGeometrique (vector <EltGeometrique*> uneListeEltsGeom)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <ObjetGeometrique>" << endl;
#endif
    listeEltsGeom.assign(uneListeEltsGeom.begin(),uneListeEltsGeom.end());
}


vector<EltGeometrique*> ObjetGeometrique::getListeEltsGeom() const
{
    return listeEltsGeom;
}

 //----- Fin de ~ObjetGeometrique


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
