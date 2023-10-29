#ifndef MYITERATOR_H
#define MYITERATOR_H

#include <queue>
#include "floorComponent.h"

class myIterator
{
    protected:
        std::queue<std::shared_ptr<floorComponent>> flattenedTree;
        virtual void flattenTree(std::shared_ptr<floorComponent>) = 0;
        std::shared_ptr<floorComponent> head;
        std::shared_ptr<floorComponent> current;
    public:
        myIterator(std::shared_ptr<floorComponent>);
        virtual std::shared_ptr<floorComponent> first();
        virtual void next(); //moves pointer
        virtual std::shared_ptr<floorComponent> currentItem();
        virtual bool hasNext();
        virtual ~myIterator();
};

#endif