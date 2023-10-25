#ifndef FLOORCOMPONENT_H
#define FLOORCOMPONENT_H

#include <memory>
#include <vector>

class floorComponent
{
    public:
        floorComponent(){};
        virtual void add(std::shared_ptr<floorComponent>)=0;
        virtual void remove(std::shared_ptr<floorComponent>)=0;
        virtual ~floorComponent(){};
};

#endif
