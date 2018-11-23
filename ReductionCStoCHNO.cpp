
#include <fstream>
#include <iostream>
#include <algorithm>
#include "./include/graphReader.h"
#include "./include/Graph.h"
#include "./include/Parcours.h"
#include "./include/verifierCertificat.h"
#include "./include/Widget.h"
#include "include/graphWriter.h"

using namespace std;
int main( int argc, char** argv ){
    if(argc < 1){
        cout << "Usage: reductionCStoCHNO <inputGraph> -Optional <outputGraph>" << endl;
        return -1;
    }
    cerr << argc << endl;
    //Si un fichier cible est renseigné on écrit dans celui-ci, sinon on écrit sur la sortie standart
    streambuf * buf;
    ofstream of;
    if(argc < 3){
        buf = std::cout.rdbuf();
    }
    else{
        of.open(argv[2]);
        buf = of.rdbuf();
    }
    ostream output(buf);

    cerr << "Init OK" << endl;

    ifstream input(argv[1]);
    Graph Glecture;
    int k = graphReader::readGraphCS(Glecture, input);
    if (k==-1){
        cerr << "Problème during reading" << endl;
        return -1;
    }

    cerr << "lecture OK" << endl;

    Graph Gres;
    for(int i = 1; i<=k; i++ ) Gres.addSommet("k"+ to_string(i));
    for(auto &itLinks : Glecture.getLinks()){
       Widget W = Widget(itLinks);
       Gres.addGraph(W.getDataWidget());
    }
    // TODO : Add links Widget / graph (= E/S) (cf course given by teacher)
    //pour chaques sommets
    for(auto S: Glecture.getSommets()){
        //On regarde ses liens
        vector<Link> vL = Glecture.findLinks(S);
        // Pour chaque liens, on relie le widget précédement créer au suivant
        int i = 0;
        if( !vL.empty()){
            for(int j = 1; j<=k; j++ ) Gres.addLink(Link( vL.at(0).getS1() + vL.at(0).getS2() + to_string(6),"k"+ to_string(j)));
            for(; i < vL.size()-1; i ++){
                Gres.addLink(Link(vL.at(i).getS1() + vL.at(i).getS2() + to_string(6), vL.at(i+1).getS1() + vL.at(i+1).getS2() + to_string(1)));
            }
            //Pour le dernier lien, on le relie aux K Sommets
            for(int j = 1; j<=k; j++ ) Gres.addLink(Link( vL.at(i).getS1() + vL.at(i).getS2() + to_string(6),"k"+ to_string(j)));
        }

    }
    cerr << "crea OK" << endl;

    graphWriter::writeCHNO(Gres, output);
    cerr << "write Ok" << endl;
    return 0;
}