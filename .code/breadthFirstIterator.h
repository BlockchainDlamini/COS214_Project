#ifndef BREADTHFIRSTITERATOR_H
#define BREADTHFIRSTITERATOR_H

#include "iterator.h"

class breadthFirstIterator: public myIterator
{
    public:
        breadthFirstIterator(std::shared_ptr<floorComponent>);
        std::shared_ptr<floorComponent> first();
        void next();
        std::shared_ptr<floorComponent> currentItem();
        bool hasNext();
        ~breadthFirstIterator();
};

#endif