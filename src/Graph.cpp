#include "Graph.h"

Graph::Graph()
{
    //ctor
}

Graph::Graph(int nbSommet, std::vector<std::string> sommets, std::vector<Link> Links):
    m_nbSommet(nbSommet), m_sommets(sommets), m_links(Links)
    {

    }

Graph::~Graph()
{
    //dtor
}
