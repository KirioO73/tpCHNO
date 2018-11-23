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

}
