#include <point.hpp>

std::stringstream & operator <<(std::stringstream& Stream, const Point& Obj) 
{ 
    Obj.afficher(Stream); 
    return Stream; // N'oubliez pas de renvoyer le flux, afin de pouvoir chaîner les appels 
}
