#include "floor.h"

floor::floor()
{}

void floor::add(std::shared_ptr<floorComponent> newUnit)
{
    next.push_back(newUnit);
}

void floor::remove(std::shared_ptr<floorComponent> unit)
{
    std::vector<std::shared_ptr<floorComponent>>::iterator it = next.begin();
    bool found = false;

    while(it!=next.end() && !found)
    {
        if(*it == unit)
        {
            found = true;
            next.erase(it);
        }
        ++it;
    } 
}

std::shared_ptr<floorComponent> floor::getChild(int i)
{
    return next[i];
}

int floor::getIndexOfChild(std::shared_ptr<floorComponent> child)
{
    std::vector<std::shared_ptr<floorComponent>>::iterator it = next.begin();
    int count = 0;

    while(it!=next.end())
    {
        if(*it == child)
        {
            return count;
        }
        ++it;
        ++count;
    } 

    return -1;
}
std::shared_ptr<myIterator> floor::getDepthIterator()
{
    currentChild = 0;
    return  std::make_shared<myIterator>(depthFirstIterator(std::make_shared<floorComponent>(this)));
}

std::shared_ptr<myIterator> floor::getBreadthIterator()
{
    currentChild = 0;
    return  std::make_shared<myIterator>(breadthFirstIterator(std::make_shared<floorComponent>(this)));
}

int floor::getNumChildren()
{
    return next.size();
}

void floor::setCurrentChild(int indx)
{
    currentChild = indx;
}

int floor::getCurretnChild()
{
    return currentChild;
}

floor::~floor()
{
}