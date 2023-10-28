#include "floor.h"
#include "findSpaceVisitor.h"


floor::floor(int size)
{
    sideLenght = size;
    myFloor = std::make_shared<floorComponent>(compositeFloor(0));

    for (int i = 0; i < 4; i++)
    {
        for (int x = 0; x < size; i++)
        {
            std::shared_ptr<floorComponent> tile = std::make_shared<floorComponent>(compositeFloor(1+i));
            std::shared_ptr<floorComponent> tb = std::make_shared<floorComponent>(table(1+i));
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

bool floor::seatCustomer(std::vector<std::shared_ptr<customer>> customers)
{
    if(hasSpace(customers->size()))
    {

    }
    else
        return false;
}

void floor::merdgeTile(int amount)
{
    std::shared_ptr<myIterator> curr = myFloor->getDepthIterator();
    std::shared_ptr<myIterator> prev = myFloor->getDepthIterator();
    std::shared_ptr<visitor> visit = std::make_shared<visitor>(new findSpaceVisitor());
    std::queue<std::shared_ptr<floorComponent>> tables;
    std::queue<std::shared_ptr<floorComponent>> tiles;
    int temp;

    curr->next();
    //Finding the tables to merdge
    while(curr->hasNext() && amount>0)
    {
        temp = curr->currentItem()->acceptVisitor(visit);
        if(temp>0)
        {
            tables.push(curr->currentItem());
            tiles.push(prev->currentItem());
            amount-=temp;
        }
        curr->next();
        prev->next();
    }

    



}

void floor::unmerdgeTiles()
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
