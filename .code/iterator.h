#ifndef ITERATOR_H
#define ITERATOR_H

#include <memory>
#include <vector>
#include "floorComponent.h"

class myIterator
{
    protected:
        std::shared_ptr<floorComponent> head;
        std::shared_ptr<floorComponent> current;
        std::shared_ptr<floorComponent> previous;
    public:
        myIterator(std::shared_ptr<floorComponent>);
        virtual std::shared_ptr<floorComponent> first() = 0;
        virtual void next() = 0; //moves pointer
        virtual std::shared_ptr<floorComponent> currentItem() = 0;
        virtual bool hasNext() = 0;
        virtual ~myIterator(){};
};

#endif