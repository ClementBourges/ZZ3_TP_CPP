#include <valeur.hpp>
#include <string>

Valeur::Valeur()
{
	x =0.0;
	nom=std::string("inconnu");
}
Valeur::Valeur(double x0)
{
	x=x0;

}
Valeur::Valeur(double x0, const char * n)
{
	x=x0;
	nom=n;
}

void Valeur::setNombre(double x0)
{
	x = x0;
}

double Valeur::getNombre() const
{
	return x;
}

double Valeur::getNote() const
{
	return x;
}

void Valeur::setNote(double n)
{
	x = n;
}

std::string Valeur::getEtudiant() const
{
	std::string s(nom) ;
	return s;
}

void Valeur::setEtudiant(std::string et)
{
	nom=std::string(et);
}
