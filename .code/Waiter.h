#ifndef WAITER_H
#define WAITER_H

#include <string>
#include <vector>
#include <iostream>
#include "order.h"
#include "customer.h"
#include "kitchen.h"
#include "iterator.h"

// should we rather name it floor staff?
// and then we have waiter and maitreD inheriting from floor staff

using namespace std;

class Waiter {
private:
    string name; // name of waiter
    vector<Customer> assignedCustomers; // vector of customers assigned to the waiter
    Kitchen kitchen;

public:
    Waiter(string name, vector<Customer> assignedCustomers);
    
    void assignCustomer(Customer& customer);
    void takeOrder(Customer& customer, const Order& order); // take order from customer
    void bringOrder(Customer& customer, const Order& order);
    void getBill(Customer& customer); // use the iterator class to get the amount of the bill
    
    void communicateWithKitchen(const Order& order); // take order to kitchen
    void pickUpOrderFromKitchen(const Order& order); // pick up order from customer
    void processPayment(Customer& customer);
};

#endif // WAITER_H
