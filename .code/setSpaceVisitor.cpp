#include "setSpcaeVisitor.h"


setSpaceVisitor::setSpaceVisitor(int newSpace):visitor()
{
    space = newSpace;
}

int setSpaceVisitor::visitTable(std::shared_ptr<table> tble)
{
    tble->setSpace(space);
    return 1;
}
int setSpaceVisitor::visitTile(std::shared_ptr<floorComposite>)
{
    return 0;
}