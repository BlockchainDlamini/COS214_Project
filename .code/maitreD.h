#ifndef MAITRED_H
#define MAITRED_H

#include "Waiter.h"
#include "floor.h"

#include <iostream>
#include <memory>

using namespace std;

class maitreD : public Waiter {
public:
    maitreD::maitreD(string name, shared_ptr<floor> floor);

    // maitreD specific
    // void mergeTables(); - floor deals with merging tables
    void seatCustomers(std::shared_ptr<Customer> customer);

    virtual string get();
    void changed();
    void setOperation(string op);

private:
    vector<table> assignedTables;
    shared_ptr<floor> floorobj;
    string name;
};

#endif //MAITRED_H