#include "pioche.hpp"

bool Pioche::rienRetourner()
{
	bool ret = 0;
	if(retournees_.size()==0)
	{
		ret=1;
	}
	return ret;
		
}
bool Pioche::toutRetourner()
{
	bool ret = 0;
	if(retournees_.size()==0)
	{
		ret=1;
	}
	return ret;
}
bool Pioche::estVide()
{
	bool ret = 0;
	if(cartes_.size()==0)
	{
		ret=1;
	}
	return ret;
}
Carte * Pioche::getProchaine() const
{
	return nullptr;
}
Carte * Pioche::getVisible() const
{
	return nullptr;
}
void Pioche::ajouter(Carte *)
{

}
bool Pioche::tirer()
{
	return 0;
}
Carte * Pioche::retirer()
{
	return cartes_.back();
}
