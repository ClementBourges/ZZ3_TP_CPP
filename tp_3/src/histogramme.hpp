#include <vector>
#include "classe.hpp"
#include <iterator>
#include <iostream>
#include "Echantillon.hpp"

#define CONTAINER_TYPE	SET

template<typename T = std::less<Classe> >
class Histogramme
{
	private:
  public:
#if CONTAINER_TYPE == VECTOR 
std::vector<Classe> cla;
	//std::set<Classe> cla;
    Histogramme(double a,double b, int t);
    typedef std::vector<Classe> classes_t;
    typedef std::vector<Classe>::const_iterator const_iterator;
    const std::vector<Classe> & getClasses() const;
#elif CONTAINER_TYPE == SET
	std::set<Classe, T > ensemble;
	public:
	typedef std::set<Classe > classes_t;
	Histogramme(double low_b = 0, double upper_b = 0, unsigned classNb = 0);
	const std::set<Classe, T > & getClasses()const{return ensemble;};
#endif
void ajouter(Echantillon e);

};



template<typename T >
Histogramme<T>::Histogramme(double a,double b, int t)
{
  double pas=(b-a)/t;
  int i=0;
  for(i=0; i<t;i++)
  {
    double abis=a+(i*pas);
    cla.push_back(Classe(abis,(b-(t-1)*pas+i*pas)));
	//cla.insert(Classe(abis,(b-(t-1)*pas+i*pas));
  }
}

template<typename T >
const std::vector<Classe> & Histogramme<T>::getClasses() const
{
  return cla;
}

template<typename T >
void Histogramme<T>::ajouter(Echantillon e)
{

	for(int i=0; i<e.getTaille(); i++)
	{

		Valeur v = e.getValeur(i);
		Histogramme::classes_t::iterator it = cla.begin();
		 while (it!=cla.end())
		{
			if(v.getNombre() >= it->getBorneInf() && v.getNombre() < it->getBorneSup())
			{
					int q = it->getQuantite();
					it->setQuantite(q + 1);
			}
			  ++it;
	 	}
	}
}
