#ifndef BREADTHFIRSTITERATOR_H
#define BREADTHFIRSTITERATOR_H

#include "iterator.h"
#include <queue>

class breadthFirstIterator: public myIterator
{
    private:
        void flattenTree(std::shared_ptr<floorComponent>);
        int height(std::shared_ptr<floorComponent>);
        void breadthFirstIterator::pushCurrentLevel(std::shared_ptr<floorComponent>, int);
    public:
        breadthFirstIterator(std::shared_ptr<floorComponent>);
        std::shared_ptr<floorComponent> first(){};
        void next(){};
        std::shared_ptr<floorComponent> currentItem(){};
        bool hasNext(){};
        ~breadthFirstIterator();
};

#endif