#include "regularWaiter.h"

regularWaiter::regularWaiter(int Id, vector<shared_ptr<table>> assignedTables, Floor floor) {
    this->Id=Id;
    this->assignedTables=assignedTables;
    this->floor = floor;
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

        //get the correct table from the floor
        shared_ptr<table> table = floor.getTable(tableId);

        vector<shared_ptr<Customer>> customers = table->getCustomers();
        for (const auto& customer : customers) {
            vector<Order> customerOrders = customer->getOrders();
            ordersForATable.insert(ordersForATable.end(), customerOrders.begin(), customerOrders.end());
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

        shared_ptr<table> table = floor.getTable(tableId);

        vector<shared_ptr<Customer>> customers = table->getCustomers();
        for (int r = 0; r < customers.size(); r++) {

            cout << "Customer: " << customers[r]->getName() << " received order: " << pizzasForTable[r].toString() << endl;

        }

    }

} 

void::regularWaiter::payBill(){
    // use mediator to
    // pizza obj will have the price - not the order

    // get full total of the bill
    int orderAmount;
    shared_ptr<table> table = floor.getTable(tableId);
    vector<shared_ptr<Customer>> customers = table->getCustomers();
            // iterate through
            // for (const auto& customer : customers) {
            //     orderAmount += customer->getOrders()->orderAmount();
            // }
    for (const auto& pizza : pizzasForTables) {
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

                orderAmount = pizza[count]->getTotal();
                float floatValue = std::stof(orderAmount);

                cout << "Amount payable for " << customer->getID() << " is: " << pizza[count]->getTotal() << " ZAR";

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

        float floatValue = std::stof(orderAmount);

        cout<< "Customer " << customer->getID() << " amount due: " << customer->getOrders()->orderAmount() << endl;
        customer[0]->pay(floatValue, 'P');// orderAmount

    }
    
    
}

void regularWaiter::get() {
    return *this;
}

void regularWaiter::changed() {
}

void regularWaiter::set() {
}
