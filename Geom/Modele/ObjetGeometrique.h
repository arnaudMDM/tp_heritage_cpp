/*************************************************************************
 ObjetGeometrique  -  description
 -------------------
 début                : 31 janv. 2012
 copyright            : (C) 2012 par arnaud
 *************************************************************************/

//---------- Interface de la classe <ObjetGeometrique> (fichier ObjetGeometrique.h) ------
#if ! defined ( OBJETGEOMETRIQUE_H_ )
#define OBJETGEOMETRIQUE_H_

//---------------------------------------------------
using namespace std;
//--------------------------------------------------- Interfaces utilisées

#include "EltGeometrique.h"
#include <vector>

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <ObjetGeometrique>
//
//
//------------------------------------------------------------------------ 

class ObjetGeometrique
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste des paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	//

	string DescriptionEltsSelect ( );
	// Mode d'emploi : renvoie les string de commandes des éléments sélectionnés
	//
	// Contrat : aucun
	//

	string DescriptionEltsTotal ( );
	// Mode d'emploi : renvoie les string de commandes des éléments totaux
	//
	// Contrat : aucun
	//

	int NbEltsTotals ( );
	// Mode d'emploi : renvoie le nombre total de d'éléments totaux
	//
	// Contrat :aucun
	//

	void SupprimerTousElts ( );
	// Mode d'emploi : supprime tous les élements totaux
	//
	// Contrat :aucun
	//

	void SupprimerEltsSelectionnes ( );
	// Mode d'emploi : supprimer tous les éléments sélectionnés
	//
	// Contrat :aucun
	//

	void Deselectionner ( );
	// Mode d'emploi : déselctionne tous les éléments sélectionnés
	//
	// Contrat :aucun
	//

	void SupprimerEltParticulier ( EltGeometrique *elt );
	// Mode d'emploi : supprime un élément géométrique
	//
	// Contrat :aucun
	//

	void SupprimerElts ( vector<EltGeometrique *> elts );
	// Mode d'emploi : supprime plusieurs éléments géométriques
	//
	// Contrat :aucun
	//

	void Translater ( int x, int y );
	// Mode d'emploi : translate les éléments sélectionnés
	//
	// Contrat :aucun
	//

	int SelectionnerElts ( int x1, int y1, int x2, int y2 );
	// Mode d'emploi : sélectionne les nouveaux éléments à partir de la liste des
	// éléments totaux.
	// Renvoie le nombre d'éléments sélectionnés
	//
	// Contrat :aucun
	//

	int SelectionnerElts ( vector<EltGeometrique *> elementsASelectionner );
	// Mode d'emploi : la liste des éléments sélectionnés remplace ses éléments
	// par elementsASelectionner si ils appartiennent à la liste des éléments totaux.
	// Renvoie le nombre d'éléments sélectionnés
	//
	// Contrat :aucun
	//

	bool SelectionnerElt ( EltGeometrique *elt );
	// Mode d'emploi : ajoute elt à la liste des éléments sélectionnés si
	// l'élément appartient à la liste des éléments totaux
	// Renvoie vrai si l'élément appartient à la liste des éléments totaux
	//
	// Contrat :aucun
	//

	void AjouterEltGeom ( EltGeometrique *unEltGeometrique );
	// Mode d'emploi : ajoute unEltGeometrique à la liste des éléments totaux
	//
	// Contrat :aucun
	//

	void AjouterEltGeom ( vector<EltGeometrique *> elts );
	// Mode d'emploi : ajoute elts à la liste des éléments totaux
	//
	// Contrat :aucun
	//

//------------------------------------------------- Surcharge d'opérateurs
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
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	vector<EltGeometrique *> listeEltsGeomTotal;
	vector<EltGeometrique *> listeEltsGeomSelect;
};

//--------------------------- Autres définitions dépendantes de <ObjetGeometrique>

#endif // OBJETGEOMETRIQUE_H_
