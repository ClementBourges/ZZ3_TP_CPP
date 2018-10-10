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

class Nuage 
{
	public:
		vector<Point *>vect;
		typedef vector<Point*>::const_iterator const_iterator;
		typedef std::vector<Point*>::iterator iterator;
		int size()const ;
		void ajouter(Cartesien c);
		void ajouter(Polaire p);
		const_iterator begin() const;
		const_iterator end() const;
		iterator begin(){return vect.begin();};
 		iterator end(){return vect.end();};
};

Cartesien barycentre(Nuage & n);
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
