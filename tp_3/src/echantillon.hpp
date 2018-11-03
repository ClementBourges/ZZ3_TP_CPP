#include "valeur.hpp"
#include <vector>

class Echantillon
{
	private:
			std::vector<Valeur>ech;
  public:
    int getTaille() const;
    void ajouter(double a);
    Valeur getMinimum() const;
    Valeur getMaximum() const;
		Valeur getValeur(int i) const;

};
