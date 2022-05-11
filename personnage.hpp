/**
* Classe du Personnage
* \file   personnage.hpp
* \author Taylor et Alaa-Eddine
* \date   22 decembre 2021
* Créé le 3 decembre 2021
*/
#pragma once
#include "piece.hpp"

class Personnage
{
public:
	Personnage(Piece* positionInitiale);
	void deplacer(string s);
	void afficherChoix();
	void regarderObjet(string objet);
	void utiliserObjet(string objet);
private:
	Piece* position_;
};