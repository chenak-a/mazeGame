/**
* Implementation de la classe Objet
* \file   objet.cpp
* \author Taylor et Alaa-Eddine
* \date   22 decembre 2021
* Créé le 17 decembre 2021
*/
#include "objet.hpp"

void Objet::activerObjet()const 
{
	cout << action_ << endl;
}
const string& Objet::getNom() const 
{
	return nom_;
}
const string& Objet::getDiscription() const 
{
	return desciption_;
}
void Objet::montrerObjet() 
{
	estCache_ = false;
}
bool Objet::getEstCache() const 
{
	return estCache_;
}