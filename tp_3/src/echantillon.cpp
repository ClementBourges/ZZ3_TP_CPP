#include <echantillon.hpp>
#include<stdexcept>

int Echantillon::getTaille() const
{
  return ech.size();
}

void Echantillon::ajouter(double a)
{
  ech.push_back(a);
}

Valeur Echantillon::getMinimum() const
{
  Valeur val;
  if(ech.size()>0)
  {
    val= ech.at(0);
    for(unsigned int i=0;i<ech.size();i++)
    {
      if(ech.at(i).getNombre()<val.getNombre())
      {
        val=ech.at(i);
      }
    }
  }
  else
  {
    throw std::domain_error("erreur");
  }
  return val;
}
Valeur Echantillon::getMaximum() const
{
  Valeur val;
  if(ech.size()>0)
  {
    val= ech.at(0);
    for(unsigned int i=0;i<ech.size();i++)
    {
      if(ech.at(i).getNombre()>val.getNombre())
      {
        val=ech.at(i);
      }
    }
  }
  else
  {
    throw std::domain_error("erreur");
  }
  return val;
}

Valeur Echantillon::getValeur(int i) const
{
  return ech.at(i);
}
