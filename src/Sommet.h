#ifndef SOMMET_H
#define SOMMET_H

#include <iostream>
#include <vector>

class Sommet
{
    public:
        typedef std::vector<Sommet&> Others;

        Sommet();
        virtual ~Sommet();

        char* Getid() const { return m_id; }
        void Setid(char* val){ m_id = val; }

        int GetnbLink()const { return m_nbLink; }
        void SetnbLink(int val){ m_nbLink = val; }

        Sommet();
        Sommet(int id, int nbLinks);
        Sommet(int id, int nbLinks, Sommet[] links);

    private:
        char* m_id;s
        int m_nbLink;
        Others m_links;
};

#endif // SOMMET_H
