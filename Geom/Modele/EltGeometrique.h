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


	virtual bool Appartient(int X1, int Y1, int X2, int Y2);
    // Mode d'emploi : renvoie vrai si la forme g�om�trique appartient dans le car� d�fini par ces deux points.
    //
    // Contrat :
    //

	virtual bool Translater(int deltaX, int deltaY);
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------- Surcharge d'op�rateurs
    EltGeometrique & operator = ( const EltGeometrique & unEltGeometrique );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    EltGeometrique ( const EltGeometrique & unEltGeometrique );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    EltGeometrique ( );
    // Mode d'emploi :
    //
    // Contrat :
    //



    virtual ~EltGeometrique ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- M�thodes prot�g�es

//----------------------------------------------------- Attributs prot�g�s

};

//--------------------------- Autres d�finitions d�pendantes de <EltGeometrique>

#endif // ELTGEOMETRIQUE_H_
