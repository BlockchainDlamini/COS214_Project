#ifndef MAITRED_H
#define MAITRED_H

#include "Waiter.h"
#include "Floor.h"

#include <iostream>
#include <memory>

using namespace std;

class MaitreD : public Waiter {
public:
    MaitreD(string name, shared_ptr<Floor> floor);

    // maitreD specific
    // void mergeTables(); - floor deals with merging tables
    void seatCustomers(std::vector<std::shared_ptr<Customer>> customers);

    virtual string get();
    void changed();
    void setOperation(string op);

private:
    vector<table> assignedTables;
    shared_ptr<Floor> floorobj;
    string name;
};

#endif //MAITRED_H