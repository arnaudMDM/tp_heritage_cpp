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
	deque <string> list;
	list.push_back("C");
	list.push_back("1");
	list.push_back("1");
	list.push_back("10");

	Commande *laCommande = NULL;

	ObjetGeometrique *contexte = new ObjetGeometrique();
	cout<<"Avant factory"<<endl;

	if( CommandeFactory::GetCommande(list, &laCommande, contexte))
	{
		cout<<"retour getCommande ok"<<endl;
	}
	cout<<"Après Factory"<<endl;
	if(laCommande == NULL)
<<<<<<< .mine
	{
		cout<<"Erreur"<<endl;
	}
=======
		{ cout<<"Erreur"<<endl;}
>>>>>>> .r30
	laCommande->execute();
	cout<<"Avant vector"<<endl;
	vector<EltGeometrique *> elts = contexte->getListeEltsGeomTotal();
	Cercle *cercle = (Cercle *)elts.back();

	cout<<"Valeur du cercle : "<<cercle->getRayon()<<endl;
}
