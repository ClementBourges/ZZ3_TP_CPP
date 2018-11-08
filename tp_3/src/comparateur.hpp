#include "classe.hpp"

template<typename T >
class ComparateurQuantite< Classe > {
	bool operator() (Classe a, Classe b)
	{
  	return a.getQuantite()<b.getQuantite();
	}
};
