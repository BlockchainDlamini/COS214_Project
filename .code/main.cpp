#include <iostream>
#include "Customer.h"
#include "Floor.h"
#include "RegularWaiter.h"
#include "MaitreD.h"

// #include "Floor.h"

using namespace std;

// Test for regularWaiter class
void testRegularWaiter() {
    cout<<"Testing for the waiter class"<<endl;
    
    // Create a Floor (assuming you have the implementation)
    shared_ptr<Floor> floorObj;

    // Create a regularWaiter object
    int waiterId = 1;
    RegularWaiter waiter(waiterId, {1, 2, 3}, floorObj);

    // Assign a table to the waiter
    shared_ptr<table> table1 = make_shared<table>(1);

    // Take an order for table 1
    waiter.takeOrder(1);

    // Get orders for the kitchen
    std::pair<int, std::vector<std::shared_ptr<Order>>> kitchenOrders = waiter.getForKitchen();


    std::shared_ptr<Pizza> pizza1 = std::make_shared<Pizza>("Margherita", 10);
    std::shared_ptr<Pizza> pizza2 = std::make_shared<Pizza>("Pepperoni", 12);

    // Take orders to the table
    std::vector<std::shared_ptr<Pizza>> pizzasForTable;
    pizzasForTable.push_back(pizza1);
    pizzasForTable.push_back(pizza2);
    waiter.takeOrderToTable(pizzasForTable);

    // Process payment
    waiter.payBill(1);

    // Example of calling the Mediator-related functions (get, changed, set)
    waiter.get();
    waiter.changed();
    waiter.setOperation("SomeOperation");


}

// Test for maitreD class
void testMaitreD() {
    cout<<"Testing for the MaitreD"<<endl;
    // Create a Floor (assuming you have the implementation)
    shared_ptr<Floor> floor = make_shared<Floor>();

    MaitreD maitre("John", floor);

    shared_ptr<Customer> customer1 = make_shared<Customer>(1000, 1);
    shared_ptr<Customer> customer2 = make_shared<Customer>(300, 1);
    shared_ptr<Customer> customer3 = make_shared<Customer>(245, 1);
    shared_ptr<Customer> customer4 = make_shared<Customer>(234, 1);

    // Seat customers
    vector<shared_ptr<Customer>> customers = {customer1, customer2, customer3};
    maitre.seatCustomers(customers);

    // string value = maitre.get();
    // maitre.changed();
    // maitre.setOperation("SomeOperation");
}

void testWaiterVector() {
    cout<<"Testing for the testWaiterVector"<<endl;
    // Create a Floor (assuming you have the implementation)
    shared_ptr<Floor> floor = make_shared<Floor>();

    MaitreD maitre("John", floor);

    shared_ptr<RegularWaiter> newWaiter1 = RegularWaiter::createRegularWaiter(1, vector<int>{1, 2, 3}, floor);
    shared_ptr<RegularWaiter> newWaiter2 = RegularWaiter::createRegularWaiter(2, vector<int>{4, 5, 6}, floor);

    // Assign a table to the waiter
    shared_ptr<table> table1 = make_shared<table>(1);
    // Take an order for table 1
    RegularWaiter waiter(1, {1}, floor);
    waiter.takeOrder(5);

    // Get orders for the kitchen
    std::pair<int, std::vector<std::shared_ptr<Order>>> kitchenOrders = waiter.getForKitchen();


    std::shared_ptr<Pizza> pizza1 = std::make_shared<Pizza>("Margherita", 10);
    std::shared_ptr<Pizza> pizza2 = std::make_shared<Pizza>("Pepperoni", 12);

    cout<<"from test"<<endl;

    // RegularWaiter waiter(1, {1}, floor);
    shared_ptr<RegularWaiter> waiterFromClass = waiter.waiterResponsible(1);
    waiterFromClass->takeOrder(2);

}

int main() {
    cout<<"Testing my waiter class"<<endl;
    // Run the test functions for regularWaiter and maitreD
    testRegularWaiter(); // getting segFault
    // testMaitreD();
    // testWaiterVector();

    return 0;
}
