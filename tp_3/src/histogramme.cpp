#include "histogramme.hpp"
#include <iostream>

typedef Histogramme Histo;

template <T>
Histogramme::Histogramme(double a,double b, int t)
{
  double pas=(b-a)/t;
  int i=0;
  for(i=0; i<t;i++)
  {
    double abis=a+(i*pas);
    //cla.push_back(Classe(abis,(b-(t-1)*pas+i*pas)));
	cla.insert(Classe(abis,(b-(t-1)*pas+i*pas));
  }
}


template <T>
const std::vector<Classe> & Histogramme::getClasses() const
{
  return cla;
}

template <T>
void Histogramme::ajouter(Echantillon e)
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
