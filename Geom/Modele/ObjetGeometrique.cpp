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

string ObjetGeometrique::DescriptionEltsSelect ( )
// Algorithme : rend un string coorespondant au string de chaque création des
//élémentsGéométriques de liste des élémentsGéométriques sélectionnés
//
{
	string description;
	for (vector<EltGeometrique *>::iterator it = listeEltsGeomSelect.begin();
			it != listeEltsGeomSelect.end(); it++)
			{
		description.append((*it)->Description());
	}
	return description;
}    //----- Fin de Méthode

string ObjetGeometrique::DescriptionEltsTotal ( )
// Algorithme : rend un string coorespondant au string de chaque création des
//élémentsGéométriques de liste des élémentsGéométriques totals
//
{
	string description;
	for (vector<EltGeometrique *>::iterator it = listeEltsGeomTotal.begin();
			it != listeEltsGeomTotal.end(); it++)
			{
		description.append((*it)->Description());
	}
	return description;
}    //----- Fin de Méthode

int ObjetGeometrique::NbEltsTotals ( )
// Algorithme : rend la taille de la liste des élémentsGéométriques totals
//
{
	return listeEltsGeomTotal.size();
}    //----- Fin de Méthode

void ObjetGeometrique::SupprimerTousElts ( )
// Algorithme :
//
{
	listeEltsGeomTotal.clear();
	listeEltsGeomSelect.clear();
}    //----- Fin de Méthode

void ObjetGeometrique::SupprimerEltsSelectionnes ( )
// Algorithme : méthode qui enlèvent de la liste des élémentsGéométriques totals
// et de la liste des élémentsGéométriques sélectionnés les élémentsGéométriques sélectionnés
//
{
	for (vector<EltGeometrique *>::iterator it = listeEltsGeomSelect.begin();
			it != listeEltsGeomSelect.end(); it++)
			{
		listeEltsGeomTotal.erase(it);
	}
	listeEltsGeomSelect.clear();
}    //----- Fin de Méthode

void ObjetGeometrique::Deselectionner ( )
// Algorithme : méthode qui enlèvent de la liste des élémentsGéométriques totals
// et de la liste des élémentsGéométriques sélectionnés les élémentsGéométriques sélectionnés
//
{
	listeEltsGeomSelect.clear();
}    //----- Fin de Méthode

void ObjetGeometrique::SupprimerEltParticulier ( EltGeometrique *elt )
// Algorithme : enlève un élémentGéométrique de liste des élémentGéométrique totals
//
{
	bool trouve(false);

	vector<EltGeometrique *>::iterator it = listeEltsGeomTotal.begin();
	while (it != listeEltsGeomTotal.end() && !trouve)
	{
		if (*it == elt)
		{
			listeEltsGeomTotal.erase(it);
			trouve = true;
		}
	}

}    //----- Fin de Méthode

void ObjetGeometrique::Translater ( int x, int y )
// Algorithme :translate tous les élémentsGéométriques sélectionnés de x et y
//
{
	for (vector<EltGeometrique *>::iterator it = listeEltsGeomSelect.begin();
			it != listeEltsGeomSelect.end(); it++)
			{
		(*it)->Translater(x, y);
	}
}    //----- Fin de Méthode

int ObjetGeometrique::SelectionnerElts ( int x1, int y1, int x2, int y2 )
// Algorithme : recherche quels sont les éléments se trouvant à l'intérieur de
// ce rectangle définit par les deux points de la diagonales. Les éléments qui sont
// dans ce rectangle deviennent la nouvelle liste des élémentsGéométriques sélectionnés
//
{
	listeEltsGeomSelect.clear();
	for (vector<EltGeometrique *>::iterator it = listeEltsGeomTotal.begin();
			it != listeEltsGeomTotal.end(); it++)
	{
		if ((*it)->Appartient(x1, y1, x2, y2))
		{
			listeEltsGeomSelect.push_back(*it);
		}
	}
	return listeEltsGeomSelect.size();
}    //----- Fin de Méthode

void ObjetGeometrique::AjouterEltGeom ( EltGeometrique *unEltGeometrique )
// Algorithme : ajoute un élément à la liste des élémentsGéométriques totals
//
{
	listeEltsGeomTotal.push_back(unEltGeometrique);
}    //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
ObjetGeometrique & ObjetGeometrique::operator = (
		const ObjetGeometrique & unObjetGeometrique )
// Algorithme :
//
{
	listeEltsGeomTotal.assign(
			unObjetGeometrique.getListeEltsGeomTotal().begin(),
			unObjetGeometrique.getListeEltsGeomTotal().end());
	return *this;
}    //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
ObjetGeometrique::ObjetGeometrique (
		const ObjetGeometrique & unObjetGeometrique )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <ObjetGeometrique>" << endl;
#endif
	listeEltsGeomTotal.assign(
			unObjetGeometrique.getListeEltsGeomTotal().begin(),
			unObjetGeometrique.getListeEltsGeomTotal().end());
}    //----- Fin de ObjetGeometrique (constructeur de copie)

ObjetGeometrique::ObjetGeometrique ( )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <ObjetGeometrique>" << endl;
#endif

}    //----- Fin de ObjetGeometrique

ObjetGeometrique::~ObjetGeometrique ( )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <ObjetGeometrique>" << endl;
#endif
}

ObjetGeometrique::ObjetGeometrique ( vector<EltGeometrique*> uneListeEltsGeom )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <ObjetGeometrique>" << endl;
#endif
	listeEltsGeomTotal.assign(uneListeEltsGeom.begin(), uneListeEltsGeom.end());
}

vector<EltGeometrique*> ObjetGeometrique::getListeEltsGeomTotal ( ) const
{
	return listeEltsGeomTotal;
}

vector<EltGeometrique*> ObjetGeometrique::getListeEltsGeomSelect ( ) const
{
	return listeEltsGeomSelect;
}

//----- Fin de ~ObjetGeometrique

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
