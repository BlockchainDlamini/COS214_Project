/*@file RegularWaiter.cpp
@brief contains the RegularWaiter class
    *which inherits from the Waiter class
    *and creates a RegularWaiter
*/
#include "RegularWaiter.h"

std::vector<shared_ptr<RegularWaiter>> RegularWaiter::waiters;

RegularWaiter::RegularWaiter(int Id, std::vector<int> assignedTables, shared_ptr<Floor> floorObj)
{
    this->Id = Id;
    this->assignedTables = assignedTables;
    this->floorObject = floorObj;
}

shared_ptr<RegularWaiter> RegularWaiter::createRegularWaiter(int Id, std::vector<int> assignedTables, shared_ptr<Floor> floorObj)
{
    auto waiter = make_shared<RegularWaiter>(Id, assignedTables, floorObj);
    waiters.push_back(waiter);
    return waiter;
}

int RegularWaiter::getWaiterID()
{
    return Id;
}

shared_ptr<RegularWaiter> RegularWaiter::waiterResponsible(int tableId)
{

    for (auto &waiter : waiters)
    {
        vector<int> tablesOfWaiter = waiter->getAssignedTables();
        for (unsigned int r = 0; r < tablesOfWaiter.size(); r++)
        {
            if (tableId == tablesOfWaiter[r])
            {
                cout << "Waiter: " << waiter->getWaiterID() << " is being called to table : " << tableId << endl;
                return waiter;
            }
        }
    }
    return nullptr;
}

void RegularWaiter::takeOrder(int tableId)
{

    shared_ptr<RegularWaiter> waiter = waiterResponsible(tableId);

    if (waiter)
    {
        cout << "Waiter: " << waiter->getWaiterID() << " is taking the order for table number: " << tableId << endl;
    }

    this->tableID = tableId;
    // iterate through this waiters tables' customers

    // get the correct table from the floor
    shared_ptr<table> table = floorObject->getTable(tableId);

    vector<shared_ptr<Customer>> customers = table->getCustomers();

    std::vector<std::pair<int, std::shared_ptr<Order>>> vectorForKitchen;

    for (auto customer : customers) {
        // null check
        if (customer != NULL) {
            vectorForKitchen.push_back(std::make_pair(customer->getID(), customer->getOrders()));
        }
    }

    forKitchen = std::make_pair(Id, vectorForKitchen);

    setOperation("sendToKitchen");
    changed();

}

pair<int, vector<shared_ptr<Order>>> RegularWaiter::getForKitchen()
{
    return forKitchen;
}

// pair<int, std::vector<std::shared_ptr<pair<int, std::shared_ptr<Pizza>>>>>
// void RegularWaiter::takeOrderToTable(vector<shared_ptr<Pizza>> pizzasForTable)
void RegularWaiter::takeOrderToTable(std::vector<std::shared_ptr<pair<int, std::shared_ptr<Pizza>>>> order)
{
    // extracted pizzas
    std::vector<std::shared_ptr<Pizza>> pizzas = order.second;
    this->pizzasForTable = pizzas;

    // extracted ints
    std::vector<int> ints;
    for (const auto& pairPtr : order) {
        int intValue = pairPtr->first;
        ints.push_back(intValue);
    }


    cout << "the waiter is in takeOrderToTable()" << endl;
    // get table with the customers sitting there
    shared_ptr<table> table = floorObject->getTable(tableID);
    vector<shared_ptr<Customer>> customers = table->getCustomers();


    for (unsigned int r = 0; r < pizzas.size(); r++)
    {
        cout << "Customer: " << ints[r] << " received order: ";
        pizzas[r]->getDescription();
    }

    setOperation("Food taken to table");
    changed();
}

// CHANGE
void RegularWaiter::payBill(int tableId)
{

    shared_ptr<RegularWaiter> waiter = waiterResponsible(tableId);

    if (waiter)
    {
        cout << "Waiter: " << waiter->getWaiterID() << " is preparing the bill for table: " << tableId << endl;
    }
    // use mediator to
    // pizza obj will have the price - not the order

    // get full total of the bill
    int orderAmount;
    shared_ptr<table> table = floorObject->getTableAt(tableID);
    vector<shared_ptr<Customer>> customers = table->getCustomers();

    for (const auto &pizza : pizzasForTable)
    {
        orderAmount += pizza->getPrice();
    }

    // terminal get if split
    string splitChoice;

    cout << "Would you like to split the bill? (yes/no): ";
    cin >> splitChoice;

    // ----------------------------------- if splitting bill -----------------------------------
    if (splitChoice == "yes")
    {
        // then the head of the table must pay

        int count = 0;
        for (const auto &customer : customers)
        {

            orderAmount = pizzasForTable[count]->getPrice();
            std::string orderAmountStr = std::to_string(orderAmount);

            float floatValue = std::stof(orderAmountStr);
            cout << "Amount payable for customer " << customer->getID() << " is: " << pizzasForTable[count]->getPrice() << " ZAR";

            string tabChoice;

            cout << "Would you like to put the bill on your tab? (yes/no): ";
            cin >> tabChoice;

            if (tabChoice == "yes")
            {
                if (customer->isLoyal())
                {
                    cout << "Putting the bill of amount: " << orderAmount << " onto your tab.";
                    customer->payBill(floatValue, 'T');
                }
                else
                {
                    customer->startTab();
                    cout << "Putting the bill of amount: " << orderAmount << " onto your tab.";
                    customer->payBill(floatValue, 'T');
                }
            }
            else
            {
                cout << "Paying the bill of amount: " << orderAmount << endl;
                customer->payBill(floatValue, 'P');
            }
            // SEG

            count++;
        }
    }
    else
    {
        // ----------------------------------- if NOT splitting bill -----------------------------------
        cout << "Full amount payable: " << orderAmount;

        std::string orderAmountStr = std::to_string(orderAmount);

        float floatValue = std::stof(orderAmountStr);

        cout << "Customer " << customers[0]->getID() << " amount due: " << orderAmount << endl;
        customers[0]->payBill(floatValue, 'P'); // orderAmount
    }
}

string RegularWaiter::get()
{
    return operation;
}

void RegularWaiter::changed()
{
    // this->notify();
}

void RegularWaiter::setOperation(string op)
{
    this->operation = op;
}

vector<int> RegularWaiter::getAssignedTables()
{
    return this->assignedTables;
}

void RegularWaiter::getPizzas()
{
}