#include "setMergeVisitor.h"
#include "table.h"

setMergeVisitor::setMergeVisitor(int newMerge):visitor()
{
    merge = newMerge;
}

int setMergeVisitor::visitTable(std::shared_ptr<table> tble)
{
    if(merge==1)
        tble->setIsMerged(true);
    else
        tble->setIsMerged(false);
    return 1;
}
int setMergeVisitor::visitTile(std::shared_ptr<floorComposite>)
{
    return 0;
}