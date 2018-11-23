#include <utility>
#include <iostream>

#include "../include/Graph.h"

Graph::Graph()
{
    m_nbSommet = 0;
    m_nbLink = 0;
    m_links = std::vector<Link>();
    m_sommets = std::vector<std::string>();
}

Graph::Graph(std::vector<std::string> sommets, std::vector<Link> Links):
        m_nbSommet(sommets.size()), m_sommets(sommets), m_links(Links), m_nbLink(Links.size())
{

}


Graph::Graph(int nbSommet, std::vector<std::string> sommets, std::vector<Link> Links):
    m_nbSommet(nbSommet), m_sommets(std::move(sommets)), m_links(Links), m_nbLink(Links.size())
    {

    }

Graph::Graph(int nbSommet, std::vector<std::string> sommets, int nbLinks, std::vector<Link> Links):
        m_nbSommet(nbSommet), m_sommets(std::move(sommets)), m_links(std::move(Links)), m_nbLink(nbLinks)
{

}

int Graph::findSommet(const std::string &sommet) const {
    for (int i = 0; i < getNb(); i++){
        if (m_sommets.at(i) == sommet) return i;
    }
    return -1;
}

std::vector<Link> Graph::findLinks(const std::string &sommet) const{
    std::vector<Link> res;
    for (int i = 0; i < getNbLink(); i++){
        if (m_links.at(i).getS1() == sommet || m_links.at(i).getS2() == sommet) res.push_back(m_links.at(i));
    }
    return res;
}

std::vector <Link> Graph::findLinksFirst(const std::string sommet) {
    std::vector<Link> res;
    for (int i = 0; i < getNbLink(); i++){
        if (m_links.at(i).getS1() == sommet) res.push_back(m_links.at(i));
    }
    return res;
}

void Graph::addSommet(std::string sommet) {
    m_sommets.push_back(sommet);
    m_nbSommet++;
}

void Graph::addLink(Link L) {
    m_links.push_back(L);
    m_nbLink++;
}

void Graph::addGraph(Graph otherG) {
    for (const auto &S : otherG.getSommets()) addSommet(S);
    for (const auto &L : otherG.getLinks()) addLink(L);
}


/*void Graph::addGraphWidget(Widget W) {
    getSommets().insert(m_sommets.end(), W.getDataWidget().getSommets().begin(), W.getDataWidget().getSommets().end());
    getLinks().insert(m_links.end(), W.getDataWidget().getLinks().begin(), W.getDataWidget().getLinks().end());
    m_nbSommet = m_sommets.size();
    m_nbLink = m_links.size();
}*/



