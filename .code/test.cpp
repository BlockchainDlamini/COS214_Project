#include <iostream>
#include "floor.h"
#include "floorComposite.h"
#include "table.h"
#include "iterator"
#include "breadthFirstIterator.h"
#include "depthFirstIterator.h"

void basicComposteTest()
{
    std::cout<<"Test basic creation and linking. Only making 1 tile and table and linking"<<std::endl;
    std::shared_ptr<floorComponent> theFloor = std::make_shared<floorComposite>(floorComposite(0));
    std::shared_ptr<floorComponent> tile = std::make_shared<floorComposite>(floorComposite(1));
    std::shared_ptr<floorComponent> tb = std::make_shared<table>(table(1, 4));

    tile->add(tb);
    theFloor->add(tile);

    std::cout<<"First node (Not a actual floor tile): "<< theFloor->toString() <<std::endl;
    std::cout<<"Number of children: "<<theFloor->getNumChildren()<<std::endl;
    std::cout<<"The children are: "<<std::endl;
    for (int i = 0; i < theFloor->getNumChildren(); i++)
    {
        std::cout<<theFloor->getChild(i)->toString()<<std::endl;
        std::cout<<"This child had this number of children: "<<theFloor->getChild(i)->getNumChildren()<<std::endl;
        std::cout<<"The children are: "<<std::endl;
        for (int x = 0; x < theFloor->getChild(i)->getNumChildren(); x++)
        {
            std::cout<<theFloor->getChild(i)->getChild(x)->toString()<<std::endl;
        }
    }
}

void printFloor(std::shared_ptr<floorComponent> curr)
{
    std::cout<<curr->toString()<<std::endl;
    for (int i = 0; i < curr->getNumChildren(); i++)
    {
        printFloor(curr->getChild(i));
    }
}

int height(std::shared_ptr<floorComponent> curr)
{
    if (curr->getNumChildren()==0)
    {
        return -1;
    }
    else {
        int max = -1;
        for (int i = 0; i <curr->getNumChildren(); i++)
        {
            int childHeight = height(curr->getChild(i));
            if(childHeight>max)
                max = childHeight;            
        }
        return max+1;
    }
}

void fullFloorCreationTest()
{
    std::cout<<"Creating a 4 by 4 floor. 16 tables total"<<std::endl;
    std::shared_ptr<floorComponent> theFloor = std::make_shared<floorComposite>(floorComposite(0));

    for (int i = 0; i < 4; i++)
    {
        std::shared_ptr<floorComponent> tile = std::make_shared<floorComposite>(floorComposite(1+i*4));
        std::shared_ptr<floorComponent> tb = std::make_shared<table>(table(1+i*4, 4));
        tile->add(tb);
        std::shared_ptr<floorComponent> prev = nullptr;
        for (int x = 0; x < 3; x++)
        {
            std::shared_ptr<floorComponent> subTile = std::make_shared<floorComposite>(floorComposite(2+i*4+x));
            std::shared_ptr<floorComponent> subTb = std::make_shared<table>(table(2+i*4+x, 4));
            if(x==0)
                prev = tile;
            subTile->add(subTb);
            prev->add(subTile);
            prev = subTile;  
        }
        theFloor->add(tile);
    }

    std::cout<<"The table has been created"<<std::endl;
    std::cout<<"The table is as follows"<<std::endl;

    printFloor(theFloor);

    std::cout<<"The tree has height of: "<<std::endl;
    std::cout<<height(theFloor)<<std::endl;
}

void variableSizeTreeTest(int size)
{
    std::cout<<"Creating a "<<size<<" by "<<size<<" floor. "<<size*size<<" tables total"<<std::endl;
    std::shared_ptr<floorComponent> theFloor = std::make_shared<floorComposite>(floorComposite(0));

    for (int i = 0; i < size; i++)
    {
        std::shared_ptr<floorComponent> tile = std::make_shared<floorComposite>(floorComposite(1+i*size));
        std::shared_ptr<floorComponent> tb = std::make_shared<table>(table(1+i*size, size));
        tile->add(tb);
        std::shared_ptr<floorComponent> prev = nullptr;
        for (int x = 0; x < size-1; x++)
        {
            std::shared_ptr<floorComponent> subTile = std::make_shared<floorComposite>(floorComposite(2+i*size+x));
            std::shared_ptr<floorComponent> subTb = std::make_shared<table>(table(2+i*size+x, 4));
            if(x==0)
                prev = tile;
            subTile->add(subTb);
            prev->add(subTile);
            prev = subTile;  
        }
        theFloor->add(tile);
    }

    std::cout<<"The table has been created"<<std::endl;
    std::cout<<"The table is as follows"<<std::endl;

    printFloor(theFloor);

    std::cout<<"The tree has height of: "<<std::endl;
    std::cout<<height(theFloor)<<std::endl;
}

void testDepthFirstIterator(int size)
{
    std::cout<<"Creating a "<<size<<" by "<<size<<" floor. "<<size*size<<" tables total"<<std::endl;
    std::shared_ptr<floorComponent> theFloor = std::make_shared<floorComposite>(floorComposite(0));

    for (int i = 0; i < size; i++)
    {
        std::shared_ptr<floorComponent> tile = std::make_shared<floorComposite>(floorComposite(1+i*size));
        std::shared_ptr<floorComponent> tb = std::make_shared<table>(table(1+i*size, size));
        tile->add(tb);
        std::shared_ptr<floorComponent> prev = nullptr;
        for (int x = 0; x < size-1; x++)
        {
            std::shared_ptr<floorComponent> subTile = std::make_shared<floorComposite>(floorComposite(2+i*size+x));
            std::shared_ptr<floorComponent> subTb = std::make_shared<table>(table(2+i*size+x, 4));
            if(x==0)
                prev = tile;
            subTile->add(subTb);
            prev->add(subTile);
            prev = subTile;  
        }
        theFloor->add(tile);
    }

    std::cout<<"Getting the iterator"<<std::endl;

    std::shared_ptr<myIterator> it = theFloor->getDepthIterator();

    std::cout<<"The tree is as follows: "<<std::endl;

    while(it->hasNext())
    {
        std::cout<<it->currentItem()->toString()<<std::endl;
        it->next();
    }

    std::cout<<"The head is: "<<it->first()->toString()<<std::endl;
}

void testFloor()
{
    std::cout<<"Making a neew floor"<<std::endl;
    std::shared_ptr<Floor> theFloor = std::make_shared<Floor>(Floor(4, 4));

    std::cout<<std::endl;
    std::cout<<"Depth first iteration:"<<std::endl;
    theFloor->printDepth();

    std::cout<<std::endl;
    std::cout<<"Checking the space function with group that should fit:"<<std::endl;
    if(theFloor->hasSpace(3))
        std::cout<<"The floor has space"<<std::endl;
    else    
        std::cout<<"The floor doesn't have space"<<std::endl;

    std::cout<<"Checking the space function with group that shouldn't fit:"<<std::endl;
    if(theFloor->hasSpace(5))
        std::cout<<"The floor has space"<<std::endl;
    else    
        std::cout<<"The floor doesn't have space"<<std::endl;

    std::cout<<std::endl;
    std::cout<<"Testing tableAt() function"<<std::endl;
    for (int i = 0; i < 18; i++)
    {
        std::shared_ptr<floorComponent> tb = theFloor->getTableAt(i); 
        if(tb!=nullptr)   
            std::cout<<"The table is: "<<tb->toString()<<std::endl;
        else
            std::cout<<"The table doesn't exit"<<std::endl;
    }

    /*std::cout<<std::endl;
    std::cout<<"Testing the merge function"<<std::endl;
    std::cout<<"Testing a merge with a single table"<<std::endl;
    theFloor->merdgeTile(7);
    theFloor->printDepth();

    std::cout<<"Testing a merge with 5 table"<<std::endl;
    theFloor->merdgeTile(20);
    theFloor->printDepth();


    std::cout<<std::endl;
    std::cout<<"Testing the unmerge function"<<std::endl;
    theFloor->unmerdgeTiles();
    theFloor->printDepth();  */  
}

void testSeating(int size)
{
    std::cout<<"Creating the floor"<<std::endl;
    std::shared_ptr<Floor> theFloor = std::make_shared<Floor>(Floor(4, 4));

    for (size_t i = 0; i <9; i++)
    {
        std::cout<<"Creating the customer vector"<<std::endl;
        std::vector<std::shared_ptr<Customer>> customers;

        for (int i = 0; i < size; i++)
        {
            customers.push_back(std::make_shared<Customer>(Customer(i+1, (i+1)*3)));
        }
        std::cout<<"Seating the customer"<<std::endl;
        theFloor->printDepth();
        if(theFloor->seatCustomer(customers))
            std::cout<<"The customer was seated"<<std::endl;
        else
        {
            std::cout<<"The customer was not seated"<<std::endl;
        }
        theFloor->printDepth();    
        std::cout<<std::endl;
    }   
    std::cout<<"Customers a table 1 has left"<<std::endl;
    theFloor->customersLeft(1);
    theFloor->printDepth(); 
    theFloor->customersLeft(3);
    theFloor->printDepth(); 
    theFloor->customersLeft(5);
    theFloor->printDepth(); 
}

int main()
{
    //basicComposteTest(); //complete
    //fullFloorCreationTest(); //complete
    //variableSizeTreeTest(5); //complete
    //testDepthFirstIterator(4); //complete
    //testFloor(); //Complete
    testSeating(8); //Conplete

    return 0;
}