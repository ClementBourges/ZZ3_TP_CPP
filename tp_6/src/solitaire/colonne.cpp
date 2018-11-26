#include "colonne.hpp"

bool Colonne::estVide()
{
	bool estvide;
	if(cartes_.size()==0)
	{
		estvide=true;
	}
	else
	{
		estvide=false;
	}
	return estvide;
}
Carte * Colonne::getSommet()
{
	return cartes_.back();
}
void Colonne::ajouter(Carte * c)
{
	cartes_.push_back(c);
}
Carte * Colonne::retirer()
{
	return cartes_.back();
	cartes_.pop_back();
}

int Colonne::getTaille() const
{
	return cartes_.size();
}

Carte * Colonne::getCarte(int index) const
{
	return cartes_.at(index);
}

