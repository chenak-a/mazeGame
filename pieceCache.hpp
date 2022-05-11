/**
* Classe d'une piece cache
* \file   pieceCache.hpp
* \author Taylor et Alaa-Eddine
* \date   22 decembre 2021
* Créé le 18 decembre 2021
*/
#pragma once
#include "piece.hpp"
class PieceCache : public Piece
{
public:
	PieceCache(const string& nom, const string& description) : Piece(nom, description) {};
	void debloquerPiece();
	bool getEstCache();
private:
	bool estCache_ = true;
};

