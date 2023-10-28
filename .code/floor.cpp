#include "floor.h"
#include "findSpaceVisitor.h"
#include "setSpcaeVisitor.h"
#include "setVisibilityVisitor.h"
#include "setMergeVisitor.h"
#include "getMergeVisitor.h"
#include "getVisibilityVisitor.h"

floor::floor(int size)
{
    sideLenght = size;
    tableSpace = 4;
    myFloor = std::make_shared<floorComponent>(floorComposite(0));

    for (int i = 0; i < 4; i++)
    {
        for (int x = 0; x < size; i++)
        {
            std::shared_ptr<floorComponent> tile = std::make_shared<floorComponent>(floorComposite(1+i));
            std::shared_ptr<floorComponent> tb = std::make_shared<floorComponent>(table(1+i, tableSpace));
            tile->add(tb);
            myFloor->add(tile);
        }
    }
}

bool floor::hasSpace(int amount) 
{
    std::shared_ptr<myIterator> it = myFloor->getDepthIterator();
    std::shared_ptr<visitor> visit = std::make_shared<visitor>(new findSpaceVisitor());

    while(it->hasNext())
    {
        if(it->currentItem()->acceptVisitor(visit)>=amount)
            return true;
        it->next();
    }
    return false;
}

/*bool floor::seatCustomer(std::vector<std::shared_ptr<customer>> customers)
{
    if(hasSpace(customers.size()))
    {

    }
    else
        return false;
}*/


void floor::merdgeTile(int amount)
{
    std::shared_ptr<myIterator> curr = myFloor->getDepthIterator();
    std::vector<std::shared_ptr<floorComponent>> tables;
    int temp;

    //Finding the tables to merdge
    while(curr->hasNext() && amount>0)
    {
        temp = curr->currentItem()->acceptVisitor(std::make_shared<visitor>(new findSpaceVisitor()));
        if(temp>0)
        {
            tables.push_back(curr->currentItem());
            amount-=temp;
        }
        curr->next();
    }

    int newSpace = 0;    
    for (int i = 0; i < tables.size(); i++)
        newSpace += tables.at(i)->acceptVisitor(std::make_shared<visitor>(new findSpaceVisitor()));
    
    tables.at(0)->acceptVisitor(std::make_shared<visitor>(new setSpaceVisitor(newSpace)));
    tables.at(0)->acceptVisitor(std::make_shared<visitor>(new setMergeVisitor(1)));
    for (int i = 1; i < tables.size(); i++)
    {
        tables.at(i)->acceptVisitor(std::make_shared<visitor>(new setSpaceVisitor(0)));
    }
}

void floor::unmerdgeTiles()
{
    std::shared_ptr<myIterator> curr = myFloor->getDepthIterator();
    std::vector<std::shared_ptr<floorComponent>> mergedTables;
    std::vector<std::shared_ptr<floorComponent>> hidenTables;
    int temp;
    
    //Finding the tables to merdge
    while(curr->hasNext())
    {
        if(curr->currentItem()->acceptVisitor(std::make_shared<visitor>(new getMergeVisitor()))==1)
            mergedTables.push_back(curr->currentItem());
        else if(curr->currentItem()->acceptVisitor(std::make_shared<visitor>(new getVisibilityVisitor()))==0)
            hidenTables.push_back(curr->currentItem());
        
        curr->next();
    }

    for (int i = 0; i < mergedTables.size(); i++)
    {
        int newSize = mergedTables.at(i)->acceptVisitor(std::make_shared<visitor>(new findSpaceVisitor())); 
        for (int x = 0; x < hidenTables.size() && newSize>=4; x++)
        {
            newSize -= hidenTables.at(i)->acceptVisitor(std::make_shared<visitor>(new findSpaceVisitor()));
            hidenTables.at(i)->acceptVisitor(std::make_shared<visitor>(new setVisibilityVisitor(1)));
        }
        mergedTables.at(0)->acceptVisitor(std::make_shared<visitor>(new setMergeVisitor(0)));        
    }
}

std::shared_ptr<table> floor::getTableAt(int id)
{

}

void floor::printBreadth()
{
    std::shared_ptr<myIterator> it = myFloor->getBreadthIterator();
    while(it->hasNext())
    {
        std::cout<<it->currentItem()<<std::endl;
        it->next();
    }
}

void floor::printDepth()
{
    std::shared_ptr<myIterator> it = myFloor->getDepthIterator();
    while(it->hasNext())
    {
        std::cout<<it->currentItem()<<std::endl;
        it->next();
    }
}

floor::~floor()
{
}
