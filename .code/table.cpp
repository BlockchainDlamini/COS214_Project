#include "table.h"
#include "visitor.h"

table::table(int id, int spce):floorComponent(id)
{
    space=spce;
    isVisible = true;
    isMerged = false;
}

void table::add(std::shared_ptr<floorComponent>) //Comply with interface
{}

void table::remove(std::shared_ptr<floorComponent>)//Comply with interface
{}

void table::newCustomers(std::vector<std::shared_ptr<floorComponent>> newCustomers)
{
    customers = newCustomers;
    isVisible=false;
}

void table::removeCustomers()
{
    customers.clear();
    isVisible = true;
}

bool table::getIsVisible()
{
    return isVisible;
}

void table::setIsVisible(bool vis)
{
    isVisible = vis;
}

int table::spaceAvailable()
{
    if(customers.empty())
        return space;

    return 0;
}

bool table::getIsMerged()
{
    return isMerged;
}

void table::setIsMerged(bool merge)
{
    isMerged = merge;
}

void table::setSpace(int spce)
{
    space = spce;
}

std::shared_ptr<floorComponent> table::getChild(int)
{
    return nullptr;
}

int table::getNumChildren()
{
    return 0;
}

std::shared_ptr<myIterator> table::getDepthIterator()
{
    return nullptr;
}

std::shared_ptr<myIterator> table::getBreadthIterator()
{
    return nullptr;
}

int table::acceptVisitor(std::shared_ptr<visitor> visitor)
{
    if(isSpaceAvailable)
    {
        std::shared_ptr<table> temp = std::dynamic_pointer_cast<table>(shared_from_this());
        return visitor->visitTable(temp);
    }
    return 0;
}

std::string table::toString()
{
    if(isVisible)
        return "This is table number: " + id;
    else
        return "";
}

table::~table()
{
}