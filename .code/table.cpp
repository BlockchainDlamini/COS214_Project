#include "table.h"

table::table(int num, int spce)
{
    space=spce;
    tableNumber = num;
}

void table::add(std::shared_ptr<floorComponent>) //Comply with interface
{}

void table::remove(std::shared_ptr<floorComponent>)//Comply with interface
{}

void table::newCustomers(std::vector<std::shared_ptr<floorComponent>> newCustomers)
{
    customers = newCustomers;
}

void table::removeCustomers()
{
    customers.clear();
}

int table::spaceAvailable()
{
    if(customers.empty())
        return space;

    return 0;
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
    currentChild = -1;
    return nullptr;
}

std::shared_ptr<myIterator> table::getBreadthIterator()
{
    currentChild = -1;
    return nullptr;
}

int table::acceptVisitor(std::shared_ptr<visitor> visitor)
{
    if(isSpaceAvailable)
        return visitor->visitTable(std::make_shared<table>(this));
    return 0;
}

std::string table::toString()
{
    return "This is table number: " + tableNumber;
}

table::~table()
{
}