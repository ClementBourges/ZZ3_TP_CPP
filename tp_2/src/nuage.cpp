#include <nuage.hpp>


typedef vector<Point*>::const_iterator const_iterator;

template <class T> int Nuage<T>::size() const
{
	return vect.size();
}
template <class T>
void Nuage<T>::ajouter(T c)
{
	vect.push_back(&c);
}

template <class T>
const_iterator Nuage<T>::begin() const
{
	return vect.cbegin();
}
template <class T>
const_iterator Nuage<T>::end() const
{
	return vect.cend();
}

/*
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
}*/



