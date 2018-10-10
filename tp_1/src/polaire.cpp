#include <polaire.hpp>


Polaire::Polaire(const double& a, const double& d)
{
	angle=a;
	distance=d;
}
Polaire::Polaire()
{
	angle=0;
	distance=0;
}
Polaire::Polaire(const Polaire & p)
{
	this->angle=p.angle;
	this->distance=p.distance;
}

Polaire::Polaire(Cartesien & c)
{
	c.convertir(*this);
}
double Polaire::getAngle()const
{
	return this->angle;
}
double Polaire::getDistance() const
{
	return this->distance;
}

void Polaire::setAngle(const double &a)
{
	this->angle=a;
}
void Polaire::setDistance(const double &d)
{
	this->distance=d;
}
void Polaire::afficher(std::stringstream & fl)
{
	fl <<"(a="<<angle<<";d="<<distance<<")";
}
void Polaire::afficher(std::stringstream & fl) const
{
	fl <<"(a="<<angle<<";d="<<distance<<")";
}

void Polaire::convertir(Cartesien & c) const
{
	c.x=distance*cos(angle*3.1415/180);
	c.y=distance*sin(angle*3.1415/180);
}
void Polaire::convertir(Polaire & p) const
{
	p.angle=angle;
	p.distance=distance;
}





