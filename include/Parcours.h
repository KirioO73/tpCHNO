#ifndef PARCOURS_H
#define PARCOURS_H

#include <vector>
#include <string>

class Parcours
{
    public:
        Parcours() = default;
        Parcours(int len, std::vector<std::string> chemin);
        virtual ~Parcours() = default;

        std::vector<std::string> getChemin() const {return m_chemin; }
        int getLen() const {return m_lenChemin;}

    private:
        int m_lenChemin{};
        std::vector<std::string> m_chemin;

};

#endif // PARCOURS_H
