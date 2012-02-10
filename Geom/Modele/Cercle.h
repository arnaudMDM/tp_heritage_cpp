/*************************************************************************
                           Cercle  -  description
                             -------------------
    d�but                : 27 janv. 2012
    copyright            : (C) 2012 par Pitou
*************************************************************************/

//---------- Interface de la classe <Cercle> (fichier Cercle.h) ------
#if ! defined ( CERCLE_H_ )
#define CERCLE_H_

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
#include <string>
//--------------------------------------------------- Interfaces utilis�es
#include "EltGeometrique.h"
#include "Point.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <Cercle>
//
//
//------------------------------------------------------------------------ 

class Cercle : public EltGeometrique
{
    //----------------------------------------------------------------- PUBLIC
public:
    //----------------------------------------------------- M�thodes publiques
    // type M�thode ( liste des param�tres );
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
    // Mode d'emploi : renvoie vrai si le cercle est inclus dans le rectangle d�fini par ces deux points. Il peut �tre �gal.
    //renvoie vrai si le cercle appartient dans le rectangle de s�lection.
    //
    // Contrat :
    //
    virtual void Translater(int deltaX, int deltaY);
    // Mode d'emploi : translate le centre qui d�finissent le cercle par le biais du vecteur d�fini par deltaX et deltaY
    //
    // Contrat :
    //
    //------------------------------------------------- Surcharge d'op�rateurs
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
    //----------------------------------------------------- M�thodes prot�g�es
    //----------------------------------------------------- Attributs prot�g�s
    Point centre;
    int rayon;
};

//--------------------------- Autres d�finitions d�pendantes de <Cercle>

#endif // CERCLE_H_
