#ifndef DEPTHFIRSTITERATOR_H
#define DEPTHFIRSTITERATOR_H

#include "iterator.h"

class depthFirstIterator: public myIterator
{
    public:
        depthFirstIterator(std::shared_ptr<floorComponent>);
        std::shared_ptr<floorComponent> first();
        std::shared_ptr<floorComponent> next();
        std::shared_ptr<floorComponent> currentItem();
        bool isDone();
        ~depthFirstIterator();
};

#endif