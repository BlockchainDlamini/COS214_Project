#include "floorUnit.h"
#include <iterator>

floorUnit::floorUnit()
{
}

void floorUnit::add(std::shared_ptr<floor> newUnit)
{
    next.push_back(newUnit);
}

void floorUnit::remove(std::shared_ptr<floor> unit)
{
    
}

floorUnit::~floorUnit()
{

}