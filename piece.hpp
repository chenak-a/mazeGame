/**
* Classe d'une Piece
* \file   piece.hpp
* \author Taylor et Alaa-Eddine
* \date   22 decembre 2021
* Créé le 3 decembre 2021
*/
#pragma once
#include "objet.hpp"

class Piece
{
public:
	Piece(const string& nom, const string& description);
	virtual ~Piece() = default;
	void setVoisins(string direction, Piece* piece);
	void setVoisins(map<string, Piece*> voisins);
	virtual Piece* getVoisin(string direction) const;
	virtual ostream& afficher(ostream& os);
	void setObjet(map<vector<string>, Objet*> objet);
	virtual Objet* getObjet(string objet) const;
protected:
	string nom_;
	string description_;
	unordered_map<string, Piece*> voisins_;
	map<vector<string>, Objet*> objets_;
};