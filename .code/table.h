#ifndef TABLE_H
#define TABLE_H

#include "floorComponent.h"
#include <vector>
#include <memory>

class table: public floorComponent
{
    private:
        std::vector<std::shared_ptr<floorComponent>> customers;
        int space, tableNumber;
        bool isSpaceAvailable;
    public:
        table(int, int);
        void add(std::shared_ptr<floorComponent>);
        void remove(std::shared_ptr<floorComponent>);
        std::shared_ptr<floorComponent> getChild(int);
        int getNumChildren();
        std::shared_ptr<myIterator> getDepthIterator();
        std::shared_ptr<myIterator> getBreadthIterator();
        void newCustomers(std::vector<std::shared_ptr<floorComponent>>);
        void removeCustomers();
        int spaceAvailable();
        void setSpace(int);
        std::string toString();
        int acceptVisitor(std::shared_ptr<visitor>);
        ~table();
};

#endif