#include "../include/Widget.h"
#include <vector>

Widget::Widget(Link L) {
    std::vector<Link> Links;
    std::vector<std::string> Sommets;

    //12 Sommets
    for(int i=1; i<=6; i++){
        Sommets.push_back(L.getS1() + L.getS2() + std::to_string(i));
        Sommets.push_back(L.getS2() + L.getS1() + std::to_string(i));
    }
    //10 Links
    for(int i=2; i<=6; i++){
        Links.emplace_back(Link(L.getS1() + L.getS2() + std::to_string(i - 1),L.getS1() + L.getS2() + std::to_string(i)));
        Links.emplace_back(Link(L.getS2() + L.getS1() + std::to_string(i - 1),L.getS2() + L.getS1() + std::to_string(i)));
    }
    //4 Lasts Links
    Links.emplace_back(Link(L.getS1() + L.getS2() + "1",L.getS2() + L.getS1() + "3"));
    Links.emplace_back(Link(L.getS1() + L.getS2() + "3",L.getS2() + L.getS1() + "1"));
    Links.emplace_back(Link(L.getS1() + L.getS2() + "4",L.getS2() + L.getS1() + "6"));
    Links.emplace_back(Link(L.getS1() + L.getS2() + "6",L.getS2() + L.getS1() + "4"));


    m_dataWidget = Graph(Sommets, Links);
}
