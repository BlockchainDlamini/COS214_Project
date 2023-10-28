#include "Customer.cpp"
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
    for (int i = 0; i < 10; i++)
    {
        test->createOrder(i, commands);
    }
    return 0;
}