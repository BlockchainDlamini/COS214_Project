#include "floor.h"
#include "depthFirstIterator.h"
#include "breadthFirstIterator.h"

myFloor::myFloor(int num)
{
    number = num;
}

void myFloor::add(std::shared_ptr<floorComponent> newUnit)
{
    next.push_back(newUnit);
}

void myFloor::remove(std::shared_ptr<floorComponent> unit)
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

std::shared_ptr<floorComponent> myFloor::getChild(int i)
{
    return next[i];
}

int myFloor::getIndexOfChild(std::shared_ptr<floorComponent> child)
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
std::shared_ptr<myIterator> myFloor::getDepthIterator()
{
    currentChild = 0;
    return  std::make_shared<myIterator>(depthFirstIterator(std::make_shared<floorComponent>(this)));
}

std::shared_ptr<myIterator> myFloor::getBreadthIterator()
{
    currentChild = 0;
    return  std::make_shared<myIterator>(breadthFirstIterator(std::make_shared<floorComponent>(this)));
}

int myFloor::getNumChildren()
{
    return next.size();
}

void myFloor::setCurrentChild(int indx)
{
    currentChild = indx;
}

int myFloor::getCurretnChild()
{
    return currentChild;
}

std::string myFloor::toString()
{
    return "This is a floor piece number: " + number;
}

/*void acceptVisitor(std::shared_ptr<maitreD> visitor)
{

}*/

myFloor::~myFloor()
{
}