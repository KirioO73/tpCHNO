#include <utility>

#include "../include/Parcours.h"

Parcours::Parcours(int len, std::vector<std::string> chemin): m_lenChemin(len), m_chemin(std::move(chemin))
{

}
