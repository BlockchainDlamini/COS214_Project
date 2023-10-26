#ifndef BREADTHFIRSTITERATOR_H
#define BREADTHFIRSTITERATOR_H

#include "iterator.h"

class breadthFirstIterator: public myIterator
{
    public:
        breadthFirstIterator(std::shared_ptr<floorComponent>);
        std::shared_ptr<floorComponent> first();
        std::shared_ptr<floorComponent> next();
        std::shared_ptr<floorComponent> currentItem();
        bool isDone();
        ~breadthFirstIterator();
};

#endif