#ifndef VISITOR_H
#define VISITOR_H

#include <memory>

class floorComposite;
class table;

class visitor
{
    public:
        visitor(){};
        virtual int visitTable(std::shared_ptr<table>)=0;
        virtual int visitTile(std::shared_ptr<floorComposite>)=0;
        ~visitor(){};
};

#endif