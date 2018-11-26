#include "dock.hpp"

bool Dock::estVide()
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
Carte * Dock::getSommet() const
{
	return nullptr;
}
void Dock::ajouter(Carte * c)
{
	cartes_.push_back(c);
}
Carte * Dock::retirer()
{
	return cartes_.back();
	cartes_.pop_back();
}
