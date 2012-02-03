/*
 * main.cpp
 *
 *  Created on: 27 janv. 2012
 *      Author: Pitou
 */
using namespace std;
#include <iostream>


#include "Controleur/CommandeFactory.h"
#include "Controleur/Commande.h"
#include "Modele/ObjetGeometrique.h"
#include "Modele/Cercle.h"
#include "Modele/EltGeometrique.h"

int main(int args, char *argv[])
{
	cout<<"Test"<<endl;
	Commande *laCommande = NULL;
	ObjetGeometrique *contexte = new ObjetGeometrique();
	cout<<"Avant factory"<<endl;
	CommandeFactory::GetCommande(argv,laCommande,contexte);
	cout<<"Après Factory"<<endl;
	if(laCommande == NULL)
		{ cout<<"Erreur"<<endl;}
	laCommande->execute();
	cout<<"Avant vector"<<endl;
	vector<EltGeometrique *> elts = contexte->getListeEltsGeomTotal();
	Cercle *cercle = (Cercle *)elts.back();

	cout<<"Valeur du cercle : "<<cercle->getRayon()<<endl;
}
