#include "depthFirstIterator.h"

depthFirstIterator::depthFirstIterator(std::shared_ptr<floorComponent> head) : myIterator(head)
{}

std::shared_ptr<floorComponent> depthFirstIterator::first()
{
    return head;
}

void depthFirstIterator::next()
{
    if(current->getNumChildren()==0) //in leaf -> need to go back up again
    {
        current = previous;
       previous = findPrevious(previous, head);        
    }
    else //need to move down 
    {
        std::shared_ptr<floorComponent> temp = current->getChild(current->getCurretnChild());
        current->setCurrentChild(current->getCurretnChild()+1); //increating the index of the child I need to move to
        previous = current;
        current = temp;
    }
}

std::shared_ptr<floorComponent> depthFirstIterator::findPrevious(std::shared_ptr<floorComponent> curr, std::shared_ptr<floorComponent> hd)
{
    for (int i = 0; i < hd->getNumChildren(); i++)
    {
        if(curr==hd->getChild(i))
            return hd;
        else
            return findPrevious(curr,hd->getChild(i));
    }
    
}

std::shared_ptr<floorComponent> depthFirstIterator::currentItem()
{
    return current;
}

bool depthFirstIterator::hasNext()
{

}

depthFirstIterator::~depthFirstIterator()
{}
