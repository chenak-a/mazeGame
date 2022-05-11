/**
* Implementation de la classe d'un objet qui en contient un autre
* \file   Objectcontenur.cpp
* \author Taylor et Alaa-Eddine
* \date   22 decembre 2021
* Créé le 18 decembre 2021
*/
#include "Objectcontenur.hpp"

void ObjetConteneur::activerObjet()const
{
	if (objet_->getEstCache())
	{
		cout << descriptionAction_ << endl;
		objet_->montrerObjet();
	}
	else
		Objet::activerObjet();
}