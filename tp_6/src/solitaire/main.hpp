#ifndef MAIN_HPP
#define MAIN_HPP

class Main
{
	public:
		std::vector<Carte *> cartes_;
		int size()const {return cartes_.size();};
		Carte * operator[](int n) const {return cartes_.at(n);};
};

#endif
