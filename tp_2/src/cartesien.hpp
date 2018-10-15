#ifndef CAR
#define CAR
#include <point.hpp>
#include <polaire.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include <math.h>

using namespace std;

class Point;
class Polaire;

class Cartesien : public Point
{
	public:
		double y;
		double x;
		double getX() const;
		double getY() const;
		void setX(const double &a);
		void setY(const double &a);
		Cartesien(const double& a, const double& d);
		Cartesien();
		Cartesien(const Polaire &);
		Cartesien(const Cartesien &);
		void afficher(std::stringstream & fl);
		void afficher(std::stringstream & fl) const;
		void convertir(Polaire & p) const;
		void convertir(Cartesien & c) const;
};

#endif
