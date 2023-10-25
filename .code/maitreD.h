#ifndef MAITRED_H
#define MAITRED_H

#include "Waiter.h"

#include <iostream>

using namespace std;

class maitreD : public Waiter {
public:
    
    MaitreD(const std::string& name);

    // maitreD specific
    void assignCustomer(Customer& customer);
    void getBill(Customer& customer);
    void mergeTables();


    void takeOrder(Customer& customer, const Order& order);
    void bringOrder(Customer& customer, const Order& order);
    
    void communicateWithKitchen(const Order& order);
    void pickUpOrderFromKitchen(const Order& order);
    void processPayment(Customer& customer);

    // extra functions only for the MaitreD

    void get();
    void changed();
    void set();


};

#endif //MAITRED_H