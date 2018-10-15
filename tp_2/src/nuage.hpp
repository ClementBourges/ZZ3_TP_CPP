#ifndef NUA
#define NUA
#include <point.hpp>
#include <cartesien.hpp>
#include <polaire.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;



template <typename T>
class Nuage 
{
	public:
		vector<T>vect;
		int size()const ;
		void ajouter(T c);

		using const_iterator = typename vector<T>::const_iterator ;
		const_iterator begin() const;
		const_iterator end() const;
};

template <typename T> int Nuage<T>::size() const
{
	return vect.size();
}
template <typename T>
void Nuage<T>::ajouter(T c)
{
	vect.push_back(c);
}

template <typename T>
using const_iterator = typename vector<T>::const_iterator ;

template <typename T>
const_iterator<T> Nuage<T>::begin() const
{
	return vect.cbegin();
}

template <typename T>
const_iterator<T> Nuage<T>::end() const
{
	return vect.cend();
}

/*
template <typename T>
T barycentre_v1(Nuage<T> & n)
{
	double x=0,y=0,nb=(double)n.size();
	Cartesien c(0,0);
	Point & p1 = c;
	if(typeid(T)==typeid(Cartesien))
	{
		Cartesien current(0,0);
		for(const_iterator<T> it = n.begin(); it != n.end();++it)
		{
			(*it).convertir(current);
			x+=current.getX();
			y+=current.getY();
		}
		if(nb!=0)
		{
			current.setX(x/nb);
			current.setY(y/nb);
		}
		p1 = current;
	}
	else if(typeid(T)==typeid(Polaire))
	{
		Cartesien current2(0,0);
		for(const_iterator<T> it = n.begin(); it != n.end();++it)
		{
			(*it).convertir(current2);
			x+=current2.getX();
			y+=current2.getY();
		}
		if(nb!=0)
		{
			current2.setX(x/nb);
			current2.setY(y/nb);
		}
		Polaire p(0,0);
		p.convertir(current2);
		p1 = p;
	}
	return (T)p1;
} */
/*
class BarycentreCartesien
{
	public:
		typedef vector<Point*>::const_iterator const_iterator;
		Cartesien operator()(Nuage & n)
		{
			cout << "OPERATEUR"<<endl;
			cout << n.size()<<endl;
			for(iterator it = n.begin(); it != n.end();++it)
			{
				cout << "Coucou"<<endl;
				Cartesien current(0,0);
				//(*it)->convertir(current);
				cout << "Coucou"<<endl;
				cout << current.x;
			}
			return barycentre(n);
		}
}; */
#endif
