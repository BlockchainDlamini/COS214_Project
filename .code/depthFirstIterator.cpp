#include "depthFirstIterator.h"

depthFirstIterator::depthFirstIterator(std::shared_ptr<floorComponent> head) : myIterator(head)
{
    flattenTree(head);
}

void depthFirstIterator::flattenTree(std::shared_ptr<floorComponent> currNode)
{
    flattenedTree.push(currNode);
    for (int i = 0; i < currNode->getNumChildren(); i++)
    {
        flattenTree(currNode->getChild(i));
        flattenedTree.push(currNode->getChild(i));
    }
    
}

depthFirstIterator::~depthFirstIterator()
{}
