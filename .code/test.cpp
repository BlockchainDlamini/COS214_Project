#include "Customer.cpp"
#include "Happy.cpp"
#include "Order.cpp"
#include "DinnerDone.cpp"
#include "Preorder.cpp"
#include "Satisfied.cpp"
#include "Frustrated.cpp"
#include "gameElement.cpp"
#include "OrderReceived.cpp"
#include "OrderMemento.cpp"
#include "MenuItemOrderCommand.cpp"
#include "Tab.cpp"
#include "EmotionState.cpp"
#include "Disgruntaled.cpp"
#include "OrderProcessState.cpp"
#include "Waiting.cpp"

int main()
{
    vector<shared_ptr<MenuItemOrderCommand>> commands;
    shared_ptr<Customer> test = make_shared<Customer>(1000, 1);
    test->beSeated(1);
    test->startTab();
    for (int i = 0; i < 5; i++)
    {
        commands.push_back(make_shared<MenuItemOrderCommand>());
    }
    for (int i = 1; i <= 10; i++)
    {
        test->createOrder(i, commands);
    }
    // the Emotion changes, starting from happy
    cout << "Starting From Happy" << endl;
    test->setEmotionState(std::make_shared<Happy>());
    test->changeMood();
    cout << test->printCustomer() << endl;
    test->changeMood();
    cout << test->printCustomer() << endl
         << endl;

    // the Emotion changes, starting from Frustrated
    cout << "Starting From Frustrated" << endl;
    test->setEmotionState(std::make_shared<Frustrated>());
    test->changeMood();
    cout << test->printCustomer() << endl;
    test->changeMood();
    cout << test->printCustomer() << endl
         << endl;

    // the Emotion changes, starting from Satisfied
    cout << "Starting From Satisfied" << endl;
    test->setEmotionState(std::make_shared<Satisfied>());
    test->changeMood();
    cout << test->printCustomer() << endl;
    test->changeMood();
    cout << test->printCustomer() << endl
         << endl;

    // the Emotion changes, starting from Disgruntaled
    cout << "Starting From Disgruntaled" << endl;
    test->setEmotionState(std::make_shared<Disgruntaled>());
    test->changeMood();
    cout << test->printCustomer() << endl;
    test->changeMood();
    cout << test->printCustomer() << endl
         << endl;

    // cout << "Starting the Order Process" << endl;
    // test->setOrderProcessState(std::make_shared<Preorder>());
    // test->changedOrderProcessState();
    // test->changedOrderProcessState();
    // test->changedOrderProcessState();
    // test->changedOrderProcessState();
    // Paying the bill
    test->hasBill = true;
    test->payBill('g', 0);
    test->payBill('P', 100);  // within the budget
    test->payBill('P', 2000); // outside the budget, overpaid
    test->payBill('T', 100);
    test->payBill('T', 2000);
    cout << test->printBill() << endl;

    // Paying the bill
    test->hasBill = false;
    test->payBill('g', 0);
    test->payBill('P', 100);  // within the budget
    test->payBill('P', 2000); // outside the budget, overpaid
    test->payBill('T', 100);
    test->payBill('T', 2000);
    cout << test->printBill() << endl;
    return 0;
}
