#include "getMergeVisitor.h"
#include "table.h"

int getMergeVisitor::visitTable(std::shared_ptr<table> tble)
{
    return tble->getIsMerged();
}
int getMergeVisitor::visitTile(std::shared_ptr<floorComposite>)
{
    return -1;
}