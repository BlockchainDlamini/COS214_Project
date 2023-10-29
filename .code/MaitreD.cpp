#include "MaitreD.h"

maitreD::maitreD(string name, shared_ptr<Floor> floor) {
    this->name=name;
    this->floorobj = floor;
}

string maitreD::get() {
    return operation;
}

void maitreD::changed() {
}

void maitreD::setOperation(string op) {
    operation = op;
}

void maitreD::seatCustomers(std::vector<std::shared_ptr<Customer>> customers)
{
    floorobj->seatCustomer(customers);
}
