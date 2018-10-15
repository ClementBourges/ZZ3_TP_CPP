#include <cartesien.hpp>


Cartesien::Cartesien(const double& a, const double& d)
{
	x=a;
	y=d;
}
Cartesien::Cartesien()
{
	x=0;
	y=0;
}
Cartesien::Cartesien(const Polaire & p)
{
	p.convertir(*this);
}
Cartesien::Cartesien(const Cartesien & p)
{
	this->x=p.x;
	this->y=p.y;
}

double Cartesien::getX()const
{
	return this->x;
}
double Cartesien::getY() const
{
	return this->y;
}

void Cartesien::setX(const double &a)
{
	this->x=a;
}
void Cartesien::setY(const double &d)
{
	this->y=d;
}
void Cartesien::afficher(std::stringstream & fl)
{
	fl <<"(x="<<x<<";y="<<y<<")";
}
void Cartesien::afficher(std::stringstream & fl) const
{
	fl <<"(x="<<x<<";y="<<y<<")";
}

void Cartesien::convertir(Polaire & p) const
{
	p.distance=sqrt(x*x+y*y);
	p.angle=atan(y/x)*180/3.14;
}

void Cartesien::convertir(Cartesien & c) const
{
	c.x=x;
	c.y=y;
}







