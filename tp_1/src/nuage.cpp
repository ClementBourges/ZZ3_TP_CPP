#include <nuage.hpp>
int Nuage::size()
{
	return vect.size();
}
void Nuage::ajouter(Cartesien c)
{
	vect.push_back(&c);
}

void Nuage::ajouter(Polaire p)
{
	vect.push_back(&p);
}
