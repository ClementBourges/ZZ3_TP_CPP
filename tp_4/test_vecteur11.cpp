// Entetes //---------------------------------------------------------------------------------------
#include <algorithm>
#include <deque>
#include <vecteur11.hpp>

// Operations binaires sous differentes formes //---------------------------------------------------

//------------------------------------------------------------------------------------------Foncteur
struct SoustractionComplexe {
 complexe_t operator() (const complexe_t & a,const complexe_t & b) const
 { return complexe_t(a.reel-b.reel,a.imaginaire-b.imaginaire); }
};

//------------------------------------------------------------------------------------------Fonction
inline complexe_t multiplier_complexes(const complexe_t & a,const complexe_t & b) {
 return complexe_t(a.reel*b.reel-a.imaginaire*b.imaginaire,
                   a.reel*b.imaginaire+a.imaginaire*b.reel);
}

// Fonction principale //---------------------------------------------------------------------------
int main(void) {
 Vecteur v1;
 Vecteur v2;

 complexe_t::stats();

 unsigned i = 0; for (complexe_t & c : v1) { c=complexe_t(10*i,i*i); ++i; }
 i=0; for (complexe_t & c : v2) { c=complexe_t(i,i+1); ++i; }

 std::cout << std::endl << "v1 = " << v1 << std::endl;
 std::cout << "v2 = " << v2 << std::endl;
 complexe_t::stats();

 Vecteur v3 = v1;

 std::cout << std::endl << "v3 = " << v3 << std::endl;
 complexe_t::stats();

 Vecteur v4;

 v4=v1+v2;

 std::cout << std::endl << "v4 = " << v4 << std::endl;
 complexe_t::stats();

 Vecteur v5;

 v5=v1*v2;

 std::cout << std::endl << "v5 = " << v5 << std::endl;
 complexe_t::stats();

 std::deque<complexe_t> liste;

 for (complexe_t & c : v5) liste.push_back(c);

 std::cout << std::endl << "liste = v5" << std::endl;
 complexe_t::stats();

 std::sort(liste.begin(),liste.end(),[] (const complexe_t & a,const complexe_t & b) {
                                      return (a.reel<b.reel
                                              || (a.reel==b.reel && a.imaginaire<b.imaginaire));
                                     });

 std::cout << std::endl;
 for (complexe_t & c : liste) std::cout << c << " ";
 std::cout << std::endl;
 complexe_t::stats();

 Vecteur v6, v7, v8;

 v6=appliquer(v1,v2,[] (const complexe_t & a,const complexe_t & b) { return a+b; });
 v7=appliquer(v1,v2,SoustractionComplexe());
 v8=appliquer(v1,v2,&multiplier_complexes);

 std::cout << std::endl << "v6 = " << v6 << std::endl;
 std::cout << "v7 = " << v7 << std::endl;
 std::cout << "v8 = " << v8 << std::endl;
 complexe_t::stats();
}

// Fin //-------------------------------------------------------------------------------------------
