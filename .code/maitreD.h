#ifndef MAITRED_H
#define MAITRED_H

#include "Waiter.h"

#include <iostream>

using namespace std;

class maitreD : public Waiter {
public:
    
    MaitreD(const std::string& name);
    void assignCustomer(Customer& customer);
    void takeOrder(Customer& customer, const Order& order);
    void bringOrder(Customer& customer, const Order& order);
    void getBill(Customer& customer);
    
    void communicateWithKitchen(const Order& order);
    void pickUpOrderFromKitchen(const Order& order);
    void processPayment(Customer& customer);

    // extra functions only for the MaitreD

    void seatCustomer(const Customer& customer, Table& table);
    void mergeTables(Table& table1, Table& table2);


};

#endif //MAITRED_H