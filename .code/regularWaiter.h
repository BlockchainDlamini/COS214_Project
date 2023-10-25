#ifndef REGULARWAITER_H
#define REGULARWAITER_H

#include "Waiter.h"
#include "table.h"

#include <iostream>

using namespace std;

class regularWaiter : public Waiter {
public:
    // tables that this specific waiter waiters
    vector<table> assignedTables; // tables has a vector<Customers>

    Kitchen kitchen;
    string name;

    regularWaiter(string name, vector<tables> assignedTables, Kitchen kitchen);

    void assignCustomer(Customer& customer);
    void takeOrder(Customer& customer, const Order& order);
    void bringOrder(Customer& customer, const Order& order);
    
    void communicateWithKitchen(const Order& order);
    void pickUpOrderFromKitchen(const Order& order);
    void processPayment(Customer& customer);

    void get();
    void changed();
    void set();

};

#endif //REGULARWAITER_H