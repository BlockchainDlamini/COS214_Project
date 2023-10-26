#ifndef FLOORCOMPONENT_H
#define FLOORCOMPONENT_H

#include <memory>
#include <vector>
#include "iterator.h"
#include "depthFirstIterator.h"
#include "breadthFirstIterator.h"
class floorComponent
{
    public:
        floorComponent(){};
        virtual void add(std::shared_ptr<floorComponent>)=0;
        virtual void remove(std::shared_ptr<floorComponent>)=0;
        virtual std::shared_ptr<floorComponent> getChild(int)=0;
        virtual int getNumChildren()=0;
        virtual std::shared_ptr<myIterator> getDepthIterator()=0;
        virtual std::shared_ptr<myIterator> getBreadthIterator()=0;
        virtual ~floorComponent(){};    

    friend myIterator;
};

#endif
