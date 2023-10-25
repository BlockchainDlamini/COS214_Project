#include "floor.h"

floor::floor()
{
}

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

floor::~floor()
{
}