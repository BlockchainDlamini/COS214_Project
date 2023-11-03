#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "EmotionState.h"
#include "Disgruntaled.h"
#include "Happy.h"
#include "Satisfied.h"
#include "Frustrated.h"
#include "OrderProcessState.h"
#include "Preorder.h"
#include "Order.h"
#include "gameElement.h"
#include "Pizza.h"
#include "Tab.h"
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

/**
 * @class Customer
 * @brief Represents a customer in a restaurant with various states and actions.
 */
class Customer : public gameElement, public enable_shared_from_this<Customer>
{
private:
    int ID;
    string tabID;                                                              /**< The unique identifier of the customer's order. */
    std::shared_ptr<EmotionState> mood = make_shared<Happy>();                 /**< The emotional state of the customer. */
    std::shared_ptr<OrderProcessState> orderProcess = make_shared<Preorder>(); /**< The current order process state. */
    float bankAccountAmount;                                                   /**< The amount of money in the customer's bank account. */
    std::shared_ptr<Tab> tab = nullptr;                                        /**< The customer's tab for keeping track of orders. */
    int tableNum;
    float total;                                /**< The table number where the customer is seated. */
    std::shared_ptr<Pizza> pizza = nullptr;     /**< The pizza ordered by the customer. */
    std::vector<std::shared_ptr<Order>> orders; /**< A vector of customer's orders. */
    shared_ptr<Kitchen> kitchen = make_shared<ManagerChef>();

public:
    /**
     * @brief Constructor for a Customer.
     * @param id The unique identifier of the customer.
     * @param tableNum The table number where the customer is seated.
     */
    Customer(int id, int bankAccountAmount);

    /**
     * @brief Constructor for a Customer with an initial emotional state.
     * @param mood The initial emotional state of the customer.
     * @param tableNum The table number where the customer is seated.
     */
    Customer(std::shared_ptr<EmotionState> mood, int bankAccountAmount);
    Customer(int bankAccount);

    /**
     * @brief Change the emotional state of the customer.
     */

    void setManager(shared_ptr<Kitchen>);
    void changeMood();

    /**
     * @brief Trigger a change in the customer's order process state.
     */
    void changedOrderProcessState();

    /**
     * @brief Set the unique identifier of the customer.
     * @param id The unique identifier of the customer.
     */

    /**
     * @brief Request the bill from the restaurant.
     */
    void requestBill();

    /**
     * @brief Pay the bill or add it to the tab.
     * @param c A character indicating payment method (P for pay, T for tab).
     * @param t The total bill amount.
     * @return True if the bill is paid, false if added to the tab.
     */
    void payBill(char c, float t);

    /**
     * @brief Check if the customer is loyal.
     * @return True if the customer is loyal, false otherwise.
     */
    bool isLoyal();

    /**
     * @brief Start a tab for the customer.
     */
    void startTab();

    /**
     * @brief Pay the customer's tab.
     */
    void payTab();

    /**
     * @brief Print the customer's bill.
     * @return A string representing the customer's bill.
     */
    string printBill();

    void setKitchenReference(shared_ptr<Kitchen>);

    /**
     * @brief Create a new order.
     * @param orderID The identifier for the new order.
     * @param command A vector of shared pointers to menu item order commands.
     */
    void createOrder();
    vector<shared_ptr<MenuItemCommand>> predefinedOrder();

    /**
     * @brief Seat the customer at a table.
     * @param tableNum The table number where the customer is seated.
     */
    void beSeated(int tableNum);

    /**
     * @brief Get the table number where the customer is seated.
     * @return The table number.
     */
    int getTableNum();

    /**
     * @brief Set the emotional state of the customer.
     * @param mood A shared pointer to the new emotional state.
     */
    void setEmotionState(std::shared_ptr<EmotionState> mood);

    /**
     * @brief Set the order process state of the customer.
     * @param orderProcess A shared pointer to the new order process state.
     */
    void setOrderProcessState(std::shared_ptr<OrderProcessState> orderProcess);

    /**
     * @brief Get the emotional state of the customer.
     * @return A shared pointer to the emotional state.
     */
    std::shared_ptr<EmotionState> getMood();
    /**
     * @brief Set the Total object
     *
     * @param total
     */
    void setTotal(float total);
    /**
     * @brief  Get the Id of the customer's order
     *
     * @return An int that stores the ID of the order for the customer
     */
    int getID();
    /**
     * @brief
     *
     * @return a float that stores the customer's total bill
     */
    float getTotal();

    /**
     * @brief Get the order process state of the customer.
     * @return A shared pointer to the order process state.
     */
    std::shared_ptr<OrderProcessState> getOrderProcessState();

    /**
     * @brief Get a vector of customer's orders.
     * @return A vector of shared pointers to orders.
     */
    std::vector<std::shared_ptr<Order>> getOrders();

    /**
     * @brief Receive a pizza order.
     * @param pizza A shared pointer to the pizza order.
     * @return True if the customer receives the order, false otherwise.
     */
    bool receiveOrder(std::shared_ptr<Pizza> pizza);

    /**
     * @brief Print information about the customer.
     * @return A string representing customer information.
     */
    std::string printCustomer();

    bool hasOrdered = false; /**< A flag indicating whether the customer has placed an order. */
    bool hasBill = false;    /**< A flag indicating whether the customer has a bill. */
    bool hasFood = false;    /**< A flab indicating whether the customer has their food or not*/

    /**
     * @brief Check if the customer has received food.
     * @return True if the customer has received food, false otherwise.
     */

    void hasPizza();
    /**
     * @brief Function that will call the menu, for the customer so that they can build the pizza from scratch
     *
     * @return returns a vector of shared pointers that point at MenuItemCommands
     */
    vector<shared_ptr<MenuItemCommand>> buildPizza(); // interact with the menu, what is chosen on the menu will have a corresponding menu command which is added to the vector;
    /**
     * @brief Function will have the customer talk to the waiter through the mediator
     *
     */
    void talkToWaiter();

    shared_ptr<Customer> getMe();

    std::string generateRandomString(int length)
    {
        const std::string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        std::string randomString;
        srand(static_cast<unsigned int>(time(nullptr))); // Seed the random number generator with the current time

        for (int i = 0; i < length; ++i)
        {
            int randomIndex = rand() % characters.length();
            randomString += characters[randomIndex];
        }

        return randomString;
    }

    int getRandomNumber() {
        // Seed the random number generator with a value based on the current time
        std::random_device rd;
        std::mt19937 gen(rd());

        // Define the range (0 to 100)
        std::uniform_int_distribution<int> dist(0, 100);

        // Generate a random number
        int randomNum = dist(gen);

        return randomNum;
    }
    /**
     * @brief Get the Tab object
     *
     * @return a shared pointer that points to the Tab for the customer
     */
    std::shared_ptr<Tab> getTab();
    /**
     * @brief leave function will tell the mediator that the customer want to leave the restaurant
     *
     */
    void leave();
    /**
     * @brief  getKitchenReference function will tell the mediator that the customer wants the reference of the manager that owns the restaurant
     *
     */
    void getKitchenReference();
};

#endif
