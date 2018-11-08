
#include "Graph.h"
#include "Parcours.h"
#include "Link.h"
#include <iostream>

bool verifierCertificat(Graph G, Parcours P)
{
    if (P.getLen() != G.getNb()) return false;
    else
    {
        //test doublons
        for (int i = 0; i < P.getLen() - 1; i++){
            for(int y = i+1; y < P.getLen(); y++){
                if (P.getChemin().at(i) == P.getChemin().at(y)) return false;
            }
        }

        std::string first = P.getChemin().at(0);
        for (int iParc = 1; iParc < P.getLen(); iParc++){
            for(int iLink = 0; iLink < G.getNbLink(); iLink++){
                Link L = G.getLinks().at(iLink);
                if (iLink == G.getNbLink() && !((L.getS1() == first && L.getS2() == P.getChemin().at(iParc))
                                                || (L.getS1() == P.getChemin().at(iParc) && L.getS2() == first)) ) return false;
            }
        }
    }
    return true;
}
