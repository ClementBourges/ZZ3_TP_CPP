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

};
