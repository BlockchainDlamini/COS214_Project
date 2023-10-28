#include "regularWaiter.h"
#include "Kitchen.h"
#include "iterator.h"

regularWaiter::regularWaiter(string name, vector<shared_ptr<table>> assignedTables, Kitchen kitchen) {
    this->name=name;
    this->assignedTables=assignedTables;
    this->kitchen = kitchen
}

void regularWaiter::assignTable(shared_ptr<table> table)
{
    tables.push_back(table);
    std::cout << name << " has been assigned table number " << table->getNum() << std::endl;
    //ADD getNum() to table class
}

void regularWaiter::assignCustomer(std::shared_ptr<Customer> customer) {
    assignedCustomers.push_back(customer);
    std::cout << name << " has been assigned to serve Customer " << customer->getID() << std::endl;
}

void regularWaiter::takeOrder(shared_ptr<Customer> customer, std::shared_ptr<Order> order) {
    cout << name << " takes the order down from Customer " << customer.getID() << endl;
    communicateWithKitchen(order);
}

void regularWaiter::bringOrder(shared_ptr<Customer> customer, std::shared_ptr<Order> order) {
    cout << name << " brings the order to Customer " << customer.getID() << endl;
    pickUpOrderFromKitchen(order);
    customer.getOrder(order);
}

// to send the order to the kitchen
void regularWaiter::communicateWithKitchen(std::shared_ptr<Order> order) {
    kitchen.receiveOrder(order);
    cout << name << " communicates the order to the kitchen." << endl;
}

// only when notified by kitchen
// pick up the order from the kitchen
void regularWaiter::pickUpOrderFromKitchen(std::shared_ptr<Order> order) {
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
