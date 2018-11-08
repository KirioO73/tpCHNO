#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <vector>
#include "Link.h"

class Graph
{
    public:
        Graph();
        Graph(int nbSommets);
        Graph(std::vector<std::string> sommets, std::vector<Link> links);
        Graph(int nbSommets, std::vector<std::string> sommets, std::vector<Link> links);
        Graph(int nbSommets, std::vector<std::string> sommets, int nbLinks, std::vector<Link> links);
        virtual ~Graph();

        int getNb()const {return m_nbSommet;}
        int getNbLink()const {return m_nbLink;}

        std::vector<std::string> getSommets() const {return m_sommets;}
        std::vector<Link> getLinks() const {return m_links;}

        int findSommet(const std::string &sommet) const;

        std::vector<Link> findLinks(const std::string &sommet);

        void addSommet(std::string sommet);

    private:
        int m_nbSommet;
        int m_nbLink;
        std::vector<std::string> m_sommets;
        std::vector<Link> m_links;

};

#endif // GRAPH_H
