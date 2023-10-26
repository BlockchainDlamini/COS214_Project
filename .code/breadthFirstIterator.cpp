#include "breadthFirstIterator.h"

breadthFirstIterator::breadthFirstIterator(std::shared_ptr<floorComponent> head) : myIterator(head)
{
    flattenTree(head);
}

void breadthFirstIterator::flattenTree(std::shared_ptr<floorComponent> currNode)
{
    for (int i = 0; i < currNode->getNumChildren(); i++)
    {
        flattenedTree.push(currNode->getChild(i));
    }
    for (int i = 0; i < currNode->getNumChildren(); i++)
    {
        flattenTree(currNode->getChild(i));
    }
    
}

breadthFirstIterator::~breadthFirstIterator()
{}
