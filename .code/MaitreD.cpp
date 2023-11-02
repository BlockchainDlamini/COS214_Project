/*@file MaitreD.cpp
@brief contains the MaitreD class
    *which inherits from the Waiter class
    *and creates a MaitreD
*/
#include "MaitreD.h"

MaitreD::MaitreD(string name, shared_ptr<Floor> floor) {
    this->name=name;
    this->floorobj = floor;


    // employ waiters
    // shared_ptr<RegularWaiter> newWaiter1 = RegularWaiter::createRegularWaiter(1, vector<int>{1, 2, 3}, floor);
    // shared_ptr<RegularWaiter> newWaiter2 = RegularWaiter::createRegularWaiter(2, vector<int>{4, 5, 6}, floor);
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
    cout<<"The MaitreD is calling floorobj->seatCustomer."<<endl;
    floorobj->seatCustomer(customers);
}

void MaitreD::customersLeft(int tableNum){
    cout<<"The MaitreD is calling floorobj->seatCustomer."<<endl;
    floorobj->customersLeft(tableNum);
}
