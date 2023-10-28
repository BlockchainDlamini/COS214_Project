#ifndef GETMERGEVISITOR_H
#define GETMERGEVISITOR_H

#include "floorComponent.h"
#include "floorComposite.h"
#include "table.h"
#include <memory>

class getMergeVisitor: public visitor
{
    public:
        getMergeVisitor():visitor(){};
        int visitTable(std::shared_ptr<table>);
        int visitTile(std::shared_ptr<floorComposite>);
        ~getMergeVisitor(){};
};

#endif