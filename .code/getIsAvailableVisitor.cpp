#include "getIsAvailableVisitor.h"
#include "table.h"

int getIsAvailableVisitor::visitTable(std::shared_ptr<table> tble)
{
    if(tble->getIsSpaceAvailable())
        return 1;
    return 0;
}
int getIsAvailableVisitor::visitTile(std::shared_ptr<floorComposite>)
{
    return -1;
}