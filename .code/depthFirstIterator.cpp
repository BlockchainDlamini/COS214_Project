#include "depthFirstIterator.h"

depthFirstIterator::depthFirstIterator(std::shared_ptr<floorComponent> head) : iterator(head)
{}

std::shared_ptr<floorComponent> depthFirstIterator::first()
{
    return head;
}

std::shared_ptr<floorComponent> depthFirstIterator::next()
{
    
}

std::shared_ptr<floorComponent> depthFirstIterator::currentItem()
{
    return current;
}

bool depthFirstIterator::isDone()
{

}

depthFirstIterator::~depthFirstIterator()
{}
