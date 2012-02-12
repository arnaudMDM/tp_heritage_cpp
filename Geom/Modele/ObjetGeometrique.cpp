/*************************************************************************
 ObjetGeometrique  -  description
 -------------------
 d�but                : 31 janv. 2012
 copyright            : (C) 2012 par arnaud
 *************************************************************************/

//---------- R�alisation de la classe <ObjetGeometrique> (fichier ObjetGeometrique.cpp) -------
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include syst�me
#include <iostream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "ObjetGeometrique.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
// type ObjetGeometrique::M�thode ( liste des param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode

string ObjetGeometrique::DescriptionEltsSelect ( )
// Algorithme : rend un string coorespondant au string de chaque cr�ation des
//�l�mentsG�om�triques de liste des �l�mentsG�om�triques s�lectionn�s
//
{
	string description;
	for (vector<EltGeometrique *>::iterator it = listeEltsGeomSelect.begin();
			it != listeEltsGeomSelect.end(); it++)
			{
		description.append((*it)->Description());
	}
	return description;
}    //----- Fin de M�thode

string ObjetGeometrique::DescriptionEltsTotal ( )
// Algorithme : rend un string coorespondant au string de chaque cr�ation des
//�l�mentsG�om�triques de liste des �l�mentsG�om�triques totals
//
{
	string description;
	for (vector<EltGeometrique *>::iterator it = listeEltsGeomTotal.begin();
			it != listeEltsGeomTotal.end(); it++)
			{
		description.append((*it)->Description());
	}
	return description;
}    //----- Fin de M�thode

int ObjetGeometrique::NbEltsTotals ( )
// Algorithme : rend la taille de la liste des �l�mentsG�om�triques totals
//
{
	return listeEltsGeomTotal.size();
}    //----- Fin de M�thode

void ObjetGeometrique::SupprimerTousElts ( )
// Algorithme :
//
{
	listeEltsGeomTotal.clear();
	listeEltsGeomSelect.clear();
}    //----- Fin de M�thode

void ObjetGeometrique::SupprimerEltsSelectionnes ( )
// Algorithme : m�thode qui enl�vent de la liste des �l�mentsG�om�triques totals
// et de la liste des �l�mentsG�om�triques s�lectionn�s les �l�mentsG�om�triques s�lectionn�s
//
{
	for (vector<EltGeometrique *>::iterator it = listeEltsGeomSelect.begin();
			it != listeEltsGeomSelect.end(); it++)
			{
		listeEltsGeomTotal.erase(it);
	}
	listeEltsGeomSelect.clear();
}    //----- Fin de M�thode

void ObjetGeometrique::Deselectionner ( )
// Algorithme : m�thode qui enl�vent de la liste des �l�mentsG�om�triques totals
// et de la liste des �l�mentsG�om�triques s�lectionn�s les �l�mentsG�om�triques s�lectionn�s
//
{
	listeEltsGeomSelect.clear();
}    //----- Fin de M�thode

void ObjetGeometrique::SupprimerEltParticulier ( EltGeometrique *elt )
// Algorithme : enl�ve un �l�mentG�om�trique de liste des �l�mentG�om�trique totals
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

}    //----- Fin de M�thode

void ObjetGeometrique::Translater ( int x, int y )
// Algorithme :translate tous les �l�mentsG�om�triques s�lectionn�s de x et y
//
{
	for (vector<EltGeometrique *>::iterator it = listeEltsGeomSelect.begin();
			it != listeEltsGeomSelect.end(); it++)
			{
		(*it)->Translater(x, y);
	}
}    //----- Fin de M�thode

int ObjetGeometrique::SelectionnerElts ( int x1, int y1, int x2, int y2 )
// Algorithme : recherche quels sont les �l�ments se trouvant � l'int�rieur de
// ce rectangle d�finit par les deux points de la diagonales. Les �l�ments qui sont
// dans ce rectangle deviennent la nouvelle liste des �l�mentsG�om�triques s�lectionn�s
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
}    //----- Fin de M�thode

void ObjetGeometrique::AjouterEltGeom ( EltGeometrique *unEltGeometrique )
// Algorithme : ajoute un �l�ment � la liste des �l�mentsG�om�triques totals
//
{
	listeEltsGeomTotal.push_back(unEltGeometrique);
}    //----- Fin de M�thode

//------------------------------------------------- Surcharge d'op�rateurs
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

//----------------------------------------------------- M�thodes prot�g�es
