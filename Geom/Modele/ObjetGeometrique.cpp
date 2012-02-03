/*************************************************************************
                           ObjetGeometrique  -  description
                             -------------------
    début                : 31 janv. 2012
    copyright            : (C) 2012 par arnaud
*************************************************************************/

//---------- Réalisation de la classe <ObjetGeometrique> (fichier ObjetGeometrique.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "ObjetGeometrique.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type ObjetGeometrique::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


string ObjetGeometrique::DescriptionEltsSelect()
// Algorithme :
//
{
	string description = NULL;
	for(vector<EltGeometrique *>::iterator it = listeEltsGeomSelect.begin() ; it!=listeEltsGeomSelect.end() ; it++)
	{
		description.append((*it)->Description());
	}
	return description;
} //----- Fin de Méthode


string ObjetGeometrique::DescriptionEltsTotal()
// Algorithme :
//
{
	string description = NULL;
	for(vector<EltGeometrique *>::iterator it = listeEltsGeomTotal.begin() ; it!=listeEltsGeomTotal.end() ; it++)
	{
		description.append((*it)->Description());
	}
	return description;
} //----- Fin de Méthode


int ObjetGeometrique::NbElts()
// Algorithme :
//
{
	return listeEltsGeomTotal.size();
} //----- Fin de Méthode


void ObjetGeometrique::SupprimerTousElts()
// Algorithme :
//
{
	listeEltsGeomTotal.clear();
	listeEltsGeomSelect.clear();
} //----- Fin de Méthode


void ObjetGeometrique::SupprimerElts()
// Algorithme :
//
{
	for(vector<EltGeometrique *>::iterator it = listeEltsGeomSelect.begin() ; it!=listeEltsGeomSelect.end() ; it++)
	{
		listeEltsGeomTotal.erase(it);
	}
	listeEltsGeomSelect.clear();
} //----- Fin de Méthode


void ObjetGeometrique::Translater(int x, int y)
// Algorithme :
//
{
	for(vector<EltGeometrique *>::iterator it = listeEltsGeomSelect.begin() ; it!=listeEltsGeomSelect.end() ; it++)
	{
		(*it)->Translater(x, y);
	}
} //----- Fin de Méthode


void ObjetGeometrique::SelectionnerElts(int x1, int y1, int x2, int y2)
// Algorithme :
//
{
	listeEltsGeomSelect.clear();
	for(vector<EltGeometrique *>::iterator it = listeEltsGeomTotal.begin() ; it!=listeEltsGeomTotal.end() ; it++)
	{
		if((*it)->Appartient(x1,y1,x2,y2))
		{
			listeEltsGeomSelect.push_back(*it);
		}
	}
} //----- Fin de Méthode


void ObjetGeometrique::AjouterEltGeom(EltGeometrique *unEltGeometrique)
// Algorithme :
//
{
	listeEltsGeomTotal.push_back(unEltGeometrique);
} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
ObjetGeometrique & ObjetGeometrique::operator = ( const ObjetGeometrique & unObjetGeometrique )
// Algorithme :
//
{
	listeEltsGeomTotal.assign(unObjetGeometrique.getListeEltsGeomTotal().begin(),unObjetGeometrique.getListeEltsGeomTotal().end());
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
    listeEltsGeomTotal.assign(unObjetGeometrique.getListeEltsGeomTotal().begin(),unObjetGeometrique.getListeEltsGeomTotal().end());
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
    listeEltsGeomTotal.assign(uneListeEltsGeom.begin(),uneListeEltsGeom.end());
}



vector<EltGeometrique*> ObjetGeometrique::getListeEltsGeomTotal() const
{
    return listeEltsGeomTotal;
}

vector<EltGeometrique*> ObjetGeometrique::getListeEltsGeomSelect() const
{
    return listeEltsGeomSelect;
}

 //----- Fin de ~ObjetGeometrique


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
