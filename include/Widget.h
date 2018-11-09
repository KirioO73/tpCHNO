#ifndef CHNO_WIDGET_H
#define CHNO_WIDGET_H

#include "Link.h"
#include "Graph.h"

class Widget {
public:
    Widget() = default;
    Widget(Link L);

    Graph getDataWidget() const {return m_dataWidget;}

    virtual ~Widget() = default;
private:
    Graph m_dataWidget;
};


#endif //CHNO_WIDGET_H
