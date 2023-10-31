#include "setAvailableVisitor.h"
#include "table.h"

int setIsAvailableVisitor::visitTable(std::shared_ptr<table> tble)
{
    if(newVis==1)
        tble->setIsSpaceAvailable(true);
    else
        tble->setIsSpaceAvailable(false);
    return 1;
}
int setIsAvailableVisitor::visitTile(std::shared_ptr<floorComposite>)
{
    return -1;
}