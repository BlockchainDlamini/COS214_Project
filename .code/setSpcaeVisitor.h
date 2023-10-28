#ifndef SETSPACEVISITOR_H
#define SETSPACEVISITOR_H

#include "floorComponent.h"
#include "floorComposite.h"
#include "table.h"
#include <memory>

class setSpaceVisitor: public visitor
{
    private:
        int space;
    public:
        setSpaceVisitor(int newSpace);
        int visitTable(std::shared_ptr<table>);
        int visitTile(std::shared_ptr<floorComposite>);
        ~setSpaceVisitor(){};
};

#endif