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
        void setS1(std::string s1) {m_s1=s1;}
        void setS2(std::string s2) {m_s2=s2;}

        bool match(std::string s1, std::string s2) const{
            return ((s1==m_s1 && s2==m_s2) || (s1==m_s2 && s2==m_s1));
        }

    private:
        std::string m_s1;
        std::string m_s2;
};

#endif // LINK_H
