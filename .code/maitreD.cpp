#include "maitreD.h"
#include "Kitchen.h"
#include "iterator.h"

// dont use a kitchen obj, send the commands to the mediator

maitreD::maitreD(string name, vector<tables> assignedTables) {
    this->name=name;
    this->assignedTables=assignedTables;
}

void regularWaiter::get() {
    return *this;
}

void regularWaiter::changed() {
}

void regularWaiter::set(string op) {
    operation = op;
}

void maitreD::seatCustomers(std::shared_ptr<Customer> customer)
{
    floor.seatCustomer(vector list of customers);
}
