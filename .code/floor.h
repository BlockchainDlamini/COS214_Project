#ifndef FLOOR_H
#define FLOOR_H

#include <memory>
#include <vector>
#include <iterator>
#include "floorComponent.h"
#include "iterator.h" 


class floor: public floorComponent
{
    protected:
        std::vector<std::shared_ptr<floorComponent>> next;
        int number;

    public:
        floor(int);
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
        virtual ~floor();    

};

#endif

