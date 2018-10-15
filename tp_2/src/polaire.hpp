#ifndef POL
#define POL
#include <point.hpp>
#include <cartesien.hpp>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Point;
class Cartesien;

class Polaire : public Point
{
	public:
		double distance;
		double angle;
		double getAngle() const;
		double getDistance() const;
		void setAngle(const double &a);
		void setDistance(const double &a);
		Polaire(const double& a, const double& d);
		Polaire();
		Polaire(Cartesien & c);
		Polaire(const Polaire &);
		void afficher(std::stringstream & fl);
		void afficher(std::stringstream & fl) const;
		void convertir(Cartesien & c) const;
		void convertir(Polaire & p) const;
};

#endif
