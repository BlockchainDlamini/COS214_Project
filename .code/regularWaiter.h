#ifndef REGULARWAITER_H
#define REGULARWAITER_H

#include "Waiter.h"

#include <iostream>

using namespace std;

class regularWaiter : public Waiter {
public:
    regularWaiter(string name, vector<Customer> assignedCustomers);

    void assignCustomer(Customer& customer);
    void takeOrder(Customer& customer, const Order& order);
    void bringOrder(Customer& customer, const Order& order);
    void getBill(Customer& customer);
    
    void communicateWithKitchen(const Order& order);
    void pickUpOrderFromKitchen(const Order& order);
    void processPayment(Customer& customer);

};

#endif //REGULARWAITER_H