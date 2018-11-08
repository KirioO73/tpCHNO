#include <iostream>
#include "include/verifierCertificat.h"
#include <vector>

int main() {
    std::vector<std::string> sommets = {"s1", "s2", "s3", "s4" };
    std::vector<Link> links = { Link("s1", "s4"), Link("s2","s1"), Link("s3", "s2"), Link("s4", "s2"), Link("s1", "s3")};
    Graph G = Graph(4,sommets, links );
    std::vector<std::string> chemin = {"s1", "s3", "s2", "s4"};
    Parcours P = Parcours(4, chemin);
    if (Verifier::verifierCertificat(G,P)) std::cout << "ok" << std::endl;
    else std::cout<<"nonOk"<< std::endl;
    return 0;
}