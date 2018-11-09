
#include <fstream>
#include <iostream>
#include <algorithm>
#include "./include/graphReader.h"
#include "./include/Graph.h"
#include "./include/Parcours.h"
#include "./include/verifierCertificat.h"
#include "./include/Widget.h"

using namespace std;
int main( int argc, char** argv ){
    if(argc < 2){
        cout << "Usage: reductionCStoCHNO <inputGraph>" << endl;
    }

    ifstream input(argv[1]);
    Graph Glecture;
    int k = graphReader::readGraphCS(Glecture, input);
    if (k==-1){
        cerr << "Problème during reading" << endl;
        return -1;
    }

    Graph Gres;
    for(int i=1; i <= k; ++i){
        Gres.addSommet("s"+ to_string(i));
    }
    for(auto &itLinks : Glecture.getLinks()){
       Widget W = Widget(itLinks);
       Gres.addGraph(W.getDataWidget());
    }

}