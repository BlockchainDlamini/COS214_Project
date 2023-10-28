#ifndef MAITRED_H
#define MAITRED_H

#include "Waiter.h"
#include "Floor.h"

#include <iostream>

using namespace std;

class maitreD : public Waiter {
public:
    maitreD::maitreD(string name, vector<tables> assignedTables, shared_ptr<Floor> floor);

    // maitreD specific
    // void mergeTables(); - floor deals with merging tables
    void seatCustomers();

    void get();
    void changed();
    void set(string op);

private:
    vector<table> assignedTables;
    Floor floor;
    string name;
};

#endif //MAITRED_H