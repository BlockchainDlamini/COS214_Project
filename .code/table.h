#ifndef TABLE_H
#define TABLE_H

#include "floorComponent.h"
#include <memory>
#include <vector>

class table: public floorComponent
{
    private:
        std::vector<std::shared_ptr<floorComponent>> customers;
        int space, number;
    public:
        table(int);
        void add(std::shared_ptr<floorComponent>);
        void remove(std::shared_ptr<floorComponent>);
        std::shared_ptr<floorComponent> getChild(int);
        int getNumChildren();
        int getIndexOfChild(std::shared_ptr<floorComponent>);
        void setCurrentChild(int);
        int getCurretnChild();
        std::shared_ptr<myIterator> getDepthIterator();
        std::shared_ptr<myIterator> getBreadthIterator();
        void newCustomers(std::vector<std::shared_ptr<floorComponent>>);
        void removeCustomers();
        int spaceAvailable();
        void setSpace(int);
        std::string toString();
        //void acceptVisitor(std::shared_ptr<maitreD>);
        ~table();
};

#endif