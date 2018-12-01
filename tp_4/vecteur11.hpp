// Gardien //---------------------------------------------------------------------------------------
#ifndef _VECTEUR11_HPP_
#define _VECTEUR11_HPP_

// Entetes //---------------------------------------------------------------------------------------
#include <complexe.hpp>
#include <stdexcept>

// Classe  V e c t e u r //-------------------------------------------------------------------------
class Vecteur {
 //----------------------------------------------------------------------------------------Attributs
 private:
  unsigned     taille_;
  complexe_t * tableau_;

 //---------------------------------------------------------------------------------------Accesseurs
 public:
  unsigned getTaille(void) const { return taille_; }

  complexe_t & operator[](unsigned i) {
   if (i<taille_) return tableau_[i];
   throw std::out_of_range("");
  }

  const complexe_t & operator[](unsigned i) const {
   if (i<taille_) return tableau_[i];
   throw std::out_of_range("");
  }

 public:
  //-----------------------------------------------------------------------------Constructeur defaut
  explicit Vecteur(unsigned t = 10) : taille_(t),tableau_(new complexe_t[taille_]) {}

  //------------------------------------------------------------------------------Constructeur copie
  Vecteur(const Vecteur & v) : taille_(v.taille_),tableau_(new complexe_t[taille_]) {
   for (unsigned i = 0; i<taille_; ++i) tableau_[i]=v[i];
  }

  //--------------------------------------------------------------------------Constructeur mouvement
  Vecteur(Vecteur && v) : taille_(v.taille_),tableau_(v.tableau_) {
   v.taille_=0;
   v.tableau_=0;
  }

  //-------------------------------------------------------------------------------------Destructeur
  ~Vecteur(void) { if (tableau_) delete [] tableau_; }

  //-------------------------------------------------------------------------------Affectation copie
  Vecteur & operator=(const Vecteur & v) {
   if (this!=&v) {
    if (taille_!=v.taille_) throw std::length_error("");
    for (unsigned i = 0; i<v.taille_; ++i) tableau_[i]=v[i];
   }

   return *this;
  }

  //---------------------------------------------------------------------------Affectation mouvement
  Vecteur & operator=(Vecteur && v) {
   if (taille_!=v.taille_) throw std::length_error("");
   std::swap(tableau_,v.tableau_);
   return *this;
  }

  //-------------------------------------------------------------------------Interface iterateur STL
  typedef complexe_t *       iterator;
  typedef const complexe_t * const_iterator;

  iterator       begin(void) { return tableau_; }
  const_iterator begin(void) const { return tableau_; }

  iterator       end(void) { return tableau_+taille_; }
  const_iterator end(void) const { return tableau_+taille_; }
};

// Surcharge operateurs //--------------------------------------------------------------------------

//----------------------------------------------------------------------------------------operator<<
inline std::ostream & operator<<(std::ostream & flux,const Vecteur & v) {
 for (unsigned i = 0; i<v.getTaille(); ++i) flux << v[i] << " ";
 return flux;
}

//-----------------------------------------------------------------------------------------operator+
inline Vecteur operator+(const Vecteur & v1,const Vecteur & v2) {
 Vecteur v;

 for (unsigned i = 0; i<v1.getTaille(); ++i) v[i]=v1[i]+v2[i];

 return v;
}

//-----------------------------------------------------------------------------------------operator*
inline Vecteur operator*(const Vecteur & v1,const Vecteur & v2) {
 Vecteur v;

 for (unsigned i = 0; i<v1.getTaille(); ++i) v[i]=v1[i]*v2[i];

 return v;
}

// Fonctions //-------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------appliquer
template <class OP>
inline Vecteur appliquer(const Vecteur & v1,const Vecteur & v2,const OP & op) {
 Vecteur v;

 for (unsigned i = 0; i<v1.getTaille(); ++i) v[i]=op(v1[i],v2[i]);

 return v;
}

// Fin //-------------------------------------------------------------------------------------------
#endif
