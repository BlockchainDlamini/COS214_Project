#ifndef TABLE_H
#define TABLE_H

#include "floor.h"
#include <memory>
#include <vector>

class table: public floor
{
    private:
        std::vector<std::shared_ptr<floor>> customers;
    public:
        table();
        void add(std::shared_ptr<floor>);
        void remove(std::shared_ptr<floor>);
        ~table();
};

#endif