#include "maitreD.h"
#include "Kitchen.h"
#include "iterator.h"

maitreD::maitreD(string name, vector<tables> assignedTables, Kitchen kitchen) {
    this->name=name;
    this->assignedTables=assignedTables;
    this->kitchen = kitchen
}

void regularWaiter::assignCustomer(Customer& customer) {
    assignedCustomers.push_back(customer);
    cout << name << " has been assigned to serve Customer " << customer.getID() << endl;
}

void regularWaiter::takeOrder(Customer& customer, const Order& order) {
    cout << name << " takes the order down from Customer " << customer.getID() << endl;
    communicateWithKitchen(order);
}

void regularWaiter::bringOrder(Customer& customer, const Order& order) {
    cout << name << " brings the order to Customer " << customer.getID() << endl;
    pickUpOrderFromKitchen(order);
    customer.getOrder(order);
}

// to send the order to the kitchen
void regularWaiter::communicateWithKitchen(const Order& order) {
    kitchen.receiveOrder(order);
    cout << name << " communicates the order to the kitchen." << endl;
}

// pick up the order from the kitchen
void regularWaiter::pickUpOrderFromKitchen(const Order& order) {
    kitchen.prepareOrder(order);
    cout << name << " picks up the order from the kitchen." << endl;
}

void regularWaiter::processPayment(Customer& customer) {
    //send bill to the customer
    //payBill can be P or T
    // bool paid = customer.sendBill(amountOfBill);

    // if (paid) {
    //     cout << name << " processes the payment for Customer " << customer.getID() << endl;
    //     cout << name << " payment successful " << customer.getID() << endl;
    // } else {
    //     cout << "Payment processing failed for Customer " << customer.getID() << endl;
    // }
}

void regularWaiter::get() {
}

void regularWaiter::changed() {
}

void regularWaiter::set() {
}

