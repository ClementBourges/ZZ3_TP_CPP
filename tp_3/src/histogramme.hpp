#include <vector>
#include "classe.hpp"
#include <iterator>
#include <iostream>
#include "echantillon.hpp"
#include <set>
#include <map>
#include <comparateur_quantite.hpp>

template<typename T = std::less<Classe> >
class Histogramme
{
  public:
/*
std::vector<Classe> cla;
	//std::set<Classe> cla;
    Histogramme(double a,double b, int t);
    typedef std::vector<Classe> classes_t;
    typedef std::vector<Classe>::const_iterator const_iterator;
    const std::vector<Classe> & getClasses() const;
*/
	typedef std::set<Classe > classes_t;
	typedef std::multimap<Classe, Valeur,std::less<Classe>> valeurs_t;
	typedef std::multimap<Classe, Valeur,std::less<Classe>>::iterator it_valeurs_t;

	std::set<Classe, T > cla;
	std::multimap<Classe, Valeur, std::less<Classe>> map;
	Histogramme(double a,double b, int t);
	Histogramme(Histogramme<std::greater<Classe>>& h);
	const std::set<Classe, T > & getClasses()const{return cla;};
	void ajouter(Echantillon e);
	void ajouter(double d);
	const std::multimap<Classe, Valeur,std::less<Classe>> & getValeurs();
	std::pair<it_valeurs_t,it_valeurs_t> getValeurs(const Classe & c);


};

typedef std::multimap<Classe, Valeur,std::less<Classe>>::iterator it_valeurs_t;
template<typename T >
std::pair<it_valeurs_t,it_valeurs_t> Histogramme<T>::getValeurs(const Classe & c)
{
	return map.equal_range(c);
}


template<typename T >
Histogramme<T>::Histogramme(Histogramme<std::greater<Classe>>& h)
{
	Histogramme::classes_t::iterator ith = h.getClasses().begin();
	 while (ith!=h.getClasses().end())
	{
				Classe tmp_classe(*ith);
				cla.insert(tmp_classe);
				ith++;
	}
}

template<typename T >
Histogramme<T>::Histogramme(double a,double b, int t)
{
  double pas=(b-a)/t;
  int i=0;
  for(i=0; i<t;i++)
  {
    double abis=a+(i*pas);
    //cla.push_back(Classe(abis,(b-(t-1)*pas+i*pas)));
		cla.insert(Classe(abis,(b-(t-1)*pas+i*pas)));
  }
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
				Classe tmp_classe(*it);
				tmp_classe.ajouter();
				cla.erase(it);
				cla.insert(tmp_classe);
				it=cla.end();
			}
			else
			{
			  ++it;
			}
	 	}
	}
}

template<typename T >
void Histogramme<T>::ajouter(double d)
{
		Histogramme::classes_t::iterator it = cla.begin();
		 while (it!=cla.end())
		{
			if(d >= it->getBorneInf() && d < it->getBorneSup())
			{
				map.insert(std::pair<Classe, Valeur>(*it, Valeur(d)));
				Classe tmp_classe(*it);
				tmp_classe.ajouter();
				cla.erase(it);
				cla.insert(tmp_classe);
				it=cla.end();
			}
			else
			{
			  ++it;
			}
	 	}
}

template<typename T >
const std::multimap<Classe, Valeur, std::less<Classe>>& Histogramme<T>::getValeurs()
{
	return map;
}
