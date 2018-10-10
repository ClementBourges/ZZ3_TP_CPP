#include <nuage.hpp>


typedef vector<Point*>::const_iterator const_iterator;

int Nuage::size() const
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
const_iterator Nuage::begin() const
{
	return vect.cbegin();
}

const_iterator Nuage::end() const
{
	return vect.cend();
}

Cartesien barycentre(Nuage & n) 
{
	double x=0,y=0,nb=(double)n.size();
	Cartesien current(0,0);
	for(Nuage::const_iterator it = n.begin(); it != n.end();++it)
	{
		(*it)->convertir(current);
		x+=current.getX();
		y+=current.getY();
	}
	if(nb!=0)
	{
		current.setX(x/nb);
		current.setY(y/nb);
	}
	return current;
}



