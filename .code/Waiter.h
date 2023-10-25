#ifndef WAITER_H
#define WAITER_H

#include <string>
#include <vector>
#include <iostream>
#include "Order.h"
#include "Customer.h"
#include "Kitchen.h"
#include "iterator.h"
#include "gameElement.h"
#include "table.h"


using namespace std;

class Waiter:gameElement {
public:
    virtual void takeOrder(Customer& customer, const Order& order) = 0; // take order from customer
    virtual void bringOrder(Customer& customer, const Order& order) = 0;
   
    virtual void communicateWithKitchen(const Order& order) = 0; // take order to kitchen
    virtual void pickUpOrderFromKitchen(const Order& order) = 0; // pick up order from customer
    virtual void processPayment(Customer& customer) = 0;

    virtual void get() = 0;
    virtual void changed() = 0;
    virtual void set() = 0;

    virtual ~Waiter() {};
};

#endif // WAITER_H
