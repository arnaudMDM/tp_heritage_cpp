/*************************************************************************
 CommandeCreationRectangle  -  description
 -------------------
 d�but                : 12 f�vr. 2012
 copyright            : (C) 2012 par Pitou
 *************************************************************************/

//---------- R�alisation de la classe <CommandeCreationRectangle> (fichier CommandeCreationRectangle.cpp) -------
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>
#include <cstdlib>
//------------------------------------------------------ Include personnel
#include "CommandeCreationRectangle.h"
#include "../Modele/Rectangle.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
// type CommandeCreationRectangle::M�thode ( liste des param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode

void CommandeCreationRectangle::Execute ( )
{
	element = new Rectangle(x1, y1, x2, y2);
	contexte->AjouterEltGeom(element);
}

//------------------------------------------------- Surcharge d'op�rateurs
//CommandeCreationRectangle & CommandeCreationRectangle::operator = ( const CommandeCreationRectangle & unCommandeCreationRectangle )
//// Algorithme :
////
//{
//} //----- Fin de operator =
//
//
////-------------------------------------------- Constructeurs - destructeur
//CommandeCreationRectangle::CommandeCreationRectangle ( const CommandeCreationRectangle & unCommandeCreationRectangle )
//// Algorithme :
////
//{
//#ifdef MAP
//    cout << "Appel au constructeur de copie de <CommandeCreationRectangle>" << endl;
//#endif
//} //----- Fin de CommandeCreationRectangle (constructeur de copie)

CommandeCreationRectangle::CommandeCreationRectangle ( vector<string *> para,
		ObjetGeometrique *unContexte, const string *requete ) :
		CommandeCreation(unContexte)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <CommandeCreationRectangle>" << endl;
#endif

	x1 = atoi((para.at(1))->c_str());

	y1 = atoi((para.at(2))->c_str());

	x2 = atoi((para.at(3))->c_str());

	y2 = atoi((para.at(4))->c_str());

	texteCommande = OK + *requete;

}    //----- Fin de CommandeCreationRectangle

CommandeCreationRectangle::~CommandeCreationRectangle ( )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <CommandeCreationRectangle>" << endl;
#endif
}    //----- Fin de ~CommandeCreationRectangle

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

