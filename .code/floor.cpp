#include "floor.h"
#include "findSpaceVisitor.h"
#include <iostream>
#include <thread>

Floor::Floor(int size, int seatingSpace) //Works correctly
{
    sideLenght = size;
    tableSpace = seatingSpace;
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
            std::shared_ptr<floorComponent> subTb = std::make_shared<table>(table(2+i*size+x, tableSpace));
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

bool Floor::seatCustomer(std::vector<std::shared_ptr<Customer>> customers)  //not tested yet
{
    //std::cout<<"In seating function"<<std::endl;
    if(!hasSpace(customers.size()))
    {
        std::cout<<"There is not enought space yet, needs to merge"<<std::endl;
        if(!merdgeTile(customers.size()))
        {
            return false;
        }            
    }

    cout << std::endl;
    std::cout << "Please wait while we find a table for the customers";
    std::this_thread::sleep_for(std::chrono::milliseconds(700));
    std::cout << ".";
    std::this_thread::sleep_for(std::chrono::milliseconds(700));
    std::cout << ".";
    std::this_thread::sleep_for(std::chrono::milliseconds(700));
    std::cout << ".";
    std::this_thread::sleep_for(std::chrono::milliseconds(700));
    std::cout << ".";
    
    cout << std::endl;
    cout << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::shared_ptr<myIterator> curr = theFloor->getDepthIterator();
    int id=-1;

    while(curr->hasNext())
    {
        int temp = curr->currentItem()->acceptVisitor(std::make_shared<findSpaceVisitor>());
        if(temp>=customers.size())
        {
            //std::cout<<"Customer is being seated at: "<<curr->currentItem()->toString()<<std::endl;
            std::shared_ptr<table> tb = std::dynamic_pointer_cast<table>(curr->currentItem());
            tb->newCustomers(customers);
            tb->setIsSpaceAvailable(false);
            for (size_t i = 0; i < customers.size(); i++)
                customers.at(i)->beSeated(tb->getID());
            //std::cout<<"The customers have been seated at table "<<tb->getID()<<std::endl;
            //std::cout << " ~ The customers have been seated at table " << tb->getID() << " ~ " << std::endl;
            std::cout << "\033[46;30m ~ The customer group has been seated at table " << tb->getID() << " ~ \033[0m" << std::endl;


            return true;
        }
        curr->next();
    }
    return false;
}


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

    std::cout<<"The following tables have been merged:"<<std::endl;
    for (int i = 0; i < tables.size(); i++)   
        std::cout<<tables.at(i)->toString()<<std::endl;
    
    tables.at(0)->acceptVisitor(std::make_shared<setSpaceVisitor>(setSpaceVisitor(newSpace)));
    tables.at(0)->acceptVisitor(std::make_shared<setMergeVisitor>(setMergeVisitor(1)));
    for (int i = 1; i < tables.size(); i++)
    {
        tables.at(i)->acceptVisitor(std::make_shared<setVisibilityVisitor>(setVisibilityVisitor(0)));
    }

    return true;
}

void Floor::unmerdgeTiles() //works without customers 
{
    std::shared_ptr<myIterator> curr = theFloor->getDepthIterator();
    std::vector<std::shared_ptr<floorComponent>> mergedTables;
    std::vector<std::shared_ptr<floorComponent>> hidenTables;
    int temp =0;
    
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
        if(mergedTables.at(i)->acceptVisitor(std::make_shared<getIsAvailableVisitor>())==1)
        {
            int newSize = mergedTables.at(i)->acceptVisitor(std::make_shared<findSpaceVisitor>()); 
            for (int x = 0; x < hidenTables.size() && newSize>tableSpace; x++)
            {
                    hidenTables.at(x)->acceptVisitor(std::make_shared<setVisibilityVisitor>(setVisibilityVisitor(1)));
                    hidenTables.at(x)->acceptVisitor(std::make_shared<setIsAvailableVisitor>(setIsAvailableVisitor(1)));
                    newSize = newSize - hidenTables.at(x)->acceptVisitor(std::make_shared<findSpaceVisitor>());              
            }
            mergedTables.at(i)->acceptVisitor(std::make_shared<setVisibilityVisitor>(setVisibilityVisitor(1)));
            mergedTables.at(i)->acceptVisitor(std::make_shared<setMergeVisitor>(setMergeVisitor(0)));  
            mergedTables.at(i)->acceptVisitor(std::make_shared<setIsAvailableVisitor>(setIsAvailableVisitor(1))); 
            mergedTables.at(i)->acceptVisitor(std::make_shared<setSpaceVisitor>(setSpaceVisitor(newSize)));    
        }
         
    }
}

std::shared_ptr<table> Floor::getTableAt(int id) //Works correctly
{
    std::shared_ptr<myIterator> curr = theFloor->getDepthIterator();

    while(curr->hasNext())
    {
        if(curr->currentItem()->getID()==id && curr->currentItem()->getNumChildren()==0)
            return std::dynamic_pointer_cast<table>(curr->currentItem());
        curr->next();
    }
    return nullptr;
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

void Floor::customersLeft(int id)
{
    std::shared_ptr<table> tb = getTableAt(id);
    std::cout<<tb->toString()<<std::endl;
    tb->removeCustomers();
    tb->setIsSpaceAvailable(true);
    this->unmerdgeTiles();
}

Floor::~Floor()
{}
