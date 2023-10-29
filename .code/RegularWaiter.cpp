#include "RegularWaiter.h"

RegularWaiter::RegularWaiter(int Id, std::vector<int> assignedTables, Floor floorObj)
{
    this->Id=Id;
    this->assignedTables=assignedTables;
    this->floorObject = floorObj;
}

// RegularWaiter::RegularWaiter(int Id, std::vector<int> assignedTables, Floor floorObj)
//     : floorObject(floorObj), Id(Id), assignedTables(assignedTables) {
// }


void RegularWaiter::assignTable(shared_ptr<table> table)
{
    // tables.push_back(table);
    // std::cout << Id << " has been assigned table number " << table->getNum() << std::endl;
    //ADD getNum() to table class
}


void RegularWaiter::takeOrder(int tableId) {
    this->tableID = tableId;
    // iterate through this waiters tables' customers
    string command = get();

    if(command == "make Order"){ // then proceed to take the order

        //get the correct table from the floor
        shared_ptr<table> table = floorObject.getTable(tableId);

        vector<shared_ptr<Customer>> customers = table->getCustomers();
        for (const auto& customer : customers) {
            
            vector<std::shared_ptr<Order>> customerOrders = customer->getOrders();
            ordersForATable.insert(ordersForATable.end(), customerOrders.begin(), customerOrders.end());
        }

        // then send the vector of orders (with waiter id) to the kitchen - to the mediator
        // Mediator
        forKitchen = std::make_pair(Id, ordersForATable);

        setOperation("sendToKitchen");
        changed();
    }

}


pair <int, vector<shared_ptr<Order>>> RegularWaiter::getForKitchen(){
    return forKitchen;
}


void RegularWaiter::takeOrderToTable(vector<shared_ptr<Pizza>> pizzasForTable) {
    this->pizzasForTable = pizzasForTable;
    // iterate through this waiters tables' customers
    string command = get();

    if(command == "Take to Customer"){ // then proceed to hand out the order

        shared_ptr<table> table = floorObject.getTable(tableID);

        vector<shared_ptr<Customer>> customers = table->getCustomers();
        for (int r = 0; r < customers.size(); r++) {

            cout << "Customer: " << customers[r]->getID() << " received order: ";
            pizzasForTable[r]->toString();
            cout << endl;

            // std::shared_ptr<Pizza> pizzaPtr = pizzasForTable[r];

            // if (pizzaPtr) {
            //     pizzaPtr->toString();
            // }

        }

    }

} 

void::RegularWaiter::payBill(){
    // use mediator to
    // pizza obj will have the price - not the order

    // get full total of the bill
    int orderAmount;
    shared_ptr<table> table = floorObject.getTable(tableID);
    vector<shared_ptr<Customer>> customers = table->getCustomers();
            // iterate through
            // for (const auto& customer : customers) {
            //     orderAmount += customer->getOrders()->orderAmount();
            // }
    for (const auto& pizza : pizzasForTable) {
        orderAmount += pizza->getTotal();
    }  

    // terminal get if split
    string splitChoice;

    cout << "Would you like to split the bill? (yes/no): ";
    cin >> splitChoice;

    // ----------------------------------- if splitting bill -----------------------------------
    if(splitChoice == "yes"){
        // then the head of the table must pay

            int count = 0;
            for (const auto& customer : customers) {

                orderAmount = pizzasForTable[count]->getTotal();
                std::string orderAmountStr = std::to_string(orderAmount);

                float floatValue = std::stof(orderAmountStr);
                cout << "Amount payable for " << customer->getID() << " is: " << pizzasForTable[count]->getTotal() << " ZAR";

                string tabChoice;

                cout << "Would you like to put the bill on your tab? (yes/no): ";
                cin >> tabChoice;

                if(tabChoice == "yes"){
                    if(customer->isLoyal()){
                        cout << "Putting the bill of amount: " << orderAmount << " onto your tab.";
                        customer->payBill(floatValue, 'T');
                    }
                    else{
                        customer->startTab();
                        cout << "Putting the bill of amount: " << orderAmount << " onto your tab.";
                        customer->payBill(floatValue, 'T');
                    }
                        
                }
                else{
                    cout << "Paying the bill of amount: " << orderAmount << endl;
                    customer->payBill(floatValue, 'P');
                }

                count++;
            }
            
    }
    else{
        // ----------------------------------- if NOT splitting bill -----------------------------------
        cout << "Full amount payable: " << orderAmount;

        std::string orderAmountStr = std::to_string(orderAmount);

        float floatValue = std::stof(orderAmountStr);

        cout<< "Customer " << customers[0]->getID() << " amount due: " << orderAmount << endl;
        customers[0]->payBill(floatValue, 'P');// orderAmount

    }
    
    
}

string RegularWaiter::get() {
    return operation;
}

void RegularWaiter::changed() {
    // this->notify();
}

void RegularWaiter::setOperation(string op) {
    this->operation = op;
}


