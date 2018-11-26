// Entetes //---------------------------------------------------------------------------------------
#include <ctime>
#include <cstdlib>
#include <QApplication>
#include <controleur_graphique.hpp>
#include <controleur_texte.hpp>

//-----------------------------------------------------------------------------------CreerControleur
Controleur * creerControleur(const std::string & type,Solitaire & solitaire,QApplication & appli) {
 if (type=="txt") return new ControleurTexte(solitaire);
 else if (type=="gui") return new ControleurGraphique(solitaire,appli);

 return 0;
}

//----------------------------------------------------------------------------------------------Main
int main(int argc,char ** argv) {
 QApplication appli(argc,argv);

 Solitaire    solitaire;
 std::string  typeInterface = (argc>=2 ? argv[1] : "txt");
 Controleur * controleur = creerControleur(typeInterface,solitaire,appli);

 if (controleur==0) {
  std::cout << "Option d'affichage invalide." << std::endl;
  return 1;
 }

 std::srand(time(0));
 solitaire.setControleur(*controleur);
 controleur->demarrer();

 delete controleur;

 return 0;
}

// Fin //-------------------------------------------------------------------------------------------
