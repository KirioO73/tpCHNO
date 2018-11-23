#ifndef CHNO_GRAPHREADER_H
#define CHNO_GRAPHREADER_H

#include <iostream>
#include <string>
#include <sstream>
#include "Graph.h"

using namespace std;
class graphReader{
public:
    ///
    /// \param G: Graph ref where store readed data
    /// \param input: stream to read
    /// \return bool, true if worked
    static bool readGraphCHNO(Graph &G, istream &input){
        string str;
        vector<string> Sommets;
        vector<Link> Links;

        if ( !input.good() ) {
            cerr << "Probleme !";
            return false;
        }

        getline(input, str);   //Graph{
        getline(input, str);   //Line pour sommets
        string s;
        istringstream istr(str);
        while(istr >> s){
            Sommets.push_back(s);
        }
        istr.clear();

        getline(input, str);
        while(str != "}"){
            vector<string> vLin{explode(str, '-')};
            Links.emplace_back(vLin[0], vLin[1].erase(vLin[1].size() - 1 ));
            getline(input, str);
        }

        G = Graph(Sommets, Links);

        return true;
    }

    ///
    /// \param G: Graph ref where store readed data
    /// \param input: stream to read
    /// \return int, valeur k
    static int readGraphCS(Graph &G, istream &input){
        string str;
        vector<string> Sommets;
        vector<Link> Links;

        if ( !input.good() ) {
            cerr << "Probleme !";
            return -1;
        }
        //cerr << "lecture start OK" << endl;
        getline(input, str);   //Graph{
        getline(input, str);   //Line pour sommets
        string s;
        istringstream istr(str);
        while(istr >> s){
            Sommets.push_back(s);
        }
        istr.clear();

        //cerr << "lecture Sommet OK" << endl;

        getline(input, str);
        while(str.substr(0, str.size()-1) != "}"){
            //cerr << "lecture links " << str.substr(0, str.size()-1)  << endl;
            vector<string> vLin{explode(str, '-')};
            Links.emplace_back(vLin[0], vLin[1].erase(vLin[1].size() - 1 ));
            getline(input, str);
        }
        //cerr << "lecture Links OK" << endl;

        G = Graph(Sommets, Links);

        getline(input, str);
        if(str.substr(0, str.size()-1) == "Entier{"){
            getline(input, str);
            return stoi(str);
        }
        else{
            return -1;
        }
    }


private:
    static const vector<string> explode(const string& s, const char& c)
    {
        string buff;
        vector<string> v;

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
