#include <memory>
#include <vector>
class Order;
#include <string>
#include <iostream>
using namespace std;

class Mediator;
class gameElement: public enable_shared_from_this<gameElement> {
public:
    gameElement();
    gameElement(const std::shared_ptr<Mediator> &myGameEngine);
    gameElement(const std::shared_ptr<Mediator> &myGameEngine,int id);
    virtual ~gameElement();
    void setGameEngine(const std::shared_ptr<Mediator> &gameEngine);
    void setMyGameEngine(const shared_ptr<Mediator> &myGameEngine);
    int getMyId() const;
    void setMyId(int myId);

    //Communication functions
    virtual void changed();
    virtual string get();
    virtual void setOperation(string op);
protected:
    std::shared_ptr<Mediator> gameEngine;
    int myID;
    string operation;
};

class Customer : public enable_shared_from_this<Customer>, public gameElement
{
private:
    int ID;
    int bankAccountAmount;
    int tableNum;
    string name;

public:
    // Customer(string name){this->name = name;};
    Customer();
    Customer(int id, int tableNum);

    // Customer(int bankAccountAmount, int tableNum);
    // Customer(std::shared_ptr<EmotionState> mood, int tableNum);

    void payBill(float amount, char c); // if the passed in char is P, the customer will pay. If it is T the customer wants to add to the Tab.
    bool isLoyal();
    void startTab();
    void payTab();
    string getID(){
        // cout<<"customer id: " << ID <<endl;
        // cout<<"ID: " << ID <<endl;
        return to_string(bankAccountAmount);
    }
    int getTableNum(){
        // cout<<"customer id: " << ID <<endl;
        // cout<<"ID: " << ID <<endl;
        return tableNum;
    }
    std::vector<std::shared_ptr<Order>> getOrders(){
        cout<<"inside customer getOrders()"<<endl;
        shared_ptr<Order> customer1 = make_shared<Order>(200);
        shared_ptr<Order> customer2 = make_shared<Order>(400);

        vector<shared_ptr<Order>> orders;
        orders.push_back(customer1);
        orders.push_back(customer2);
            
        return orders;
    };

    ~Customer();
};

class Floor : public gameElement {
private:
    int sideLength, tableSpace;

public:
    Floor();
    shared_ptr<table> getTable(int){
        cout<<"in func getTable"<<endl;
        return std::make_shared<table>(2);
    };
    Floor(int);
    void seatCustomer(std::vector<std::shared_ptr<Customer>> customers);
    void customersLeft(int id){
        cout<<"left"<<endl;
    }
    virtual void changed(){};
    virtual std::string set(std::string op){return "";};
    virtual void getOperation(){};
    ~Floor();
};

class Order;

class Customer : public enable_shared_from_this<Customer>, public gameElement
{
private:
    int ID;
    int bankAccountAmount;
    int tableNum;
    string name;

public:
    // Customer(string name){this->name = name;};
    Customer();
    Customer(int id, int tableNum);

    // Customer(int bankAccountAmount, int tableNum);
    // Customer(std::shared_ptr<EmotionState> mood, int tableNum);

    void payBill(float amount, char c); // if the passed in char is P, the customer will pay. If it is T the customer wants to add to the Tab.
    bool isLoyal();
    void startTab();
    void payTab();
    string getID(){
        // cout<<"customer id: " << ID <<endl;
        // cout<<"ID: " << ID <<endl;
        return to_string(bankAccountAmount);
    }
    int getTableNum(){
        // cout<<"customer id: " << ID <<endl;
        // cout<<"ID: " << ID <<endl;
        return tableNum;
    }
    std::vector<std::shared_ptr<Order>> getOrders(){
        cout<<"inside customer getOrders()"<<endl;
        shared_ptr<Order> customer1 = make_shared<Order>(200);
        shared_ptr<Order> customer2 = make_shared<Order>(400);

        vector<shared_ptr<Order>> orders;
        orders.push_back(customer1);
        orders.push_back(customer2);
            
        return orders;
    };

    ~Customer();
};

class Order : public enable_shared_from_this<Order>
{
private:                                                /**< The total price of the order. */
    int orderID;                                                /**< The unique identifier for the order.*/
public:
    Order(int orderID);
};

class Pizza : gameElement {
    public:
        Pizza(string name, int price){
            cout << "in pizza " << endl;
            name=name;
            price=price;
        };
        int getTotal(){
            // cout << "in pizza getTotal" << endl;
            return price;
        };
        void toString(){
            cout<<"in pizza tostring()"<<endl;
        }
        // string toString(){
        //     return name;
        // }

        int price;
        string name;

};

class Waiter : public enable_shared_from_this<Waiter>, public gameElement {
public:
    virtual string get() = 0;

    virtual void changed() = 0;

    virtual void setOperation(string op) = 0;

    virtual ~Waiter() {}
};

class RegularWaiter :  public enable_shared_from_this<RegularWaiter>, public Waiter {
public:

    RegularWaiter(int Id, std::vector<int> assignedTables, shared_ptr<Floor> floorObj);

    void takeOrder(int tableId);

    std::pair<int, std::vector<std::shared_ptr<Order>>> getForKitchen();

    void takeOrderToTable(std::vector<std::shared_ptr<Pizza>> pizzasForTable);

    void payBill(int tableId);

    virtual string get();

    void changed();

    void setOperation(string op);

    vector<int> getAssignedTables();

    void getPizzas();

    static shared_ptr<RegularWaiter> createRegularWaiter(int Id, std::vector<int> assignedTables, shared_ptr<Floor> floorObj);

    std::shared_ptr<RegularWaiter> waiterResponsible(int tableId);

    int getWaiterID();


private:
    shared_ptr<Floor> floorObject;
    std::vector<shared_ptr<Pizza>> pizzasForTable;
    int Id;
    std::vector<int> assignedTables;
    int tableID;
    std::vector<shared_ptr<Order>> ordersForATable;
    std::pair<int, std::vector<std::shared_ptr<Order>>> forKitchen;


    static std::vector<shared_ptr<RegularWaiter>> waiters;
};


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

pair<int, vector<shared_ptr<Order>>> RegularWaiter::getForKitchen()
{
    return forKitchen;
}

vector<int> RegularWaiter::getAssignedTables()
{
    return this->assignedTables;
}




TEST(RegularWaiterTest, CreateRegularWaiter) {
    std::vector<int> assignedTables = {1, 2, 3};
    auto floorObj = std::make_shared<Floor>();

    auto waiter = RegularWaiter::createRegularWaiter(1, assignedTables, floorObj);
    EXPECT_EQ(waiter->getWaiterID(), 1);
    EXPECT_EQ(waiter->getAssignedTables(), assignedTables);
}

TEST(RegularWaiterTest, WaiterResponsible) {
    std::vector<int> assignedTables1 = {1, 2, 3};
    std::vector<int> assignedTables2 = {4, 5, 6};
    auto floorObj = std::make_shared<Floor>(); // You need to define the Floor class

    auto waiter1 = RegularWaiter::createRegularWaiter(1, assignedTables1, floorObj);
    auto waiter2 = RegularWaiter::createRegularWaiter(2, assignedTables2, floorObj);

    auto responsibleWaiter = waiter1->waiterResponsible(2);
    EXPECT_EQ(responsibleWaiter->getWaiterID(), 1);

    responsibleWaiter = waiter2->waiterResponsible(6);
    EXPECT_EQ(responsibleWaiter->getWaiterID(), 2);

    responsibleWaiter = waiter1->waiterResponsible(7);
    EXPECT_EQ(responsibleWaiter, nullptr);
}

// Add more test cases for other methods as needed

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
