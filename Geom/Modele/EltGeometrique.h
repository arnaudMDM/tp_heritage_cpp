/*************************************************************************
                           EltGeometrique  -  description
                             -------------------
    début                : 27 janv. 2012
    copyright            : (C) 2012 par Pitou
*************************************************************************/

//---------- Interface de la classe <EltGeometrique> (fichier EltGeometrique.h) ------
#if ! defined ( ELTGEOMETRIQUE_H_ )
#define ELTGEOMETRIQUE_H_

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <EltGeometrique>
//
//
//------------------------------------------------------------------------ 

class EltGeometrique
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


	virtual bool Appartient(int X1, int Y1, int X2, int Y2) = 0;
    // Mode d'emploi : renvoie vrai si la forme géométrique est inclus dans le rectangle défini par ces deux points. Il peu être égal
    //renvoie vrai si la forme géométrique appartient dans le rectangle de sélection.
	//
    // Contrat :
    //

	virtual void Translater(int deltaX, int deltaY) = 0;
    // Mode d'emploi : translate la forme géométrique par le biais vecteur défini par deltaX et deltaY
	//
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//--------------------------- Autres définitions dépendantes de <EltGeometrique>

#endif // ELTGEOMETRIQUE_H_
