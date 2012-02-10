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

void CommandeCreationCercle::execute()
{
	if(status)
	{
		element = new Cercle(x1,y1,rayon);
		contexte->AjouterEltGeom(element);
	}
}

void CommandeCreationCercle::undo()
{
	if(status)
	{
		contexte->SupprimerEltParticulier(element);
		contexte->Deselectionner();
		cout<<"Cet �l�ment : "<<element->Description()<<" vient d'etre d�pil�"<<endl;
	}
}

void CommandeCreationCercle::redo()
{
	if(status)
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


CommandeCreationCercle::CommandeCreationCercle (queue < string *> para, ObjetGeometrique *leContexte) : CommandeCreation(leContexte)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <CommandeCreationCercle>" << endl;
#endif
    if(para.size() == 3)
    {
    	texteCommande.append("C ");
		x1 = atoi(para.front()->c_str());
		texteCommande.append(*para.front());
		texteCommande.append(" ");
		para.pop();

		y1 = atoi(para.front()->c_str());
		texteCommande.append(*para.front());
		texteCommande.append(" ");
		para.pop();

		int rayonTemporaire;
		rayonTemporaire= atoi(para.front()->c_str());
		texteCommande.append(*para.front());
		texteCommande.append("\n");
		para.pop();
		// Le rayon ne peut pas etre n�gatif
		if(rayonTemporaire >= 1)
		{
			rayon = rayonTemporaire;
		}
		else
		{
			string temp("ERR ");
			temp.append(texteCommande);
			temp.append(CHAINE_PARA_INVALIDE);
			texteCommande = temp;
			status = false;
		}
    }
    else
    {
    	texteCommande.append("ERR C");
    	while(!para.empty())
    	{
    		texteCommande.append(" ");
    		texteCommande.append(*para.front());
    		para.pop();
    	}
    	texteCommande.append(CHAINE_PARA_INVALIDE);
        status = false;
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

