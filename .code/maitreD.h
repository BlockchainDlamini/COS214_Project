#ifndef MAITRED_H
#define MAITRED_H

#include "Waiter.h"

#include <iostream>

using namespace std;

class maitreD : public Waiter {
public:
    // tables that this specific waiter waiters
    vector<table> assignedTables; // tables has a vector<Customers>
    // the whole floor for maitreD?

    Kitchen kitchen;
    string name;
    
    maitreD::maitreD(string name, vector<tables> assignedTables, Kitchen kitchen);

    // maitreD specific
    void getBill(Customer& customer);
    void mergeTables();

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

#endif //MAITRED_H