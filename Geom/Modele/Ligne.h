/*************************************************************************
                           Ligne  -  description
                             -------------------
    début                : 27 janv. 2012
    copyright            : (C) 2012 par Pitou
*************************************************************************/

//---------- Interface de la classe <Ligne> (fichier Ligne.h) ------
#if ! defined ( LIGNE_H_ )
#define LIGNE_H_

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//--------------------------------------------------- Interfaces utilisées
#include "EltGeometrique.h"
#include "Point.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Ligne>
//
//
//------------------------------------------------------------------------ 

class Ligne : public EltGeometrique
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual string Description();
    // Mode d'emploi :
    //
    // Contrat :
    //

    string Info();
    // Mode d'emploi :
    //
    // Contrat :
    //

	Point getPoint1() const;
    // Mode d'emploi :
    //
    // Contrat :
    //

	Point getPoint2() const;
    // Mode d'emploi :
    //
    // Contrat :
    //

	virtual bool Appartient(int x1, int y1, int x2, int y2);
    // Mode d'emploi : renvoie vrai si la ligne est inclus dans le rectangle défini par ces deux points. Il peut être égal.
	//renvoie vrai si la ligne appartient dans le rectangle de sélection.
    //
    // Contrat :
    //

	virtual void Translater(int deltaX, int deltaY);
    // Mode d'emploi : translate les deux points qui définissent la ligne par le biais du vecteur défini par deltaX et deltaY
    //
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
    Ligne & operator = ( const Ligne & unLigne );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Ligne ( const Ligne & unLigne );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Ligne ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    Ligne (int x1, int y1, int x2, int y2);
    // Mode d'emploi :
    //
    // Contrat :
    //
    virtual ~Ligne();
    // Mode d'emploi :
    //
    // Contrat :
    //
    //------------------------------------------------------------------ PRIVE
protected:
    //----------------------------------------------------- Méthodes protégées
    //----------------------------------------------------- Attributs protégés
    Point point1;
    Point point2;
};

//--------------------------- Autres définitions dépendantes de <Ligne>

#endif // LIGNE_H_
