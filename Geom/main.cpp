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
	Commande *laCommande = NULL;
	ObjetGeometrique *contexte = new ObjetGeometrique();
	CommandeFactory::GetCommande(argv,laCommande,contexte);
	laCommande->execute();
	vector<EltGeometrique *> elts = contexte->getListeEltsGeom();
	Cercle *cercle = (Cercle *)elts.back();

	cout<<"Valeur du cercle : "<<cercle->getRayon()<<endl;
}
