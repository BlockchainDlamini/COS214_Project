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
#include <iostream>

Floor::Floor(int size, int seatingSpace) //Works correctly
{
    sideLenght = size;
    tableSpace = 4;
    theFloor = std::make_shared<floorComposite>(floorComposite(0));

    for (int i = 0; i < size; i++)
    {
        std::shared_ptr<floorComponent> tile = std::make_shared<floorComposite>(floorComposite(1+i*size));
        std::shared_ptr<floorComponent> tb = std::make_shared<table>(table(1+i*size, size));
        tile->add(tb);
        std::shared_ptr<floorComponent> prev = nullptr;
        for (int x = 0; x < size-1; x++)
        {
            std::shared_ptr<floorComponent> subTile = std::make_shared<floorComposite>(floorComposite(2+i*size+x));
            std::shared_ptr<floorComponent> subTb = std::make_shared<table>(table(2+i*size+x, seatingSpace));
            if(x==0)
                prev = tile;
            subTile->add(subTb);
            prev->add(subTile);
            prev = subTile;  
        }
        theFloor->add(tile);
    }
}

bool Floor::hasSpace(int amount)  //Works correctly
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

/*bool Floor::seatCustomer(std::vector<std::shared_ptr<customer>> customers)  //not tested yet
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


bool Floor::merdgeTile(int amount) //Works correctly without customers being seated
{
    //std::cout<<"In merdge function "<<std::endl;
    std::shared_ptr<myIterator> curr = theFloor->getDepthIterator();
    std::vector<std::shared_ptr<floorComponent>> tables;
    int temp;

    //Finding the tables to merdge
    while(curr->hasNext() && amount>0)
    {
        //std::cout<<curr->currentItem()->toString()<<std::endl;
        temp = curr->currentItem()->acceptVisitor(std::make_shared<findSpaceVisitor>());
        if(temp>0)
        {
            //std::cout<<"Added to list"<<std::endl;
            tables.push_back(curr->currentItem());
            amount-=temp;
        }
        curr->next();
    }
    //std::cout<<"Amount: "<<amount<<std::endl;
    if(amount>0)
        return false;

    int newSpace = 0;    
    for (int i = 0; i < tables.size(); i++)
        newSpace += tables.at(i)->acceptVisitor(std::make_shared<findSpaceVisitor>());
    
    //std::cout<<"newSpace: "<<newSpace<<std::endl;
    
    tables.at(0)->acceptVisitor(std::make_shared<setSpaceVisitor>(setSpaceVisitor(newSpace)));
    tables.at(0)->acceptVisitor(std::make_shared<setMergeVisitor>(setMergeVisitor(1)));
    for (int i = 1; i < tables.size(); i++)
    {
        tables.at(i)->acceptVisitor(std::make_shared<setVisibilityVisitor>(setVisibilityVisitor(0)));
    }

    /*for (int i = 0; i < tables.size(); i++)
    {
       std::cout<<tables.at(i)->toString()<<std::endl;
    }*/
    
    return true;
}

void Floor::unmerdgeTiles() //works without customers 
{
    std::shared_ptr<myIterator> curr = theFloor->getDepthIterator();
    std::vector<std::shared_ptr<floorComponent>> mergedTables;
    std::vector<std::shared_ptr<floorComponent>> hidenTables;
    int temp;
    
    //Finding the tables to merdge
    while(curr->hasNext())
    {
        if(curr->currentItem()->acceptVisitor(std::make_shared<getMergeVisitor>())==1)
        {
            //std::cout<<curr->currentItem()->toString()<<", is added to merged tables list"<<std::endl;
            mergedTables.push_back(curr->currentItem());
        }
        else if(curr->currentItem()->acceptVisitor(std::make_shared<getVisibilityVisitor>())==0)
        {   
            //std::cout<<curr->currentItem()->toString()<<", is added to hiden tables list"<<std::endl;
            hidenTables.push_back(curr->currentItem());
        }
        curr->next();
    }

    for (int i = 0; i < mergedTables.size(); i++)
    {
        int newSize = mergedTables.at(i)->acceptVisitor(std::make_shared<findSpaceVisitor>()); 
        for (int x = 0; x < hidenTables.size(); x++)
        {
            hidenTables.at(x)->acceptVisitor(std::make_shared<setVisibilityVisitor>(setVisibilityVisitor(1)));
            newSize = newSize - hidenTables.at(x)->acceptVisitor(std::make_shared<findSpaceVisitor>());
        }
        mergedTables.at(i)->acceptVisitor(std::make_shared<setMergeVisitor>(setMergeVisitor(0)));   
        mergedTables.at(i)->acceptVisitor(std::make_shared<setSpaceVisitor>(setSpaceVisitor(newSize)));     
    }
}

std::shared_ptr<floorComponent> Floor::getTableAt(int id) //Works correctly
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

void Floor::printBreadth() //Not needed
{
    std::shared_ptr<myIterator> it = theFloor->getBreadthIterator();
    while(it->hasNext())
    {
        std::cout<<it->currentItem()->toString()<<std::endl;
        it->next();
    }
}

void Floor::printDepth() //Works correctly
{
    std::shared_ptr<myIterator> it = theFloor->getDepthIterator();
    while(it->hasNext())
    {
        if(it->currentItem()->toString()!="")
            std::cout<<it->currentItem()->toString()<<std::endl;
        it->next();
    }
}

Floor::~Floor()
{}
