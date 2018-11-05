#include <vector>
#include "classe.hpp"
#include <iterator>


class Histogramme
{
	private:
  public:
    std::vector<Classe> cla;
    Histogramme(double a,double b, int t);
    typedef std::vector<Classe> classes_t;
    typedef std::vector<Classe>::const_iterator const_iterator;
    const std::vector<Classe> & getClasses() const;
	void ajouter(Echantillon e) const;

};
