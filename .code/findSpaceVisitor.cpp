#include "findSpaceVisitor.h"


int findSpaceVisitor::visitTable(std::shared_ptr<table> tble)
{
    if(tble->getIsVisible())
        return tble->spaceAvailable();
    return 0;
}
int findSpaceVisitor::visitTile(std::shared_ptr<floorComposite>)
{
    return 0;
}