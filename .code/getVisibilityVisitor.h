#ifndef GETVISIBILITYVISITOR_h
#define GETVISIBILITYVISITOR_h

#include "floorComponent.h"
#include "floorComposite.h"
#include "table.h"
#include "visitor.h"
#include <memory>

class getVisibilityVisitor: public visitor
{
    public:
        getVisibilityVisitor():visitor(){};
        int visitTable(std::shared_ptr<table>);
        int visitTile(std::shared_ptr<floorComposite>);
        ~getVisibilityVisitor(){};
};

#endif