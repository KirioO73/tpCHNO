#include <fstream>
#include <iostream>
#include "./include/graphReader.h"
#include "./include/Graph.h"


using namespace std;
int main( int argc, char** argv ){
    if(argc < 2){
        cout << "Usage: genereEtTest <inputGraph.txt>" << endl;
    }

    ifstream input(argv[1]);
    Graph G;

    graphReader::readGraph(G, input);


    for(int i = 0; i< G.getNb(); i++){
        cout << G.getSommets().at(i) << " ";
    }
    cout << endl;
    for (int i =0; i< G.getNbLink(); i++){
        cout << G.getLinks().at(i).getS1() << "," << G.getLinks().at(i).getS2() << endl;
    }
    return 0;
}
