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

int main ( int args, char *argv[] )
{
	cout
			<< "Bienvenue dans le programme Geom.\nVeuilliez saisir votre commande : "
			<< endl;

	Controleur ctrl;

	ctrl.traitementCommande();

}
