#include "MaitreD.h"

MaitreD::MaitreD(string name, shared_ptr<Floor> floor) {
    this->name=name;
    this->floorobj = floor;
}

string MaitreD::get() {
    return operation;
}

void MaitreD::changed() {
}

void MaitreD::setOperation(string op) {
    operation = op;
}

void MaitreD::seatCustomers(std::vector<std::shared_ptr<Customer>> customers)
{
    floorobj->seatCustomer(customers);
}
