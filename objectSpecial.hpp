/**
* Classe d'un objet qui fait une action speciale
* \file   objetSpecial.hpp
* \author Taylor et Alaa-Eddine
* \date   22 decembre 2021
* Créé le 18 decembre 2021
*/
#pragma once
#include "objet.hpp"
#include "pieceCache.hpp"

class Objetclee : public Objet
{
public:
	Objetclee(string nom, string description, string action, PieceCache* piece) :
		Objet(nom, description, action), piece_(piece)
	{}
	void activerObjet() const override;
private:
	PieceCache* piece_;
};

