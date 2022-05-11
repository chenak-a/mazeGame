/**
* Classe d'un objet qui contien un autre objet
* \file   jeu.cpp
* \author Taylor et Alaa-Eddine
* \date   22 decembre 2021
* Créé le 18 decembre 2021
*/
#pragma once
#include "objet.hpp"

class ObjetConteneur : public Objet
{
public:
	ObjetConteneur(string nom, string description, string action, Objet* objet, string descriptionAction) :
		Objet(nom, description, action),
		objet_(objet),
		descriptionAction_(descriptionAction)
	{}
	void activerObjet() const override;
private:
	Objet* objet_;
	string descriptionAction_;
};
