/**
* Implementation de la classe du Personnage
* \file   personnage.cpp
* \author Taylor et Alaa-Eddine
* \date   22 decembre 2021
* Créé le 3 decembre 2021
*/
#include "personnage.hpp"

Personnage::Personnage(Piece* positionInitiale) : position_(positionInitiale)
{}
void Personnage::afficherChoix()
{
	position_->afficher(cout);
}
void Personnage::deplacer(string d)
{
	if (auto position = position_->getVoisin(d))
	{
		position_ = position;
		cout << "Je vais vers la direction " << d << "\n\n";
		afficherChoix();
	}
	else
		cout << "Je ne peux pas aller là !\n";
}
void  Personnage::regarderObjet(string object)
{
	if (auto objetCourant = position_->getObjet(object))
		cout << objetCourant->getDiscription() << endl;
	else
		afficherChoix();
}
void  Personnage::utiliserObjet(string object)
{
	if (auto objetCourant = position_->getObjet(object))
		objetCourant->activerObjet();
	else
		cout << "L'objet n'existe pas !\n";
}
