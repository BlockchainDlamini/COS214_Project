#include "regularWaiter.h"

regularWaiter::regularWaiter(int Id, vector<shared_ptr<table>> assignedTables) {
    this->Id=Id;
    this->assignedTables=assignedTables;
}

void regularWaiter::assignTable(shared_ptr<table> table)
{
    tables.push_back(table);
    std::cout << Id << " has been assigned table number " << table->getNum() << std::endl;
    //ADD getNum() to table class
}


void regularWaiter::takeOrder(int tableId) {
    this->tableID = tableId;
    // iterate through this waiters tables' customers
    string command = getOperation();

    if(command == "make Order"){ // then proceed to take the order

        for (const auto& table : assignedTables) {
            // only get the orders of the specific table that wants to order
            if (table->getTableId() == tableId) {

                vector<shared_ptr<Customer>> customers = table->getCustomers();
                for (const auto& customer : customers) {
                    vector<Order> customerOrders = customer->getOrders();
                    ordersForATable.insert(ordersForATable.end(), customerOrders.begin(), customerOrders.end());
                }
                
            }
        }

        // then send the vector of orders (with waiter id) to the kitchen - to the mediator
        // Mediator
        forKitchen = make_pair{Id, ordersForATable};

        setOperation("sendToKitchen");
        changed();
    }

}


pair <int, vector<shared_ptr<orders>>> regularWaiter::getForKitchen(){
    return forKitchen;
}


void regularWaiter::takeOrderToTable(vector<shared_ptr<pizza>> pizzasForTable) {
    this->pizzasForTable = pizzasForTable;
    // iterate through this waiters tables' customers
    string command = getOperation();

    if(command == "Take to Customer"){ // then proceed to hand out the order

        for (const auto& table : assignedTables) {
            // only get the orders of the specific table that wants to order
            if (table->getTableId() == this->tableID) {

                vector<shared_ptr<Customer>> customers = table->getCustomers();
                for (int r = 0; r < customers.size(); r++) {

                    cout << "Customer: " << customers[r]->getName() << " received order." << endl;

                    // pizza.tostring();
                    // cout << pizza->getOrders() << endl;

                }
                
            }
        }

    }

} 

void::regularWaiter::payBill(){
    // use mediator to
    // pizza obj will have the price - not the order


    // get full total of the bill
    int orderAmount;
    for (const auto& table : assignedTables) {
        if (table->getTableId() == this->tableID) {
            vector<shared_ptr<Customer>> customers = table->getCustomers();
            // iterate through
            // for (const auto& customer : customers) {
            //     orderAmount += customer->getOrders()->orderAmount();
            // }
            for (const auto& pizza : pizzasForTables) {
                orderAmount += pizza->getTotal();
            }    
        }
    }


    // terminal get if split
    string splitChoice;

    cout << "Would you like to split the bill? (yes/no): ";
    cin >> splitChoice;

    // ----------------------------------- if splitting bill -----------------------------------
    if(splitChoice == "yes"){
        // then the head of the table must pay
        cout << "Full amount payable: " << orderAmount;
        for (const auto& table : assignedTables) {
            if (table->getTableId() == this->tableID) {
                vector<shared_ptr<Customer>> customers = table->getCustomers();

                for (const auto& customer : customers) {

                    string tabChoice;

                    cout << "Would you like to put the bill on your tab? (yes/no): ";
                    cin >> tabChoice;

                    if(tabChoice == "yes"){
                        if(customer->isLoyal()){
                            cout << "Putting the bill of amount: " << orderAmount << " onto your tab.";
                            customer->payBill('T');
                        }
                        else{
                            customer->startTab();
                            cout << "Putting the bill of amount: " << orderAmount << " onto your tab.";
                            customer->payBill('T');
                        }
                        
                    }
                    else{
                        cout << "Paying the bill of amount: " << orderAmount << endl;
                        customer->payBill('P');
                    }
                }

            }
        }
    }
    else{
        // ----------------------------------- if NOT splitting bill -----------------------------------
        int orderAmount;
        for (const auto& table : assignedTables) {

            if (table->getTableId() == this->tableID) {

                vector<shared_ptr<Customer>> customers = table->getCustomers();

                cout<< "Customer " << customer->getID() << " amount due: " << customer->getOrders()->orderAmount() << endl;
                customer[0]->pay('P');// orderAmount
                        
            }
        }
    }
    
    
}

void regularWaiter::get() {
}

void regularWaiter::changed() {
}

void regularWaiter::set() {
}
