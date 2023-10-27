#ifndef MAITRED_H
#define MAITRED_H

#include "Waiter.h"
#include <iostream>
#include <memory>

using namespace std;

class maitreD : public Waiter {
public:
    // tables that this specific waiter waiters
    vector<table> assignedTables; // tables has a vector<Customers>
    Kitchen kitchen;
    string name;
    
    maitreD(string name, vector<tables> assignedTables, Kitchen kitchen);
    void takeOrder(Customer& customer, const Order& order);
    void bringOrder(Customer& customer, const Order& order);
    void communicateWithKitchen(const Order& order);
    void pickUpOrderFromKitchen(const Order& order);
    void processPayment(Customer& customer);
    void get();
    void changed();
    void set();

};

#endif //MAITRED_H