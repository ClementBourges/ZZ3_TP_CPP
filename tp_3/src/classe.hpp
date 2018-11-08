#ifndef CLASSE_HPP
#define CLASSE_HPP

class Classe
{
	private:
	double borneinf;
      double bornesup;
      int quantite;
  public:
    double getBorneInf() const;
    double getBorneSup() const;
    int getQuantite() const;
    void setBorneInf(double);
    void setBorneSup(double);
    void setQuantite(int);
    void ajouter();
    Classe(double a, double b);
		Classe();
		bool operator<(Classe const &a)const{return (borneinf<a.borneinf);};
		bool operator>(Classe const &a)const{return (borneinf>a.borneinf);};


};

#endif
