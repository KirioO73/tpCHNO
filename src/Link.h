#ifndef LINK_H
#define LINK_H

#include <string>
class Link
{
    public:
        Link();
        Link(std::string s1, std::string s2);
        virtual ~Link();

        std::string getS1() const {return m_s1;}
        std::string getS2() const {return m_s2;}

    private:
        std::string m_s1;
        std::string m_s2;
};

#endif // LINK_H
