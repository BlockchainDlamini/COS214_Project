#include "iterator.h"

myIterator::myIterator(std::shared_ptr<floorComponent> newHead)
{
    head = newHead;
    current = newHead->getChild(0); //immediately points to first row
    previous = newHead;
}