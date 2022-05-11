/**
* Classe du Jeu
* \file   jeu.hpp
* \author Taylor et Alaa-Eddine
* \date   22 decembre 2021
* Créé le 3 decembre 2021
*/
#pragma once
#include <functional>
#include "personnage.hpp"
#include "objet.hpp"
#include "pieceCache.hpp"
#include "objectSpecial.hpp"
#include "Objectcontenur.hpp"

class Jeu
{
public:
	Jeu()
	{
		creerPieces();
		associerVoisins();
		creerPersonnage();
		creerObjets();
		associerObjets();
		associerEntreesUtilisateur();
	}
	void jouer();
	void demarrer();
	void afficherMessageAccueil();
private:
	void creerPieces();
	void creerPersonnage();
	void creerObjets();
	void associerVoisins();
	void associerObjets();
	void associerEntreesUtilisateur();
	pair<string, string> gestionEntrees(string& entree);
	unordered_map<string, unique_ptr<Piece>>pieces_;
	unordered_map<string, unique_ptr<Objet>> objets_;
	unique_ptr<Personnage> personnage_;
	unordered_map<string, function<void(string)>> entrees_;
	unordered_map<string, string> Direction_ = { {"n","Nord"},{"s","Sud"}, {"e","Est"}, {"o","Ouest"} };
	bool estTermine_ = false;
};