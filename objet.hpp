/**
* Classe d'un objet
* \file   objet.hpp
* \author Taylor et Alaa-Eddine
* \date   22 decembre 2021
* Créé le 18 decembre 2021
*/
#pragma once
#include <string>
#include <map>
#include <unordered_map>
#include <memory>
#include <vector>
#include <iostream>
using namespace std;

class Objet
{
public:
	Objet(string nom, string description, string action, bool cache = false) :
		nom_(nom),
		desciption_(description),
		action_(action),
		estCache_(cache)
	{}
	virtual ~Objet() = default;
	virtual void activerObjet() const;
	const string& getNom()const;
	const string& getDiscription() const;
	void montrerObjet();
	bool getEstCache() const;
protected:
	string nom_;
	string desciption_;
	string action_;
	bool estCache_;
};

