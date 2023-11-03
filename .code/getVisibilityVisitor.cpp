#include "getVisibilityVisitor.h"


int getVisibilityVisitor::visitTable(std::shared_ptr<table> tble)
{
    return tble->getIsVisible();
}
int getVisibilityVisitor::visitTile(std::shared_ptr<floorComposite>)
{
    return -1;
}