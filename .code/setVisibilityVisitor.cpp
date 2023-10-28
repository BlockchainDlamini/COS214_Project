#include "setVisibilityVisitor.h"

setVisibilityVisitor::setVisibilityVisitor(int newVis):visitor()
{
    newVisibility = newVis;
}

int setVisibilityVisitor::visitTable(std::shared_ptr<table> tble)
{
    if(newVisibility==1)
        tble->setIsVisible(true);
    else
        tble->setIsVisible(false);
    return 1;
}
int setVisibilityVisitor::visitTile(std::shared_ptr<floorComposite>)
{
    return 0;
}