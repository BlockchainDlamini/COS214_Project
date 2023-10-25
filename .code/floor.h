#ifndef FLOOR_H
#define FLOOR_H

#include <memory>
#include <vector>
#include <iterator>
#include "floorComponent.h"

class floor: public floorComponent
{
    private:
        std::vector<std::shared_ptr<floorComponent>> next;
    public:
        floor();
        void add(std::shared_ptr<floorComponent>);
        void remove(std::shared_ptr<floorComponent>);
        virtual ~floor();    
};

#endif

