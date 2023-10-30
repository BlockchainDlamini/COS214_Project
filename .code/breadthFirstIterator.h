#ifndef BREADTHFIRSTITERATOR_H
#define BREADTHFIRSTITERATOR_H

#include "iterator.h"

class breadthFirstIterator: public myIterator
{
    private:
        std::queue<std::shared_ptr<floorComponent>> flattenedTree;
        void treeFlatten(std::shared_ptr<floorComponent>);
        int height(std::shared_ptr<floorComponent>);
        void pushCurrentLevel(std::shared_ptr<floorComponent>, int);
    public:
        breadthFirstIterator(std::shared_ptr<floorComponent>);
        std::shared_ptr<floorComponent> first(){return myIterator::first();};
        void next(){};
        std::shared_ptr<floorComponent> currentItem(){return myIterator::currentItem();};
        bool hasNext(){return myIterator::hasNext();};
        ~breadthFirstIterator();
};

#endif