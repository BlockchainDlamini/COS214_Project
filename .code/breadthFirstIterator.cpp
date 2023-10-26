#include "breadthFirstIterator.h"

breadthFirstIterator::breadthFirstIterator(std::shared_ptr<floorComponent> head) : myIterator(head)
{}

std::shared_ptr<floorComponent> breadthFirstIterator::first()
{
    return head;
}

void breadthFirstIterator::next()
{
    
}

std::shared_ptr<floorComponent> breadthFirstIterator::currentItem()
{
    return current;
}

bool breadthFirstIterator::hasNext()
{
    
}

breadthFirstIterator::~breadthFirstIterator()
{}
