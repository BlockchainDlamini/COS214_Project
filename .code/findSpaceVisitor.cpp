#include "findSpaceVisitor.h"

int visitTable(std::shared_ptr<table> tble)
{
    return tble->spaceAvailable();
}
int visitTile(std::shared_ptr<floorComposite>)
{
    return 0;
}