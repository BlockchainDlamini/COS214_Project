#ifndef WAITER_H
#define WAITER_H

#include <string>
#include <vector>
#include <iostream>
#include "Customer.h"
#include "Kitchen.h"
#include "iterator.h"
#include "gameElement.h"
#include "table.h"
#include "Order.h"

using namespace std;

class Waiter : public gameElement {
public:
    virtual void takeOrder(std::shared_ptr<Customer> customer, std::shared_ptr<Order> order) = 0; // take order from customer
    virtual void bringOrder(std::shared_ptr<Customer> customer, std::shared_ptr<Order> order) = 0;
   
    virtual void communicateWithKitchen(std::shared_ptr<Order> order) = 0; // take order to kitchen
    virtual void pickUpOrderFromKitchen(std::shared_ptr<Order> order) = 0; // pick up order from customer
    virtual void processPayment(std::shared_ptr<Customer> customer) = 0;

    virtual void get() = 0;
    virtual void changed() = 0;
    virtual void set() = 0;

    virtual ~Waiter() {};
};

#endif // WAITER_H
