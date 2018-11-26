#ifndef _DOCK_HPP_
#define _DOCK_HPP_

#include "carte.hpp"
#include <vector> 

class Dock
{
	public:
		std::vector<Carte *> cartes_;
		bool estVide();
		Carte * getSommet() const;
		void ajouter(Carte *);
		Carte * retirer();
};

#endif
