#ifndef FLOOR_H
#define FLOOR_H

#include <memory>

class floor
{
    public:
        floor(){};
        virtual void add(std::shared_ptr<floor>)=0;
        virtual void remove(std::shared_ptr<floor>)=0;
        virtual ~floor(){};
};

#endif

