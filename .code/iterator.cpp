#include "iterator.h"

myIterator::myIterator(std::shared_ptr<floorComponent> newHead)
{
    head = newHead;
    current = newHead;
    previous = newHead;
}