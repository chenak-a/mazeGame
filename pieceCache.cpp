/**
* Implementation de la classe d'une piece cachee
* \file   personnage.cpp
* \author Taylor et Alaa-Eddine
* \date   22 decembre 2021
* Créé le 18 decembre 2021
*/
#include "pieceCache.hpp"
void PieceCache::debloquerPiece()
{
	estCache_ = false;
}
bool PieceCache::getEstCache()
{
	return estCache_;
}