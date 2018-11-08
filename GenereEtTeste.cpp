#include <fstream>
#include <iostream>
#include "./include/graphReader.h"
#include "./include/Graph.h"
#include "include/Parcours.h"


using namespace std;

std::vector<std::string> permutations (std::vector<std::string> head, std::vector<std::string> tail)
{
    if (head.size()==0){
        return tail;
    }else
        for (int i = 0; i<head.size(); i++)
        {
            tail.push_back(head[i]);
            head.erase(head.begin()+i);
            permutations( head, tail);
        }
}

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
