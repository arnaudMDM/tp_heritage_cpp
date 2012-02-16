/*
 * main.cpp
 *
 *  Created on: 27 janv. 2012
 *      Author: Pitou
 */
using namespace std;
#include <iostream>
#include "Controleur/Controleur.h"

int main ( int args, char *argv[] )
{
	cout
			<< "#Bienvenue dans le programme Geom.\n#Veuillez saisir votre commande : "
			<< endl;

	Controleur ctrl;

	ctrl.TraitementCommande();

}
