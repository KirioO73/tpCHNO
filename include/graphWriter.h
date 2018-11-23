#ifndef CHNO_GRAPHWRITTER_H
#define CHNO_GRAPHWRITTER_H

#include <iostream>
#include <string>
#include <sstream>
#include "Graph.h"

using namespace std;

class graphWriter{
public:

    static bool writeCHNO( const Graph &G, ostream &output){
        output << "Graph{" << endl;
        for (const auto &S : G.getSommets()){
            //cerr << "write " <<  S << endl;
            output << S << " ";
        }
        output << endl;
        for (const auto &L : G.getLinks()){
            //cerr << "write " << L.getS1() << " - " << L.getS2() << endl;
            output << L.getS1() << " - " << L.getS2() << endl;
        }
        output << "}";
    }

private:

};

#endif //CHNO_GRAPHWRITTER_H
