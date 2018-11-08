#include <classe.hpp>


Classe::Classe()
{
  borneinf=0;
  bornesup=0;
  quantite=0;
}
Classe::Classe(double a, double b)
{
  this->setBorneInf(a);
  this->setBorneSup(b);
  quantite=0;
}

double Classe::getBorneInf()const
{
 return borneinf;
}
double Classe::getBorneSup()const
{
  return bornesup;
}
int Classe::getQuantite()const
{
  return quantite;
}
void Classe::setBorneInf(double x)
{
  borneinf=x;
}
void Classe::setBorneSup(double x)
{
  bornesup=x;
}
void Classe::setQuantite(int x)
{
  quantite=x;
}
void Classe::ajouter()
{
  quantite++;
}
