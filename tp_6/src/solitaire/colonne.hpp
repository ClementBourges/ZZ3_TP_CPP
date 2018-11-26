#ifndef _COLONNE_HPP_
#define _COLONNE_HPP_

#include "carte.hpp"
#include <vector> 
class Colonne
{
	public:
		std::vector<Carte *> cartes_;
		bool estVide();
		Carte * getSommet();
		void ajouter(Carte *);
		Carte * retirer();
	
		int getTaille() const;
		Carte * getCarte(int index) const;
		
};

#endif
