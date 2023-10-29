#include "breadthFirstIterator.h"

breadthFirstIterator::breadthFirstIterator(std::shared_ptr<floorComponent> head) : myIterator(head)
{
    flattenTree(head);
}

void breadthFirstIterator::flattenTree(std::shared_ptr<floorComponent> currNode)
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

int breadthFirstIterator::height(std::shared_ptr<floorComponent> curr)
{
    if (curr == nullptr)
        return -1;
    else {
        // Compute the height of each subtree
        int max = -1;
        for (int i = 0; i <curr->getNumChildren(); i++)
        {
            int childHeight = height(curr->getChild(i));
            if(childHeight>max)
                max=childHeight;            
        }
        return max + 1;
    }
}

breadthFirstIterator::~breadthFirstIterator()
{}
