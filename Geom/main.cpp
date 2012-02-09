/*
 * main.cpp
 *
 *  Created on: 27 janv. 2012
 *      Author: Pitou
 */
using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "Controleur/CommandeFactory.h"
#include "Controleur/Commande.h"
#include "Modele/ObjetGeometrique.h"
#include "Modele/Cercle.h"
#include "Modele/EltGeometrique.h"
#include "Controleur/Controleur.h"

#include "Controleur/Decomposeur.h"

int main(int args, char *argv[])
{
	Controleur ctrl;

	ctrl.traitementCommande();

//	cout<<"Test "<<endl;
//
//	//Test de la commande
//	//Préparation de la liste d'arguments
//	queue <string> list;
//	list.push(string("C"));
//	list.push(string("1"));
//	list.push(string("1"));
//	list.push(string("10"));
//
//	Commande *laCommande = NULL;
//
//	//Le contexte contient les différents EltGeometriques sous forme de vector
//	ObjetGeometrique* contexte = new ObjetGeometrique();
//	cout<<"Avant factory"<<endl;
//
//	//Récupération de la commande prete a etre executée
//	if( CommandeFactory::GetCommande (list, &laCommande, contexte))
//	{
//		cout<<"retour getCommande ok"<<endl;
//	}
//	cout<<"Après Factory"<<endl;
//	if(laCommande == NULL)
//		{ cout<<"Erreur"<<endl;
//		}
//	laCommande->execute();
//	cout<<"Avant vector"<<endl;
////	vector<EltGeometrique *> elts = contexte->getListeEltsGeomTotal();
////	Cercle *cercle = (Cercle *)elts.back();
//
////	cout<<"Valeur du cercle : "<<cercle->getRayon()<<endl;
//	delete laCommande;
//	delete contexte;
}
