#include "floorComposite.h"
#include "depthFirstIterator.h"
#include "breadthFirstIterator.h"
#include <iostream>


floorComposite::floorComposite(int newId):floorComponent(newId)
{
    //std::cout<<"In floorComposite constructor"<<std::endl;
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
    std::shared_ptr<myIterator> temp = std::dynamic_pointer_cast<myIterator>(std::make_shared<depthFirstIterator>(depthFirstIterator(shared_from_this())));
    return temp; //Needs to pass floorComponent object in breathFirstIterator
}

std::shared_ptr<myIterator> floorComposite::getBreadthIterator()
{
    std::shared_ptr<myIterator> temp = std::dynamic_pointer_cast<myIterator>(std::make_shared<breadthFirstIterator>(breadthFirstIterator(shared_from_this())));
    return temp; //Needs to pass floorComponent object in breathFirstIterator
}

int floorComposite::getNumChildren()
{
    return next.size();
}

std::string floorComposite::toString()
{
    return "This is a tile. ID: " + std::to_string(id);
}

int floorComposite::acceptVisitor(std::shared_ptr<visitor> visitor)
{
    std::shared_ptr<floorComposite> temp = std::dynamic_pointer_cast<floorComposite>(shared_from_this());
    return visitor->visitTile(temp);//Needs to pass floorComposite object in visitTile
}

floorComposite::~floorComposite()
{
}