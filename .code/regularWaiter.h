#ifndef REGULARWAITER_H
#define REGULARWAITER_H

#include "Waiter.h"

#include <iostream>

using namespace std;

class regularWaiter : public Waiter {
public:
    string name;
    vector<Customer> assignedCustomers

    regularWaiter(string name, vector<Customer> assignedCustomers);

    void assignCustomer(Customer& customer);
    void takeOrder(Customer& customer, const Order& order);
    void bringOrder(Customer& customer, const Order& order);
    void getBill(Customer& customer);
    
    void communicateWithKitchen(const Order& order);
    void pickUpOrderFromKitchen(const Order& order);
    void processPayment(Customer& customer);

    void get();
    void changed();
    void set();

};

#endif //REGULARWAITER_H