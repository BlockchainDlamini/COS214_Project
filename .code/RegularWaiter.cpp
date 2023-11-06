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

    for (auto& waiter : waiters)
    {
        vector<int> tablesOfWaiter = waiter->getAssignedTables();
        for (unsigned int r = 0; r < tablesOfWaiter.size(); r++)
        {
            if (tableId == tablesOfWaiter[r])
            {
                //cout << "Waiter: " << waiter->getWaiterID() << " is being called to table : " << tableId << endl;
                return waiter;
            }
        }
    }
    return nullptr;
}

void RegularWaiter::takeOrder(int tableId)
{
    //cout << "in the waiter::takeOrder class" << endl;
    //cout << "table: " << tableId << endl;

    shared_ptr<RegularWaiter> waiter = waiterResponsible(tableId);

    if (waiter)
    {
        //cout << "Waiter: " << waiter->getWaiterID() << " is taking the order for table number: " << tableId << endl;
    }

    //ERROR
     this->tableID = tableId;


    // iterate through this waiters tables' customers

    // get the correct table from the floor
    //cout << "calling getTableAt()" << endl;
    shared_ptr<table> table = floorObject->getTableAt(tableId);
    //cout << "call success" << endl;

    //cout << "call getCustomers()" << endl;
    vector<std::shared_ptr<Customer>> customers = table->getCustomers();
    //cout << "call success" << endl;

    vector<pair<int, shared_ptr<Order>>> vectorForKitchen;
    //pair<int, vector<pair<int, shared_ptr<Order>>>> ordersForATable;

    for (auto customer : customers) {
        // null check
        if (customer != NULL) {
            auto val = customer->getOrders();
            for (auto it = val.begin(); it != val.end(); it++)
            {
                vectorForKitchen.push_back(*it);
            }
        }
    }

    forKitchen = std::make_pair(Id, vectorForKitchen);

    setOperation("sendToKitchen");
    changed();
}

pair<int, vector<pair<int, shared_ptr<Order>>>> RegularWaiter::getForKitchen()
{
    return forKitchen;
}

void RegularWaiter::takeOrderToTable(std::vector<std::shared_ptr<pair<int, std::shared_ptr<Pizza>>>> order, int tableId)
{
    std::vector<std::shared_ptr<Pizza>> pizzas;
    for (const auto& orderItem : order) {
        if (orderItem) {
            std::shared_ptr<Pizza> pizza = orderItem->second;
            if (pizza) {
                pizzas.push_back(pizza);
            }
        }
    }
    this->pizzasForTable = pizzas;
    this->tableID = tableId;

    // extracted ints
    std::vector<int> ints;
    for (const auto& pairPtr : order) {
        int intValue = pairPtr->first;
        ints.push_back(intValue);
    }

    //cout << "the waiter is in takeOrderToTable()" << endl;
    // get table with the customers sitting there
    shared_ptr<table> table = floorObject->getTableAt(tableID);
    vector<shared_ptr<Customer>> customers = table->getCustomers();

 /*   for (auto customer:customers) {
        customer->receiveOrder(pizzas);
    }*/

    for (unsigned int r = 0; r < pizzas.size(); r++)
    {
        cout << "Customer: " << ints[r] << " received order: ";
        cout << pizzas[r]->getDescription();
        cout << endl;
        //receiveOrder
    }

    for (auto customer:customers) {

        vector<std::shared_ptr<Pizza>> pizzaForSpecificCustomer;
        for (unsigned int r = 0; r < pizzas.size(); r++)
        {
            if (customer->getID() == ints[r]) {
                pizzaForSpecificCustomer.push_back(pizzas[r]);
            }
        }

        customer->receiveOrder(pizzaForSpecificCustomer);
    }


}

// CHANGE
void RegularWaiter::payBill(int tableId, vector<std::shared_ptr<pair<int, std::shared_ptr<Pizza>>>> order)
{

    //cout << "NEW CALL" << endl;

    shared_ptr<RegularWaiter> waiter = waiterResponsible(tableId);

    if (waiter)
    {
        cout << "Waiter: " << waiter->getWaiterID() << " is preparing the bill for table: " << tableId << endl;
    }
    // use mediator to
    // pizza obj will have the price - not the order

    // get full total of the bill
    float orderAmount = 0.0;
    shared_ptr<table> table = floorObject->getTableAt(tableId);
    vector<shared_ptr<Customer>> customers = table->getCustomers();


    std::vector<std::shared_ptr<Pizza>> pizzas;
    for (const auto& orderItem : order) {
        if (orderItem) {
            std::shared_ptr<Pizza> pizza = orderItem->second;
            if (pizza) {
                pizzas.push_back(pizza);
            }
        }
    }
    this->pizzasForTable = pizzas;


    for (const auto& pizza : pizzasForTable)
    {
        orderAmount += pizza->getPrice();
    }

    // terminal get if split
    string splitChoice;

    std::cout << "\033[47;30mWould you like to split the bill? (yes/no)\033[0m" << std::endl;
    cin >> splitChoice;

    // ----------------------------------- if splitting bill -----------------------------------
    if (splitChoice == "yes")
    {
        // then the head of the table must pay

        int count = 0;
        for (const auto& customer : customers)
        {

            orderAmount = pizzasForTable[count]->getPrice();
            std::string orderAmountStr = std::to_string(orderAmount);

            float floatValue = std::stof(orderAmountStr);
            cout << "\033[35mAmount payable for customer " << customer->getID() << " is: " << pizzasForTable[count]->getPrice() << " ZAR\033[0m" << endl;

            string tabChoice;

            std::cout << "\033[47;30mWould you like to put the bill on your tab? (yes/no)\033[0m" << std::endl;

            cin >> tabChoice;

            if (tabChoice == "yes")
            {
                if (customer->isLoyal())
                {
                    cout << "\033[35mPutting the bill of amount: " << orderAmount << " onto your tab.\033[0m" << endl;
                    customer->payBill( 'T',floatValue, false);
                }
                else
                {
                    cout << "\033[35m You do not yet have a tab, so lets make you one!\033[0m" << endl;
                    customer->startTab();
                    cout << "\033[35mPutting the bill of amount: " << orderAmount << " onto your tab.\033[0m" << endl;
                    customer->payBill('T',floatValue, false);
                }
            }
            else
            {
                cout << "\033[35mPaying the bill of amount: " << orderAmount << "\033[0m" << endl;
                customer->payBill('P', floatValue, false);
            }
            // SEG

            count++;
        }
    }
    else
    {
        // ----------------------------------- if NOT splitting bill -----------------------------------
        cout << "Full amount payable: " << orderAmount << endl;

        std::string orderAmountStr = std::to_string(orderAmount);

        float floatValue = std::stof(orderAmountStr);

        cout << "Customer " << customers[0]->getID() << " amount due: " << orderAmount << endl;
        customers[0]->payBill('P',floatValue, false); // orderAmount
    }

    customers[0]->payBill('P', 0.0, true);


    //leave();
}



void RegularWaiter::leave()
{
    setOperation("LEAVE");
    changed();
    cout << "Customer has left" << endl;
}



string RegularWaiter::get()
{
    return operation;
}

//void RegularWaiter::changed()
//{
//     this->notify();
//}

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