#ifndef FINDSPACEVISITOR_H
#define FINDSPACEVISITOR_H

#include "floorComponent.h"
#include "floorComposite.h"
#include "table.h"
#include "visitor.h"
#include <memory>

class findSpaceVisitor: public visitor
{
    public:
        findSpaceVisitor():visitor(){};
        int visitTable(std::shared_ptr<table>);
        int visitTile(std::shared_ptr<floorComposite>);
        ~findSpaceVisitor(){};
};

#endif