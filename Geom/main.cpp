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

#include "Controleur/CommandeFactory.h"
#include "Controleur/Commande.h"
#include "Modele/ObjetGeometrique.h"
#include "Modele/Cercle.h"
#include "Modele/EltGeometrique.h"

int main(int args, char *argv[])
{
	cout<<"Test "<<endl;
	queue <string> list;
	list.push(string("C"));
	list.push(string("1"));
	list.push(string("1"));
	list.push(string("10"));

	Commande *laCommande = NULL;

	ObjetGeometrique contexte;
	contexte.AjouterEltGeom(new Cercle(10,10,1));
	cout<<"Avant factory"<<endl;

	if( CommandeFactory::GetCommande (list, &laCommande, &contexte))
	{
		cout<<"retour getCommande ok"<<endl;
	}
	cout<<"Après Factory"<<endl;
	if(laCommande == NULL)
		{ cout<<"Erreur"<<endl;
		}
	laCommande->execute();
	cout<<"Avant vector"<<endl;
//	vector<EltGeometrique *> elts = contexte->getListeEltsGeomTotal();
//	Cercle *cercle = (Cercle *)elts.back();

//	cout<<"Valeur du cercle : "<<cercle->getRayon()<<endl;
	delete laCommande;
}
