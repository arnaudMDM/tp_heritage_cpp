/*
 * Service.h
 *
 *  Created on: 27 janv. 2012
 *      Author: Pitou
 */

#ifndef SERVICE_H_
#define SERVICE_H_

#include <string>
using namespace std;

bool Contient(int x1, int y1, int x2, int y2, int x3, int y3);

bool IsInteger(string nom);

//permet à la fabrique de commande de savoir si elle doit vérifier si la commande doit juste être une création
//ou être toutes les commandes. Pour la commande LOAD, on ne doit avoir que des commandes de créations
enum TypeCommande{
	ToutesCommandes,Creation
};

#endif /* SERVICE_H_ */
