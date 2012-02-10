/*************************************************************************
                           Cercle  -  description
                             -------------------
    début                : 27 janv. 2012
    copyright            : (C) 2012 par Pitou
*************************************************************************/

//---------- Interface de la classe <Cercle> (fichier Cercle.h) ------
#if ! defined ( CERCLE_H_ )
#define CERCLE_H_

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <string>
//--------------------------------------------------- Interfaces utilisées
#include "EltGeometrique.h"
#include "Point.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Cercle>
//
//
//------------------------------------------------------------------------ 

class Cercle : public EltGeometrique
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

	int getRayon() const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    Point getCentre() const;
    // Mode d'emploi :
    //
    // Contrat :
    //
    virtual bool Appartient(int x1, int y1, int x2, int y2);
    // Mode d'emploi : renvoie vrai si le cercle est inclus dans le rectangle défini par ces deux points. Il peut être égal.
    //renvoie vrai si le cercle appartient dans le rectangle de sélection.
    //
    // Contrat :
    //
    virtual void Translater(int deltaX, int deltaY);
    // Mode d'emploi : translate le centre qui définissent le cercle par le biais du vecteur défini par deltaX et deltaY
    //
    // Contrat :
    //
    //------------------------------------------------- Surcharge d'opérateurs
    Cercle & operator =(const Cercle & unCercle);
    // Mode d'emploi :
    //
    // Contrat :
    //
    //-------------------------------------------- Constructeurs - destructeur
    Cercle(const Cercle & unCercle);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //
    Cercle();
    // Mode d'emploi :
    //
    // Contrat :
    //
    Cercle(int x, int y, int unRayon);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Cercle();
    // Mode d'emploi :
    //
    // Contrat :
    //
    //------------------------------------------------------------------ PRIVE
protected:
    //----------------------------------------------------- Méthodes protégées
    //----------------------------------------------------- Attributs protégés
    Point centre;
    int rayon;
};

//--------------------------- Autres définitions dépendantes de <Cercle>

#endif // CERCLE_H_
