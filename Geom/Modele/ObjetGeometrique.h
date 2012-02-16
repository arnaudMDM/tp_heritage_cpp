/*************************************************************************
 ObjetGeometrique  -  description
 -------------------
 d�but                : 31 janv. 2012
 copyright            : (C) 2012 par arnaud
 *************************************************************************/

//---------- Interface de la classe <ObjetGeometrique> (fichier ObjetGeometrique.h) ------
#if ! defined ( OBJETGEOMETRIQUE_H_ )
#define OBJETGEOMETRIQUE_H_

//---------------------------------------------------
using namespace std;
//--------------------------------------------------- Interfaces utilis�es

#include "EltGeometrique.h"
#include <vector>

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <ObjetGeometrique>
//
//
//------------------------------------------------------------------------ 

class ObjetGeometrique
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
	// type M�thode ( liste des param�tres );
	// Mode d'emploi :
	//
	// Contrat :
	//

	string DescriptionEltsSelect ( );
	// Mode d'emploi : renvoie les string de commandes des �l�ments s�lectionn�s
	//
	// Contrat : aucun
	//

	string DescriptionEltsTotal ( );
	// Mode d'emploi : renvoie les string de commandes des �l�ments totaux
	//
	// Contrat : aucun
	//

	int NbEltsTotals ( );
	// Mode d'emploi : renvoie le nombre total de d'�l�ments totaux
	//
	// Contrat :aucun
	//

	void SupprimerTousElts ( );
	// Mode d'emploi : supprime tous les �lements totaux
	//
	// Contrat :aucun
	//

	void SupprimerEltsSelectionnes ( );
	// Mode d'emploi : supprimer tous les �l�ments s�lectionn�s
	//
	// Contrat :aucun
	//

	void Deselectionner ( );
	// Mode d'emploi : d�selctionne tous les �l�ments s�lectionn�s
	//
	// Contrat :aucun
	//

	void SupprimerEltParticulier ( EltGeometrique *elt );
	// Mode d'emploi : supprime un �l�ment g�om�trique
	//
	// Contrat :aucun
	//

	void SupprimerElts ( vector<EltGeometrique *> elts );
	// Mode d'emploi : supprime plusieurs �l�ments g�om�triques
	//
	// Contrat :aucun
	//

	void Translater ( int x, int y );
	// Mode d'emploi : translate les �l�ments s�lectionn�s
	//
	// Contrat :aucun
	//

	int SelectionnerElts ( int x1, int y1, int x2, int y2 );
	// Mode d'emploi : s�lectionne les nouveaux �l�ments � partir de la liste des
	// �l�ments totaux.
	// Renvoie le nombre d'�l�ments s�lectionn�s
	//
	// Contrat :aucun
	//

	int SelectionnerElts ( vector<EltGeometrique *> elementsASelectionner );
	// Mode d'emploi : la liste des �l�ments s�lectionn�s remplace ses �l�ments
	// par elementsASelectionner si ils appartiennent � la liste des �l�ments totaux.
	// Renvoie le nombre d'�l�ments s�lectionn�s
	//
	// Contrat :aucun
	//

	bool SelectionnerElt ( EltGeometrique *elt );
	// Mode d'emploi : ajoute elt � la liste des �l�ments s�lectionn�s si
	// l'�l�ment appartient � la liste des �l�ments totaux
	// Renvoie vrai si l'�l�ment appartient � la liste des �l�ments totaux
	//
	// Contrat :aucun
	//

	void AjouterEltGeom ( EltGeometrique *unEltGeometrique );
	// Mode d'emploi : ajoute unEltGeometrique � la liste des �l�ments totaux
	//
	// Contrat :aucun
	//

	void AjouterEltGeom ( vector<EltGeometrique *> elts );
	// Mode d'emploi : ajoute elts � la liste des �l�ments totaux
	//
	// Contrat :aucun
	//

//------------------------------------------------- Surcharge d'op�rateurs
	ObjetGeometrique & operator = (
	        const ObjetGeometrique & unObjetGeometrique );
	// Mode d'emploi : trivial
	//
	// Contrat :
	//

	vector<EltGeometrique *> getListeEltsGeomTotal ( ) const;
	// Mode d'emploi :trivial
	//
	// Contrat :aucun
	//

	vector<EltGeometrique *> getListeEltsGeomSelect ( ) const;
	// Mode d'emploi :trivial
	//
	// Contrat :aucun
	//

//-------------------------------------------- Constructeurs - destructeur
	ObjetGeometrique ( const ObjetGeometrique & unObjetGeometrique );
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :aucun
	//

	ObjetGeometrique ( );
	// Mode d'emploi :
	//
	// Contrat :aucun
	//

	ObjetGeometrique ( vector<EltGeometrique *> uneListeEltsGeom );
	// Mode d'emploi :
	//
	// Contrat :aucun
	//

	virtual ~ObjetGeometrique ( );
	// Mode d'emploi :
	//
	// Contrat :aucun
	//

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- M�thodes prot�g�es

//----------------------------------------------------- Attributs prot�g�s
	vector<EltGeometrique *> listeEltsGeomTotal;
	vector<EltGeometrique *> listeEltsGeomSelect;
};

//--------------------------- Autres d�finitions d�pendantes de <ObjetGeometrique>

#endif // OBJETGEOMETRIQUE_H_
