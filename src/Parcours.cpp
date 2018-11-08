#include "../include/Parcours.h"

Parcours::Parcours()
{
    //ctor
}

Parcours::Parcours(int len, std::vector<std::string> chemin): m_lenChemin(len), m_chemin(chemin)
{

}

Parcours::~Parcours()
{
    //dtor
}
