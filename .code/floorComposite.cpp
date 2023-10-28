#include "floorComposite.h"
#include "depthFirstIterator.h"
#include "breadthFirstIterator.h"

floorComposite::floorComposite(int num)
{
    number = num;
}

void floorComposite::add(std::shared_ptr<floorComponent> newUnit)
{
    next.push_back(newUnit);
}

void floorComposite::remove(std::shared_ptr<floorComponent> unit)
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

std::shared_ptr<floorComponent> floorComposite::getChild(int i)
{
    return next[i];
}

std::shared_ptr<myIterator> floorComposite::getDepthIterator()
{
    currentChild = 0;
    return  std::make_shared<myIterator>(depthFirstIterator(std::make_shared<floorComponent>(this)));
}

std::shared_ptr<myIterator> floorComposite::getBreadthIterator()
{
    currentChild = 0;
    return  std::make_shared<myIterator>(breadthFirstIterator(std::make_shared<floorComponent>(this)));
}

int floorComposite::getNumChildren()
{
    return next.size();
}

std::string floorComposite::toString()
{
    return "This is a floor piece number: " + number;
}

int floorComposite::acceptVisitor(std::shared_ptr<visitor> visitor)
{
    return visitor->visitTile(std::make_shared<floorComposite>(this));
}

floorComposite::~floorComposite()
{
}