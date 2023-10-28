#ifndef REGULARWAITER_H
#define REGULARWAITER_H

#include "Waiter.h"
#include "table.h"

#include <iostream>

using namespace std;

class regularWaiter : public Waiter {
private:
    vector<shared_ptr<table>> assignedTables;
public:
    // tables that this specific waiter waiters
    // vector<table> assignedTables; // tables has a vector<Customers>

    Kitchen kitchen;
    string name;

    regularWaiter(string name, vector<shared_ptr<table>> assignedTables, Kitchen kitchen);

    void assignTable(shared_ptr<table> table);

    void assignCustomer(shared_ptr<Customer> customer);
    void takeOrder(shared_ptr<Customer> customer, std::shared_ptr<Order> order);
    void bringOrder(shared_ptr<Customer> customer, std::shared_ptr<Order> order);
    
    void communicateWithKitchen(std::shared_ptr<Order> order);
    void pickUpOrderFromKitchen(std::shared_ptr<Order> order);
    void processPayment(shared_ptr<Customer> customer);

    void get();
    void changed();
    void set();

};

#endif //REGULARWAITER_H