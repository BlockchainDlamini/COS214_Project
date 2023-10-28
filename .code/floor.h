#ifndef FLOOR_H 
#define FLOOR_H

#include <memory>
#include "floorComponent.h"
#include "table.h"
#include "floorComposite.h"
#include "gameElement.h"
#include "iterator.h"
#include "breadthFirstIterator.h"
#include "depthFirstIterator.h"
#include <iostream>
#include <vector>

class floor: public gameElement
{
    private:
        std::shared_ptr<floorComponent> myFloor;
        int sideLenght, tableSpace;
        void merdgeTile(int);
        void unmerdgeTiles();
    public:
        floor(int);
        bool hasSpace(int);
        //bool seatCustomer(std::vector<std::shared_ptr<customer>>);
        void printBreadth();
        void printDepth();
        std::shared_ptr<table> getTableAt(int);
        void changed(){};
        void set(){};
        void get(){};
        ~floor();
};


#endif