#ifndef VISITOR_H
#define VISITOR_H

#include "floorComponent.h"
#include "floorComposite.h"
#include "table.h"
#include <memory>

class visitor
{
    public:
        visitor(){};
        virtual int visitTable(std::shared_ptr<table>)=0;
        virtual int visitTile(std::shared_ptr<floorComposite>)=0;
        ~visitor(){};
};

#endif