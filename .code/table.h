#ifndef TABLE_H
#define TABLE_H

#include "floorComponent.h"
#include <memory>
#include <vector>

class table: public floorComponent
{
    private:
        std::vector<std::shared_ptr<floorComponent>> customers;
        int space;
    public:
        table();
        void add(std::shared_ptr<floorComponent>);
        void remove(std::shared_ptr<floorComponent>);
        void newCustomers(std::vector<std::shared_ptr<floorComponent>>);
        void removeCustomers();
        int spaceAvailable();
        void setSpace(int);
        ~table();
};

#endif