#ifndef POINT
#define POINT
#include <iostream>
#include <sstream>
#include <string>

class Cartesien;
class Polaire;

using namespace std;
class Point
{
	public:
		void afficher(std::stringstream & fl);
		virtual void afficher(std::stringstream & fl) const = 0;
		virtual void convertir(Cartesien & c) const =0;
		virtual	void convertir(Polaire & p) const =0;

};

std::stringstream & operator <<(std::stringstream & Stream, const Point& Obj);

#endif
