#include "depthFirstIterator.h"
#include <iostream>

depthFirstIterator::depthFirstIterator(std::shared_ptr<floorComponent> head) : myIterator(head) //Works correctly 
{
    treeFlatten(head);
}

void depthFirstIterator::treeFlatten(std::shared_ptr<floorComponent> currNode) //Works correctly
{
    flattenedTree.push(currNode);
    for (int i = 0; i < currNode->getNumChildren(); i++)
        treeFlatten(currNode->getChild(i));
}

depthFirstIterator::~depthFirstIterator()
{}
