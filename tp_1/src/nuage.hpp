#ifndef NUA
#define NUA
#include <point.hpp>
#include <cartesien.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Point;
class Cartesien;

class Nuage 
{
	public:
		vector<Point *> vect;
		int size();
		void ajouter(Cartesien c);
		void ajouter(Polaire p);
};

#endif
