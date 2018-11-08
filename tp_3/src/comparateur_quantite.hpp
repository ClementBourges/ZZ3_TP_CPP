#ifndef COMP
#define COMP

#include "classe.hpp"

template<typename T >
class ComparateurQuantite
{

};

template<>
class ComparateurQuantite< Classe >
{
	public:
	bool operator()(const Classe & p1, const Classe & p2) const
	{
		double p1Q = p1.getQuantite(), p2Q = p2.getQuantite();
		if( (p1Q-p2Q) == 0)
		{
			return p1 < p2;
		}
		return p1Q > p2Q;
	}
};

#endif
