#include "table.h"

table::table(int num)
{
    space=0;
    number = num;
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

int table::getIndexOfChild(std::shared_ptr<floorComponent>)
{
    return -1;
}

void table::setCurrentChild(int)
{
    currentChild = -1;
}

int getCurretnChild()
{
    return -1;
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

/*void table::acceptVisitor(std::shared_ptr<maitreD> visitor)
{

}*/

std::string table::toString()
{
    return "This is table number: " + number;
}

table::~table()
{
}