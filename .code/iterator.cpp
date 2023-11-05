#include "iterator.h"
#include <iostream>

myIterator::myIterator(std::shared_ptr<floorComponent> newHead) //Works correctly
{
    head = newHead;
    current = newHead;
}

std::shared_ptr<floorComponent> myIterator::first() //Works correctly
{
    return head;
}

void myIterator::next()//Works correctly
{
    if (!flattenedTree.empty())
    {
        flattenedTree.pop();
        if(!flattenedTree.empty())
            current = flattenedTree.front();
    }

}
//void myIterator::next()//Works correctly
//{
//    flattenedTree.pop();
//    current = flattenedTree.front();
//}

std::shared_ptr<floorComponent> myIterator::currentItem() //Works correctly
{
    return current;
}

bool myIterator::hasNext() //Works correctly
{    
    if(!flattenedTree.empty())
        return true;

    return false;
}

myIterator::~myIterator()
{}