#include "histogramme.hpp"
#include <iostream>

typedef Histogramme Histo;

Histogramme::Histogramme(double a,double b, int t)
{
  double pas=(b-a)/t;
  int i=0;
  for(i=0; i<t;i++)
  {
    double abis=a+(i*pas);
    std::cout<<"Dans la classe, borneinf="<<abis<<std::endl;
    cla.push_back(Classe(abis,(b-(t-1)*pas+i*pas)));
  }
}
const std::vector<Classe> & Histogramme::getClasses() const
{
  return cla;
}

void Histogramme::ajouter(Echantillon e) const;
