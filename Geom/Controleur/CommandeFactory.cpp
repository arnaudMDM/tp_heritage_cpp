/*************************************************************************
 CommandeFactory  -  description
 -------------------
 début                : 27 janv. 2012
 copyright            : (C) 2012 par Pitou
 *************************************************************************/

//---------- Réalisation de la classe <CommandeFactory> (fichier CommandeFactory.cpp) -------
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
#include <exception>
#include <cstdlib>
using namespace std;
//------------------------------------------------------ Include personnel
#include "CommandeFactory.h"
#include "CommandeCreationCercle.h"
#include "CommandeCreationLigne.h"
#include "CommandeCreationRectangle.h"
#include "CommandeCreationPoly.h"
#include "CommandeSuppression.h"
#include "CommandeDeplac.h"
#include "CommandeLoad.h"

//------------------------------------------------------------- Constantes
static const string COMMANDE_RECTANGLE = "R";
//Nom de la commande associee a la creation d'un Rectangle
static const string COMMANDE_CERCLE = "C";
//Nom de la commande associee a la creation d'un Cercle
static const string COMMANDE_LIGNE = "L";
//Nom de la commande associee a la creation d'une Ligne
static const string COMMANDE_POLY = "PL";
//Nom de la commande associee a la creation d'une PolyLigne
static const string COMMANDE_LOAD = "LOAD";
//Nom de la commande associee a la fonctionnnalite de chargement
static const string COMMANDE_CLEAR = "CLEAR";
//Nom de la commande associee a la fonctionnnalite Suppression - clear
static const string COMMANDE_DELETE = "DELETE";
//Nom de la commande associee a la fonctionnnalite de Suppression - delete
static const string COMMANDE_MOVE = "MOVE";
//Nom de la commande associee a la fonctionnnalite de deplacement

static const unsigned int NB_PARAM_MOVE = 3;
//le nombre necessaire et suffisant d'argument de la commande MOVE
static const unsigned int NB_PARAM_LOAD = 2;
//le nombre necessaire et suffisant d'argument de la commande LOAD
static const unsigned int NB_PARAM_CLEAR = 1;
//le nombre necessaire et suffisant d'argument de la commande CLEAR
static const unsigned int NB_PARAM_DELETE = 1;
//le nombre necessaire et suffisant d'argument de la commande DELETE
static const unsigned int NB_PARAM_CREAT_RECT = 5;
//le nombre necessaire et suffisant d'argument de la commande R
static const unsigned int NB_PARA_INVARIANT_PL = 1;
//le nombre minimal (mais non suffisant) d'arguments pour la commande PL
static const unsigned int NB_PARA_PAR_POINT = 2;
//le nombre d'arguments composant un n-uplet pour la commande PL
static const unsigned int NB_PARAM_CREAT_CERCLE = 4;
//le nombre necessaire et suffisant d'argument de la commande C
static const unsigned int TAILLE_COMMANDE_LIGNE = 5;
//le nombre necessaire et suffisant d'argument de la commande L
//----------------------------------------------------------------- PUBLIC
const string CommandeFactory::EXTENSION_FICHIER = ".txt";
//----------------------------------------------------- Méthodes publiques

bool CommandeFactory::GetCommande ( vector<string *> para,
        Commande **laCommande, ObjetGeometrique *contexte, string *requete,
        TypeCommande unTypeCommande )
// Mode d'emploi : Retourne l'instance d'une commande
// correspondant aux arguments passés en paramètre.
//
{
	bool status ( true );

	string commande ( *para.front ( ) );

	//Comparaison du nom de la commande avec les differentes constantes
	//et traitement si correspondance
	if ( commande.compare ( COMMANDE_LOAD ) == 0 && unTypeCommande != Creation )
	{
		status = traitementLoad ( para, laCommande, contexte );
	}
	else if ( commande.compare ( COMMANDE_MOVE ) == 0
	        && unTypeCommande != Creation )
	{
		status = traitementMove ( para, laCommande, contexte, requete );
	}
	else if ( commande.compare ( COMMANDE_CLEAR ) == 0
	        && unTypeCommande != Creation )
	{
		if ( para.size ( ) == NB_PARAM_CLEAR )
		{
			*laCommande = new CommandeSuppression ( contexte,
			        CommandeSuppression::CLEAR );
		}
		else
		{
			status = false;
		}
	}
	else if ( commande.compare ( COMMANDE_DELETE ) == 0
	        && unTypeCommande != Creation )
	{
		if ( para.size ( ) == NB_PARAM_DELETE )
		{
			*laCommande = new CommandeSuppression ( contexte,
			        CommandeSuppression::DELETE );
		}
		else
		{
			status = false;
		}
	}
	else if ( commande.find ( COMMANDE_CERCLE ) == 0 )
	{
		status = traitementCercle ( para, laCommande, contexte, requete );
	}
	else if ( commande.compare ( COMMANDE_RECTANGLE ) == 0 )
	{
		status = traitementRect ( para, laCommande, contexte, requete );
	}
	else if ( commande.compare ( COMMANDE_LIGNE ) == 0 )
	{
		status = traitementLigne ( para, laCommande, contexte, requete );
	}
	else if ( commande.compare ( COMMANDE_POLY ) == 0 )
	{
		status = traitementPoly ( para, laCommande, contexte, requete );
	}
	else
	{
		status = false;
	}

	return status;
}
//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

CommandeFactory::CommandeFactory ( )
{
#ifdef MAP
	cout << "Appel au constructeur de <CommandeFactory>" << endl;
#endif
} //----- Fin de CommandeFactory

CommandeFactory::~CommandeFactory ( )
{
#ifdef MAP
	cout << "Appel au destructeur de <CommandeFactory>" << endl;
#endif
} //----- Fin de ~CommandeFactory

//------------------------------------------------------------------ PRIVE
bool CommandeFactory::traitementMove ( vector<string *> para,
        Commande ** laCommande, ObjetGeometrique * contexte,
        const string *requete )
//Methode permettant de traiter le cas du MOVE. Verifie la validite de la
// commande et le cas echeant cree la commande correspondante.
//Renvoie vrai si la commande a ete cree faux sinon
{
	bool etat ( true );

	//Verification nombre d'arguments
	if ( para.size ( ) == NB_PARAM_MOVE )
	{
		vector<string*>::iterator it = para.begin ( ) + 1;

		//Verification validite de chaque argument
		while (it != para.end ( ) && etat)
		{
			if ( !IsInteger ( **it ) )
			{
				etat = false;
			}
			it++;
		}

		if ( etat )
		{
			*laCommande = new CommandeDeplac ( para, contexte, requete );
		}
	}
	else
	{
		etat = false;
	}

	return etat;
} //----- Fin de traitementMove

bool CommandeFactory::traitementLoad ( vector<string *> para,
        Commande ** laCommande, ObjetGeometrique * contexte )
//Methode permettant de traiter le cas du LOAD. Verifie la validite de la
// commande et le cas echeant cree la commande correspondante.
//Renvoie vrai si la commande a ete cree ET si cette commande est valide.
// Une commande LOAD valide est une commande dont la lecture dans le
// fichier s'est bien passe.
//Retourne faux sinon.
{
	if ( para.size ( ) == NB_PARAM_LOAD
	        && para.at ( 1 )->find ( EXTENSION_FICHIER ) != string::npos )
	{
		CommandeLoad *ptrLoad = new CommandeLoad ( *(para.at ( 1 )), contexte );
		*laCommande = ptrLoad;
		return ((CommandeLoad *) (*laCommande))->IsOk ( );
		return ptrLoad->IsOk ( );
	}
	else
	{
		return false;
	}
} //----- Fin de traitementLoad

bool CommandeFactory::traitementRect ( vector<string *> para,
        Commande ** laCommande, ObjetGeometrique * contexte,
        const string *requete )
//Methode permettant de traiter le cas de la création du Rectangle.
//Verifie la validite de la commande et le cas echeant cree la commande
// correspondante.
//Renvoie vrai si la commande a ete cree faux sinon
{
	bool correct ( false );

	if ( para.size ( ) == NB_PARAM_CREAT_RECT )
	{
		correct = true;

		vector<string*>::iterator it = para.begin ( ) + 1;

		while (it != para.end ( ) && correct)
		{
			if ( !IsInteger ( **it ) )
			{
				correct = false;
			}
			it++;
		}

		if ( correct )
		{
			*laCommande = new CommandeCreationRectangle ( para, contexte,
			        requete );
		}
	}
	return correct;
} //----- Fin de traitementRect

bool CommandeFactory::traitementPoly ( vector<string *> para,
        Commande ** laCommande, ObjetGeometrique * contexte,
        const string *requete )
//Methode permettant de traiter le cas de la création de la PolyLigne.
//Verifie la validite de la commande et le cas echeant cree la commande
// correspondante.
//Renvoie vrai si la commande a ete cree. faux sinon
{
	vector<int> tempX;
	vector<int> tempY;

	bool correct ( true );

	//Verification du nombre d'arguments
	if ( (para.size ( ) - NB_PARA_INVARIANT_PL) % NB_PARA_PAR_POINT != 0 )
	{
		correct = false;
	}
	else
	{
		//Verification de la validite de chaque argument
		vector<string *>::iterator itX = para.begin ( ) + 1;
		vector<string *>::iterator itY = para.begin ( ) + 2;

		while (itX != para.end ( ) && correct)
		{
			if ( !IsInteger ( (*itY)->c_str ( ) )
			        || !IsInteger ( (*itX)->c_str ( ) ) )
			{
				correct = false;
			}
			else
			{
				tempX.push_back ( atoi ( (*itX)->c_str ( ) ) );
				tempY.push_back ( atoi ( (*itY)->c_str ( ) ) );
			}

			itX += NB_PARA_PAR_POINT;
			itY += NB_PARA_PAR_POINT;
		}
	}

	if ( correct )
	{
		*laCommande = new CommandeCreationPoly ( tempX, tempY, contexte,
		        requete );
	}
	return correct;
} //----- Fin de traitementPoly

bool CommandeFactory::traitementCercle ( vector<string *> para,
        Commande ** laCommande, ObjetGeometrique * contexte,
        const string *requete )
//Methode permettant de traiter le cas de la création du Cercle.
//Verifie la validite de la commande et le cas echeant cree la commande
// correspondante.
//Renvoie vrai si la commande a ete cree. faux sinon
{
	bool correct ( true );

	if ( para.size ( ) == NB_PARAM_CREAT_CERCLE )
	{
		vector<string*>::iterator it = para.begin ( ) + 1;
		while (it != para.end ( ) && correct)
		{
			if ( !IsInteger ( **it ) )
			{
				correct = false;
			}
			it++;
		}

		if ( correct && atoi ( (para.at ( 3 ))->c_str ( ) ) > 0 )
		{
			*laCommande = new CommandeCreationCercle ( para, contexte,
			        requete );
		}
		else
		{
			correct = false;
		}
	}
	else
	{
		correct = false;
	}

	return correct;
} //----- Fin de traitementCercle

bool CommandeFactory::traitementLigne ( vector<string *> para,
        Commande ** laCommande, ObjetGeometrique * contexte,
        const string *requete )
//Methode permettant de traiter le cas de la création du Rectangle.
//Verifie la validite de la commande et le cas echeant cree la commande
// correspondante.
//Renvoie vrai si la commande a ete cree. faux sinon
{

	string tmp;
	bool correct ( true );

	if ( para.size ( ) == TAILLE_COMMANDE_LIGNE )
	{
		vector<string *>::iterator it = para.begin ( ) + 1;

		while (it != para.end ( ) && correct)
		{
			if ( !IsInteger ( (*it)->c_str ( ) ) )
			{
				correct = false;
			}
			it++;
		}

		if ( correct )
		{
			*laCommande = new CommandeCreationLigne ( para, contexte, requete );
		}
	}
	else
	{
		correct = false;
	}

	return correct;
} //----- Fin de traitementLigne
//----------------------------------------------------- Méthodes protégées

