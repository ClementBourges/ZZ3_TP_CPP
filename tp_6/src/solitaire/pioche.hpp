#ifndef _PIOCHE_HPP_
#define _PIOCHE_HPP_

#include "carte.hpp"
#include <vector> 

class Pioche
{
	public:
		std::vector<Carte *> cartes_;
		std::vector<Carte *> retournees_;
		bool rienRetourner();
		bool toutRetourner();
		bool estVide();
		Carte * getProchaine() const;
		Carte * getVisible() const;
		void ajouter(Carte *);
		bool tirer();
		Carte * retirer();
};

#endif
