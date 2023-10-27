#ifndef FLOOR_H
#define FLOOR_H

#include <vector>
#include <memory>
#include "floorComponent.h"

class myFloor: public floorComponent
{
    protected:
        std::vector<std::shared_ptr<floorComponent>> next;
        int number;

    public:
        myFloor(int);
        void add(std::shared_ptr<floorComponent>);
        void remove(std::shared_ptr<floorComponent>);
        std::shared_ptr<floorComponent> getChild(int);
        int getNumChildren();
        int getIndexOfChild(std::shared_ptr<floorComponent>);
        void setCurrentChild(int);
        int getCurretnChild();
        std::shared_ptr<myIterator> getDepthIterator();
        std::shared_ptr<myIterator> getBreadthIterator();
        std::string toString();
        //void acceptVisitor(std::shared_ptr<maitreD>);
        virtual ~myFloor();    

};

#endif

