#include "floor.h"
#include "findSpaceVisitor.h"
#include "setSpcaeVisitor.h"
#include "setVisibilityVisitor.h"
#include "setMergeVisitor.h"
#include "getMergeVisitor.h"
#include "getVisibilityVisitor.h"
#include "depthFirstIterator.h"
#include "breadthFirstIterator.h"
#include "floorComposite.h"
#include "table.h"

myFloor::myFloor(int size)
{
    sideLenght = size;
    tableSpace = 4;
    theFloor = std::make_shared<floorComposite>(floorComposite(0));

    for (int i = 0; i < 4; i++)
    {
        for (int x = 0; x < size; i++)
        {
            std::shared_ptr<floorComponent> tile = std::make_shared<floorComposite>(floorComposite(1+i));
            std::shared_ptr<floorComponent> tb = std::make_shared<table>(table(1+i, tableSpace));
            tile->add(tb);
            theFloor->add(tile);
        }
    }
}

bool myFloor::hasSpace(int amount) 
{
    std::shared_ptr<myIterator> it = theFloor->getDepthIterator();
    std::shared_ptr<visitor> visit = std::make_shared<findSpaceVisitor>();

    while(it->hasNext())
    {
        if(it->currentItem()->acceptVisitor(visit)>=amount)
            return true;
        it->next();
    }
    return false;
}

/*bool myFloor::seatCustomer(std::vector<std::shared_ptr<customer>> customers)
{
    if(!hasSpace(customers.size()))
    {
        if(!merdgeTile(customers.size()))
            return false;
    }
    std::shared_ptr<myIterator> curr = myFloor->getDepthIterator();

    while(curr->hasNext())
    {
        temp = curr->currentItem()->acceptVisitor(std::make_shared<visitor>());
        if(temp==customer.size())
        {
            (std::shared_ptr<table>) curr->seatCustomers(customers);
        }
        curr->next();
    }
    return true;
}*/


bool myFloor::merdgeTile(int amount)
{
    std::shared_ptr<myIterator> curr = theFloor->getDepthIterator();
    std::vector<std::shared_ptr<floorComponent>> tables;
    int temp;

    //Finding the tables to merdge
    while(curr->hasNext() && amount>0)
    {
        temp = curr->currentItem()->acceptVisitor(std::make_shared<findSpaceVisitor>());
        if(temp>0)
        {
            tables.push_back(curr->currentItem());
            amount-=temp;
        }
        curr->next();
    }

    if(amount>0)
        return false;

    int newSpace = 0;    
    for (int i = 0; i < tables.size(); i++)
        newSpace += tables.at(i)->acceptVisitor(std::make_shared<findSpaceVisitor>());
    
    tables.at(0)->acceptVisitor(std::make_shared<setSpaceVisitor>(setSpaceVisitor(newSpace)));
    tables.at(0)->acceptVisitor(std::make_shared<setMergeVisitor>(setMergeVisitor(1)));
    for (int i = 1; i < tables.size(); i++)
    {
        tables.at(i)->acceptVisitor(std::make_shared<setSpaceVisitor>(setSpaceVisitor(0)));
    }
    return true;
}

void myFloor::unmerdgeTiles()
{
    std::shared_ptr<myIterator> curr = theFloor->getDepthIterator();
    std::vector<std::shared_ptr<floorComponent>> mergedTables;
    std::vector<std::shared_ptr<floorComponent>> hidenTables;
    int temp;
    
    //Finding the tables to merdge
    while(curr->hasNext())
    {
        if(curr->currentItem()->acceptVisitor(std::make_shared<getMergeVisitor>())==1)
            mergedTables.push_back(curr->currentItem());
        else if(curr->currentItem()->acceptVisitor(std::make_shared<getVisibilityVisitor>())==0)
            hidenTables.push_back(curr->currentItem());
        
        curr->next();
    }

    for (int i = 0; i < mergedTables.size(); i++)
    {
        int newSize = mergedTables.at(i)->acceptVisitor(std::make_shared<findSpaceVisitor>()); 
        for (int x = 0; x < hidenTables.size() && newSize>=4; x++)
        {
            newSize -= hidenTables.at(i)->acceptVisitor(std::make_shared<findSpaceVisitor>());
            hidenTables.at(i)->acceptVisitor(std::make_shared<setVisibilityVisitor>(setVisibilityVisitor(1)));
        }
        mergedTables.at(0)->acceptVisitor(std::make_shared<setMergeVisitor>(setMergeVisitor(0)));        
    }
}

std::shared_ptr<floorComponent> myFloor::getTableAt(int id)
{
    std::shared_ptr<myIterator> curr = theFloor->getDepthIterator();

    while(curr->hasNext())
    {
        if(curr->currentItem()->getID()==id)
            return curr->currentItem();
        curr->next();
    }
    return nullptr;
}

void myFloor::printBreadth()
{
    std::shared_ptr<myIterator> it = theFloor->getBreadthIterator();
    while(it->hasNext())
    {
        std::cout<<it->currentItem()<<std::endl;
        it->next();
    }
}

void myFloor::printDepth()
{
    std::shared_ptr<myIterator> it = theFloor->getDepthIterator();
    while(it->hasNext())
    {
        std::cout<<it->currentItem()<<std::endl;
        it->next();
    }
}

myFloor::~myFloor()
{
}
