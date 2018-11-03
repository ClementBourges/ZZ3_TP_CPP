#include "histogramme.hpp"
#include <iostream>

typedef Histogramme Histo;

Histogramme::Histogramme(double a,double b, int t)
{
  double pas=2;
  int i=0;
  for(i=0; i<t;i++)
  {
    double abis=a+(i*pas);
    std::cout<<"Dans la classe, a="<<abis<<std::endl;
    cla.push_back(Classe(abis,(b-(t-1)*pas+i*pas)));
  }
  Histo::classes_t::const_iterator it = cla.begin();
  unsigned                         j  = 0;
  while (it!=cla.end()) {
    std::cout<<"Borneinf:"<<it->getBorneInf()<<std::endl;
    std::cout<<"Bornesup:"<<it->getBorneSup()<<std::endl;
    std::cout<<"Quantite"<<it->getQuantite()<<std::endl;

   //REQUIRE ( it->getBorneInf() == Approx(bornesInf[i]) );
   //REQUIRE ( it->getBorneSup() == Approx(bornesSup[i]) );
   //REQUIRE ( it->getQuantite() == 0u );
   ++it;
   ++j;
  }
}

std::vector<Classe> Histogramme::getClasses() const
{
  return cla;
}
