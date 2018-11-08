#include <string>

class Valeur
{
	private:
		double x;
		std::string nom;
	public:
		Valeur();
		Valeur(double x0);
		Valeur(double x0, const char * n);
		double getNombre() const ;
		double getNote() const;
		void setNote(double n);
		std::string getEtudiant() const;
		void setEtudiant(std::string et);
		void setNombre(double x0) ;
};
