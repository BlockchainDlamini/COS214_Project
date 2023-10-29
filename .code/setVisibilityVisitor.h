#ifndef SETVISIBILITYVISITOR_H
#define SETVISIBILITYVISITOR_H

#include "visitor.h"
class setVisibilityVisitor: public visitor
{
    private:
        int newVisibility;
    public:
        setVisibilityVisitor(int);
        int visitTable(std::shared_ptr<table>);
        int visitTile(std::shared_ptr<floorComposite>);
        ~setVisibilityVisitor(){};
};

#endif