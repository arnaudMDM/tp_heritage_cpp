/*************************************************************************
                           EltGeometrique  -  description
                             -------------------
    d�but                : 27 janv. 2012
    copyright            : (C) 2012 par Pitou
*************************************************************************/

//---------- Interface de la classe <EltGeometrique> (fichier EltGeometrique.h) ------
#if ! defined ( ELTGEOMETRIQUE_H_ )
#define ELTGEOMETRIQUE_H_

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
#include <string>

//--------------------------------------------------- Interfaces utilis�es

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <EltGeometrique>
//
//
//------------------------------------------------------------------------ 

class EltGeometrique
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
    // type M�thode ( liste des param�tres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual string Description() = 0;
    // Mode d'emploi :
    //
    // Contrat :
    //

	virtual bool Appartient(int X1, int Y1, int X2, int Y2) = 0;
    // Mode d'emploi : renvoie vrai si la forme g�om�trique est inclus dans le rectangle d�fini par ces deux points. Il peu �tre �gal
    //renvoie vrai si la forme g�om�trique appartient dans le rectangle de s�lection.
	//
    // Contrat :
    //

	virtual void Translater(int deltaX, int deltaY) = 0;
    // Mode d'emploi : translate la forme g�om�trique par le biais vecteur d�fini par deltaX et deltaY
	//
    // Contrat :
    //

	virtual ~EltGeometrique() {};

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- M�thodes prot�g�es

//----------------------------------------------------- Attributs prot�g�s

};

//--------------------------- Autres d�finitions d�pendantes de <EltGeometrique>

#endif // ELTGEOMETRIQUE_H_
