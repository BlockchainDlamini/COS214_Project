#include "breadthFirstIterator.h"

breadthFirstIterator::breadthFirstIterator(std::shared_ptr<floorComponent> head) : iterator(head)
{}

std::shared_ptr<floorComponent> breadthFirstIterator::first()
{
    return head;
}

std::shared_ptr<floorComponent> breadthFirstIterator::next()
{
    
}

std::shared_ptr<floorComponent> breadthFirstIterator::currentItem()
{
    return current;
}

bool isDone()
{
    
}

breadthFirstIterator::~breadthFirstIterator()
{}
