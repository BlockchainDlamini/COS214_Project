#ifndef FLOOR_H 
#define FLOOR_H

#include "gameElement.h"
#include "floorComponent.h"
#include <iostream>

class Floor: public gameElement
{
    private:
        std::shared_ptr<floorComponent> theFloor;
        int sideLenght, tableSpace;
        bool merdgeTile(int);
        void unmerdgeTiles();
        
    public:
        Floor(int, int);
        bool hasSpace(int);
        //int seatCustomer(std::vector<std::shared_ptr<customer>>);
        void printBreadth();
        void printDepth();
        std::shared_ptr<floorComponent> getTableAt(int);
        virtual ~Floor();
};


#endif