/*************************************************************************
                           CommandeCreationRectangle  -  description
                             -------------------
    d�but                : 3 f�vr. 2012
    copyright            : (C) 2012 par Pitou
*************************************************************************/

//---------- Interface de la classe <CommandeCreationRectangle> (fichier CommandeCreationRectangle.h) ------
#if ! defined ( COMMANDECREATIONRECTANGLE_H_ )
#define COMMANDECREATIONRECTANGLE_H_

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me

//--------------------------------------------------- Interfaces utilis�es
#include "CommandeCreation.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <CommandeCreationRectangle>
//
//
//------------------------------------------------------------------------ 

class CommandeCreationRectangle : public CommandeCreation
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
    // type M�thode ( liste des param�tres );
    // Mode d'emploi :
    //
    // Contrat :
    //

	void Execute();

//------------------------------------------------- Surcharge d'op�rateurs
    CommandeCreationRectangle & operator = ( const CommandeCreationRectangle & unCommandeCreationRectangle );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    CommandeCreationRectangle ( const CommandeCreationRectangle & unCommandeCreationRectangle );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    CommandeCreationRectangle (vector < string *> para, ObjetGeometrique *unContexte, const string *requete );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~CommandeCreationRectangle ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- M�thodes prot�g�es

//----------------------------------------------------- Attributs prot�g�s
    int x1;
    int y1;
    int x2;
    int y2;

private:

};

//--------------------------- Autres d�finitions d�pendantes de <CommandeCreationRectangle>

#endif // COMMANDECREATIONRECTANGLE_H_
