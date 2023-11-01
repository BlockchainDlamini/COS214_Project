#include "Customer.cpp"
#include "Happy.cpp"
#include "Pizza.cpp"
#include "Order.cpp"
#include "DinnerDone.cpp"
#include "Preorder.cpp"
#include "Satisfied.cpp"
#include "Frustrated.cpp"
#include "gameElement.cpp"
#include "OrderReceived.cpp"
#include "OrderMemento.cpp"
#include "MenuItemCommand.cpp"
#include "Tab.cpp"
#include "EmotionState.cpp"
#include "Disgruntaled.cpp"
#include "OrderProcessState.cpp"
#include "Waiting.cpp"

int main()
{
     shared_ptr<Customer> test = make_shared<Customer>(1000, 1);
     shared_ptr<Pizza> pizza = make_shared<Pizza>();

     // Customer getting seated and starting his tab
     test->beSeated(1);
     test->startTab();

     // Testing the Customer and Waiter interaction
     cout << test->printCustomer() << endl;
     test->talkToWaiter();
     test->createOrder();
     cout << test->printCustomer() << endl;
     test->receiveOrder(pizza);
     cout << test->printCustomer() << endl;
     test->payBill('P', 100);
     cout << test->printCustomer() << endl;
     cout << test->printBill() << endl;

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
     test->changedOrderProcessState();

     // the Emotion changes, starting from Disgruntaled
     cout << "Starting From Disgruntaled" << endl;
     test->setEmotionState(std::make_shared<Disgruntaled>());
     test->changeMood();
     cout << test->printCustomer() << endl;
     test->changeMood();
     cout << test->printCustomer() << endl
          << endl;

     cout << "Starting the Order Process" << endl;
     test->setOrderProcessState(std::make_shared<Preorder>());
     test->changedOrderProcessState();

     // Paying the bill
     test->requestBill();
     test->payBill('P', 100); // within the budget
     cout << test->printBill() << endl;

     // Paying the bill
     test->requestBill();
     test->payBill('T', 100);
     cout << test->printBill() << endl;

     cout << test->getTab()->listOutstandingOrders() << endl;
     return 0;
}
