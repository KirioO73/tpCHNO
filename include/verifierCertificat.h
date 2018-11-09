
#include "Graph.h"
#include "Parcours.h"
#include "Link.h"
#include <iostream>


class Verifier{
public:
    static bool verifierCertificat(const Graph &G, Parcours P)
    {
        //test taille : le parcours doit prendre tous les Sommet en compte, il doit donc avoir le même nombre d'élem que le graph
        if (P.getLen() != G.getNb()) return false;
        else
        {
            //std::cout << "taille ok" << std::endl;
            //test doublons : le Parcours ne doit passer qu'une seule fois par chaque sommet
            for (int i = 0; i < P.getLen() - 1; i++){
                for(int y = i+1; y < P.getLen(); y++){
                    if (P.getChemin().at(i) == P.getChemin().at(y)) return false;
                }
            }
            //std::cout << "doublon ok" << std::endl;
            //test parcours valide
            //Commence au première elem du parcour
            std::string first = P.getChemin().at(0);
            for (int iParc = 1; iParc < P.getLen(); iParc++){   //On parcour
                std::vector<Link> links = G.findLinks(first);   //Obtiens tous les liens du première elem
                if (links.size() == 0) return false;             //S'il n'y a aucun lien, on ne peut plus avancer plus loins, c'est donc faux
                else{
                    for(int iLink = 0; iLink < links.size() ; iLink++){                 //on regarde si parmi les liens du 1er elem, il y en a un qui mène au suivant
                        //std::cout << links.at(iLink).getS1() << "," << links.at(iLink).getS2() << " pour " << first << " to " << P.getChemin().at(iParc) << std::endl;
                        if(links.at(iLink).match(first, P.getChemin().at(iParc))){
                            first = P.getChemin().at(iParc);                            //Si oui, on avance le 1er elem et on continue
                            break;
                        }
                    }
                    if (first != P.getChemin().at(iParc)) return false; //Si first n'a pas avancer, ca veut dire qu'on a pas trouver de lien
                }
            }
        }
        return true;
    }
};

