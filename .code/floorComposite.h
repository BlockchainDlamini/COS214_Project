#ifndef FLOORCOMPOSITE_H
#define FLOORCOMPOSITE_H

#include <vector>
#include <memory>
#include "floorComponent.h"

class floorComposite: public floorComponent
{
    protected:
        std::vector<std::shared_ptr<floorComponent>> next;
    public:
        floorComposite(int);
        void add(std::shared_ptr<floorComponent>);
        void remove(std::shared_ptr<floorComponent>);
        std::shared_ptr<floorComponent> getChild(int);
        int getNumChildren();
        std::shared_ptr<myIterator> getDepthIterator();
        std::shared_ptr<myIterator> getBreadthIterator();
        std::string toString();
        int acceptVisitor(std::shared_ptr<visitor>);
        virtual ~floorComposite();    
};



#endif

