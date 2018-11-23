#include <fstream>
#include <iostream>
#include <algorithm>
#include "./include/graphReader.h"
#include "./include/Graph.h"
#include "./include/Parcours.h"
#include "./include/verifierCertificat.h"

using namespace std;
int main( int argc, char** argv ){
    if(argc < 2){
        cout << "Usage: genereEtTest <inputGraph>" << endl;
    }
    cerr << "Init OK" << endl;

    ifstream input(argv[1]);
    Graph G;
    graphReader::readGraphCHNO(G, input);

    cerr << "lecture OK" << endl;

    Parcours Parc;
    vector<Parcours> ParcoursGenerer;
    vector<string> Sommets;
    Sommets = G.getSommets();


    sort(Sommets.begin(), Sommets.end());
    do{
        Parc = Parcours(Sommets.size(), Sommets);
        ParcoursGenerer.emplace_back(Parc);
    }while(next_permutation(Sommets.begin(), Sommets.end()));


    for (auto &P : ParcoursGenerer) {
        /*for(auto &t : P.getChemin()) cout << t << " ";
        cout <<  "len " << P.getLen() <<endl;*/
        if (Verifier::verifierCertificat(G, P)){
            cout << "true" << endl;
            return 0;
        }
    }
    cout << "ce n'est pas un CHNO" << endl;
    return 0;
}
