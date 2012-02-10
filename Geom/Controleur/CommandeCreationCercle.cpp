/*************************************************************************
 CommandeCreationCercle  -  description
 -------------------
 d�but                : 3 f�vr. 2012
 copyright            : (C) 2012 par Pitou
 *************************************************************************/

//---------- R�alisation de la classe <CommandeCreationCercle> (fichier CommandeCreationCercle.cpp) -------
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include syst�me
#include <iostream>
using namespace std;
#include <cstdlib>
//------------------------------------------------------ Include personnel
#include "CommandeCreationCercle.h"
#include "../Modele/Cercle.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
// type CommandeCreationCercle::M�thode ( liste des param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode

void CommandeCreationCercle::execute ( )
{
	if (status)
	{
		element = new Cercle(x1, y1, rayon);
		contexte->AjouterEltGeom(element);
	}
}

void CommandeCreationCercle::undo ( )
{
	if (status)
	{
		contexte->SupprimerEltParticulier(element);
		contexte->Deselectionner();
		cout << "Cet �l�ment : " << element->Description()
				<< " vient d'etre d�pil�" << endl;
	}
}

void CommandeCreationCercle::redo ( )
{
	if (status)
	{
		contexte->AjouterEltGeom(element);
		contexte->Deselectionner();
	}
}
//------------------------------------------------- Surcharge d'op�rateurs
//CommandeCreationCercle & CommandeCreationCercle::operator = ( const CommandeCreationCercle & unCommandeCreationCercle )
//// Algorithme :
////
//{
//} //----- Fin de operator =
//
//
////-------------------------------------------- Constructeurs - destructeur
//CommandeCreationCercle::CommandeCreationCercle ( const CommandeCreationCercle & unCommandeCreationCercle )
//// Algorithme :
////
//{
//#ifdef MAP
//    cout << "Appel au constructeur de copie de <CommandeCreationCercle>" << endl;
//#endif
//} //----- Fin de CommandeCreationCercle (constructeur de copie)

CommandeCreationCercle::CommandeCreationCercle ( vector<string *> para, ObjetGeometrique *leContexte ) :
		CommandeCreation(leContexte)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <CommandeCreationCercle>" << endl;
#endif

	string tmp("C");

	for (unsigned int i = 1; i < para.size(); i++)
	{
		tmp.append(" ");
		tmp.append(*(para.at(i)));
	}
	if (para.size() == TAILLE_COMMANDE_CERCLE)
	{
		x1 = atoi((para.at(1))->c_str());

		y1 = atoi((para.at(2))->c_str());

		int rayonTemporaire;
		rayonTemporaire = atoi((para.at(3))->c_str());
		// Le rayon ne peut pas etre n�gatif
		if (rayonTemporaire >= 1)
		{
			rayon = rayonTemporaire;
			tmp.append(" OK");
			tmp.append("\n");
		}
		else
		{
			tmp.append("\n");
			status = false;
		}
	}
	else
	{
		status = false;
	}

	if (!status)
	{
		texteCommande.append("Err ");
		texteCommande.append(tmp);
		texteCommande.append(CHAINE_PARA_INVALIDE);
		texteCommande.append("\n");
	}
	else
	{
		texteCommande.append(tmp);
	}

} //----- Fin de CommandeCreationCercle

CommandeCreationCercle::~CommandeCreationCercle ( )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <CommandeCreationCercle>" << endl;
#endif
} //----- Fin de ~CommandeCreationCercle

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

