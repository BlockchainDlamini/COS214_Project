#ifndef DEPTHFIRSTITERATOR_H
#define DEPTHFIRSTITERATOR_H

#include "iterator.h"
class depthFirstIterator: public myIterator
{
    private:
        void flattenTree(std::shared_ptr<floorComponent>);
    public:
        depthFirstIterator(std::shared_ptr<floorComponent>);
        std::shared_ptr<floorComponent> first(){return myIterator::first();};
        void next(){};
        std::shared_ptr<floorComponent> currentItem(){return myIterator::currentItem();};
        bool hasNext(){return myIterator::hasNext();};
        ~depthFirstIterator();
};

#endif