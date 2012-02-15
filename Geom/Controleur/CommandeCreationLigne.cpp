/*************************************************************************
 CommandeCreationLigne  -  description
 -------------------
 d�but                : 10 f�vr. 2012
 copyright            : (C) 2012 par arnaud
 *************************************************************************/

//---------- R�alisation de la classe <CommandeCreationLigne> (fichier CommandeCreationLigne.cpp) -------
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>
#include <cstdlib>
//------------------------------------------------------ Include personnel
#include "CommandeCreationLigne.h"
#include "../Modele/Service.h"
#include "../Modele/Ligne.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC
void CommandeCreationLigne::Execute ( )
{
	element = new Ligne(x1, y1, x2, y2);
	contexte->AjouterEltGeom(element);
	selectionElt();
}
//----------------------------------------------------- M�thodes publiques
// type CommandeCreationLigne::M�thode ( liste des param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode

//------------------------------------------------- Surcharge d'op�rateurs
//CommandeCreationLigne & CommandeCreationLigne::operator = ( const CommandeCreationLigne & unCommandeCreationLigne )
//// Algorithme :
////
//{
//} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
//CommandeCreationLigne::CommandeCreationLigne ( const CommandeCreationLigne & unCommandeCreationLigne )
//// Algorithme :
////
//{
//#ifdef MAP
//    cout << "Appel au constructeur de copie de <CommandeCreationLigne>" << endl;
//#endif
//} //----- Fin de CommandeCreationLigne (constructeur de copie)

CommandeCreationLigne::CommandeCreationLigne ( vector<string *> para,
		ObjetGeometrique *leContexte, const string *requete ) :
		CommandeCreation(leContexte)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <CommandeCreationLigne>" << endl;
#endif

	x1 = atoi(para.at(1)->c_str());
	x2 = atoi(para.at(2)->c_str());
	y1 = atoi(para.at(3)->c_str());
	y2 = atoi(para.at(4)->c_str());

	texteCommande = OK + *requete;

}    //----- Fin de CommandeCreationLigne

CommandeCreationLigne::~CommandeCreationLigne ( )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <CommandeCreationLigne>" << endl;
#endif
}    //----- Fin de ~CommandeCreationLigne

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es
