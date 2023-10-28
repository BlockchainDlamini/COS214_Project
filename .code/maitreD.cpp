#include "maitreD.h"

maitreD::maitreD(string name, shared_ptr<floor> floor) {
    this->name=name;
    this->floor = floor;
}

string maitreD::get() {
    return operation;
}

void maitreD::changed() {
}

void maitreD::setOperation(string op) {
    operation = op;
}

void maitreD::seatCustomers(std::shared_ptr<Customer> customer)
{
    floor.seatCustomer(customer);
}
