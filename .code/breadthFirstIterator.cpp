#include "breadthFirstIterator.h"
#include <iostream>

breadthFirstIterator::breadthFirstIterator(std::shared_ptr<floorComponent> head) : myIterator(head)
{
    treeFlatten(head);
}

void breadthFirstIterator::treeFlatten(std::shared_ptr<floorComponent> currNode)
{
    int numLevels = height(head);
    for (int i = 0; i < numLevels; i++)
    {
        pushCurrentLevel(head, i);
    }
}

void breadthFirstIterator::pushCurrentLevel(std::shared_ptr<floorComponent> hd, int level)
{
    if(level==0)
        flattenedTree.push(hd);
    else
    {
        for (int i = 0; i < hd->getNumChildren(); i++)
        {
            pushCurrentLevel(hd->getChild(i), level-1);
        }
    }
}

int breadthFirstIterator::height(std::shared_ptr<floorComponent> curr) //Test complete
{
    if (curr->getNumChildren()==0)
    {
        return -1;
    }
    else {
        int max = -1;
        for (int i = 0; i <curr->getNumChildren(); i++)
        {
            int childHeight = height(curr->getChild(i));
            if(childHeight>max)
                max = childHeight;            
        }
        return max+1;
    }
}

breadthFirstIterator::~breadthFirstIterator()
{}
