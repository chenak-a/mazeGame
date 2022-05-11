/**
* Implementation de la classe d'un objet qui fait une action speciale
* \file   objectSpecial.cpp
* \author Taylor et Alaa-Eddine
* \date   22 decembre 2021
* Créé le 18 decembre 2021
*/
#include"objectSpecial.hpp"

void Objetclee::activerObjet()const
{
	Objet::activerObjet();
	piece_->debloquerPiece();
}