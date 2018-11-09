#ifndef CHNO_GRAPHREADER_H
#define CHNO_GRAPHREADER_H

#include <iostream>
#include <string>
#include <sstream>
#include "Graph.h"

class graphReader{
public:
    static bool readGraph(Graph & G,std::istream & input){
        std::string str;
        std::vector<std::string> Sommets;
        std::vector<Link> Links;

        if ( !input.good() ) {
            std::cerr << "Probleme !";
            return false;
        }

        std::getline(input, str);   //Graph{
        std::getline(input, str);   //Line pour sommets
        std::string s;
        std::istringstream istr(str);
        while(istr >> s){
            Sommets.push_back(s);
        }
        istr.clear();

        std::getline(input, str);
        while(str != "}"){
            std::vector<std::string> vLin{explode(str, '-')};
            Links.emplace_back(vLin[0], vLin[1].erase(vLin[1].size() - 1 ));
            std::getline(input, str);
        }

        G = Graph(Sommets, Links);

        return true;
    }

private:
    static const std::vector<std::string> explode(const std::string& s, const char& c)
    {
        std::string buff;
        std::vector<std::string> v;

        for(auto n:s)
        {
            if(n != c) buff+=n; else
            if(n == c && !buff.empty()) { v.push_back(buff); buff = ""; }
        }
        if(!buff.empty()) v.push_back(buff);

        return v;
    }
};

#endif //CHNO_GRAPHREADER_H
