#ifndef SETVISIBILITYVISITOR_H
#define SETVISIBILITYVISITOR_H

#include "floorComponent.h"
#include "floorComposite.h"
#include "table.h"
#include "visitor.h"
#include <memory>

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