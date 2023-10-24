#ifndef FLOORUNIT_H
#define FLOORUNIT_H

#include <memory>
#include <vector>
#include "floor.h"

class floorUnit: public floor
{
    private:
        std::vector<std::shared_ptr<floor>> next;
    public:
        floorUnit();
        void add(std::shared_ptr<floor>);
        void remove(std::shared_ptr<floor>);
        virtual ~floorUnit();
};

#endif
