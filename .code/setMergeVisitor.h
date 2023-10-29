#ifndef SETMERGEVISITOR_H
#define SETMERGEVISITOR_H

#include "floorComponent.h"
#include "floorComposite.h"
#include "table.h"
#include "visitor.h"
#include <memory>

class setMergeVisitor: public visitor
{
    private:
        int merge;
    public:
        setMergeVisitor(int newSpace);
        int visitTable(std::shared_ptr<table>);
        int visitTile(std::shared_ptr<floorComposite>);
        ~setMergeVisitor(){};
};

#endif