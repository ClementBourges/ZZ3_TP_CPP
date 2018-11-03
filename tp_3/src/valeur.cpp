#include <valeur.hpp>

Valeur::Valeur()
{
	x =0.0;
}

Valeur::Valeur(double x0)
{
	x = x0;
}
void Valeur::setNombre(double x0)
{
	x=x0;
}

double Valeur::getNombre() const
{
	return x;
}
