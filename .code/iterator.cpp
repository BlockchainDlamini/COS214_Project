#include "iterator.h"

myIterator::myIterator(std::shared_ptr<floorComponent> newHead)
{
    head = newHead;
    current = newHead;
}

std::shared_ptr<floorComponent> myIterator::first()
{
    return head;
}

void myIterator::next()
{
    return flattenedTree.pop();
    /*bool found = false;

    while(!flattenedTree.empty())
    {
        std::shared_ptr<floorComponent> front = flattenedTree.front();
        flattenedTree.pop();
        if(front == current)
        {
            found = true;
            current = flattenedTree.front();
        }
    }
    if(!found)
        current = nullptr;*/
}

std::shared_ptr<floorComponent> myIterator::currentItem()
{
    return current;
}

bool myIterator::hasNext()
{
    if(flattenedTree.front()!=nullptr)
        return true;
    
    return false;
    /*bool found = false;

    while(!flattenedTree.empty())
    {
        std::shared_ptr<floorComponent> front = flattenedTree.front();
        flattenedTree.pop();
        if(front == current)
            return true;
    }
    return false;*/
}

myIterator::~myIterator()
{}