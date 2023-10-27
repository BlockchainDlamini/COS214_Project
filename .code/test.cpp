#include "table.h"
#include "Mediator.h"
#include "iterator.h"
#include "gameElement.h"
#include "floorComponent.h"
#include "floor.h"
#include "depthFirstIterator.h"
#include "breadthFirstIterator.h"
#include <iostream>

std::shared_ptr<floorComponent> createFloor()
{
    std::shared_ptr<floorComponent> floor = std::make_shared<floorComponent>(floor::floor(0));

    for (int i = 0; i < 4; i++)
    {
        std::shared_ptr<floorComponent> tile = std::make_shared<floorComponent>(floor::floor(1+i));
        std::shared_ptr<floorComponent> tbl = std::make_shared<floorComponent>(table(1+i));
        tile->add(tbl);
        floor->add(tile);
        std::shared_ptr<floorComponent> tile2 = std::make_shared<floorComponent>(floor::floor(2+i));
        std::shared_ptr<floorComponent> tbl2 = std::make_shared<floorComponent>(table(2+i));
        tile2->add(tbl2);
        floor->add(tile2);
        std::shared_ptr<floorComponent> tile3 = std::make_shared<floorComponent>(floor::floor(3+i));
        std::shared_ptr<floorComponent> tbl3 = std::make_shared<floorComponent>(table(3+i));
        tile3->add(tbl3);
        floor->add(tile3);
        std::shared_ptr<floorComponent> tile4 = std::make_shared<floorComponent>(floor::floor(4+i));
        std::shared_ptr<floorComponent> tbl4 = std::make_shared<floorComponent>(table(4+i));
        tile4->add(tbl4);
        floor->add(tile4);
    }
    return floor;    
}

void testBreadthFirstIterator(std::shared_ptr<floorComponent> floor)
{
    std::shared_ptr<myIterator> it = floor->getBreadthIterator();
    while(it->hasNext())
    {
        std::cout<<it->currentItem()<<std::endl;
        it->next();
    }
}

void testDepthFirstIterator(std::shared_ptr<floorComponent> floor)
{
    std::shared_ptr<myIterator> it = floor->getDepthIterator();
    while(it->hasNext())
    {
        std::cout<<it->currentItem()<<std::endl;
        it->next();
    }
}

int main()
{
    std::shared_ptr<floorComponent> floor = createFloor();
    testBreadthFirstIterator(floor);
    testDepthFirstIterator(floor);
    return 0;
}