/**
* Implementation de la classe d'une Piece
* \file   piece.cpp
* \author Taylor et Alaa-Eddine
* \date   22 decembre 2021
* Créé le 3 decembre 2021
*/
#include "piece.hpp"
#include "pieceCache.hpp"

Piece::Piece(const string& nom, const string& description) : nom_(nom), description_(description)
{}
void Piece::setVoisins(string direction, Piece* piece)
{
	voisins_[direction] = piece;
}
void Piece::setVoisins(map<string, Piece*> voisins)
{
	for (auto& v : voisins)
		voisins_[v.first] = v.second;
}
Piece* Piece::getVoisin(string direction) const
{
	auto it = voisins_.find(direction);
	if (it == voisins_.end() || (dynamic_cast<PieceCache*>(it->second) != nullptr && dynamic_cast<PieceCache*>(it->second)->getEstCache()))
		return nullptr;
	return it->second;
}
Objet* Piece::getObjet(string objet) const
{
	
	for (auto& a : objets_) {
		for (auto& b : a.first) 
			if (objet.find(b) != string::npos)
				return a.second;
	}
	return nullptr;
	
}
ostream& Piece::afficher(ostream& os)
{
	os << "--- " << nom_ << " ---" << endl;
	os << description_ << endl;

	if (objets_.size() != 0)
	{
		os << "Vous appercevez : " << endl;
		for (auto& objet : objets_)
		{
			if (!objet.second->getEstCache())
				os << "\t" << objet.second->getNom() << endl;
		}
	}

	for (auto& v : voisins_)
	{
		auto pieceCache = dynamic_cast<PieceCache*>(v.second);

		if ((dynamic_cast<Piece*>(v.second) && pieceCache == nullptr) || (pieceCache != nullptr && !pieceCache->getEstCache()))
			os << v.second->nom_ << " est vers " << v.first << " (" << v.first[0] << ")\n";
	}

	return os;
}
void Piece::setObjet(map< vector<string>, Objet*> objet)
{
	objets_.insert(objet.begin(), objet.end());
	
}

