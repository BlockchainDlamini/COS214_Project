#ifndef CUSTOMER_H
#define CUSTOMER_H

// #include "EmotionState.h"
// #include "Disgruntaled.h"
// #include "Happy.h"
// #include "Satisfied.h"
// #include "Frustrated.h"
// #include "OrderProcessState.h"
// #include "Preorder.h"
// #include "Order.h"
// #include "gameElement.h"
// #include "Pizza.h"
// #include <iostream>
// #include <memory>
// #include <vector>
#include "Preorder.h" //BOBS ADDITION

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
    // Create an array of shared_ptr to strings for complaints
    std::shared_ptr<std::string> complaints[10]; /**an array of shared_ptr to strings for complaints for the Customer*/

    // Create an array of shared_ptr to strings for happyMessages
    std::shared_ptr<std::string> happyMessages[10]; /**an array of shared_ptr to strings for happyMessages for the Customer*/
    float total;                                    /**< The table number where the customer is seated. */
    vector<shared_ptr<Pizza>> pizza;                /**< The pizza ordered by the customer. */
    vector<shared_ptr<Order>> orders;               /**< A vector of customer's orders. */
    shared_ptr<Kitchen> kitchen;
    string name; /**<The name of the customer*/

public:
    /**
     * @brief Constructor for a Customer.
     * @param id The unique identifier of the customer.
     * @param tableNum The table number where the customer is seated.
     */

    // switched datatypes passed in
    void setName(string name);
    string getName();
    Customer(int id, float bankAccountAmount);

    /**
     * @brief Constructor for a Customer with an initial emotional state.
     * @param mood The initial emotional state of the customer.
     * @param tableNum The table number where the customer is seated.
     */

    // changed the paramter of bankAccountAmount from int to float
    Customer(std::shared_ptr<EmotionState> mood, float bankAccountAmount);
    Customer(float bankAccount);

    /**
     * @brief Change the emotional state of the customer.
     */
    void changeMood();
    void logComplaint();

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
    void payBill(char c, float t, bool check);

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

    /**
     * @brief Create a new order.
     * @param orderID The identifier for the new order.
     * @param command A vector of shared pointers to menu item order commands.
     */
    void createOrder(bool);

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
     * @brief Set the total cost of an item or order.
     *
     * This function allows you to specify the total cost, typically as a floating-point value, for an item or an order. The total cost represents the financial amount associated with the item or order.
     *
     * @param total The total cost to be set.
     */
    void setTotal(float total);

    /**
     * @brief Get the unique identifier of an item or order.
     *
     * This function retrieves the unique identifier associated with the item or order and returns it as an integer value. The identifier is used to distinguish the item or order from others.
     *
     * @return The unique identifier of the item or order.
     */
    int getID();

    /**
     * @brief Retrieve the total cost of an item or order.
     *
     * Use this function to obtain the total cost, typically as a floating-point value, associated with an item or order. The total cost represents the financial amount for the item or order.
     *
     * @return The total cost of the item or order.
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
    vector<pair<int, shared_ptr<Order>>> getOrders();

    /**
     * @brief Receive a pizza order.
     * @param pizza A shared pointer to the pizza order.
     * @return True if the customer receives the order, false otherwise.
     */
    bool receiveOrder(vector<shared_ptr<Pizza>>);

    /**
     * @brief Print information about the customer.
     * @return A string representing customer information.
     */
    std::string printCustomer();

    bool hasOrdered = false; /**< A flag indicating whether the customer has placed an order. */
    bool hasBill = false;    /**< A flag indicating whether the customer has a bill. */
    bool hasFood = false;    /**< A flag indicating whether the customer has their food. */

    /**
     * @brief Check if the customer has received food.
     * @return True if the customer has received food, false otherwise.
     */

    void hasPizza();
    /**
     * @brief This function will show the menu for building the pizza. It will allow the customer to chose a variety of different base,toppings,sauce and cheese.
     *
     * @return it will return a vector of shared_ptr that point at MenuItemCommands
     */
    vector<shared_ptr<MenuItemCommand>> addMenuItems(); // interact with the menu, what is chosen on the menu will have a corresponding menu command which is added to the vector;
    /**
     * @brief This Function will allow the customer to pick a predefined pizza/ a basic pizza that does not require them to build a new pizza
     *
     * @return it will return a vector of shared_ptr that point at MenuItemCommands
     */
    vector<shared_ptr<MenuItemCommand>> predefinedOrder();
    /**
     * @brief Initiate communication with the waiter.
     *
     * Use this function to signal the start of communication with the waiter. Depending on the context, it may involve requesting service, placing an order, or discussing specific requirements with the restaurant's staff.
     */
    void talkToWaiter();

    void waiterToTable(char action);

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

    int getRandomNumber()
    {
        // Seed the random number generator with a value based on the current time
        std::random_device rd;
        std::mt19937 gen(rd());

        // Define the range (0 to 100)
        std::uniform_int_distribution<int> dist(0, 100);

        // Generate a random number
        int randomNum = dist(gen);

        return randomNum;
    }
    int randomNumberForMessages()
    {
        // Seed the random number generator with a value based on the current time
        std::random_device rd;
        std::mt19937 gen(rd());

        // Define the range (0 to 100)
        std::uniform_int_distribution<int> dist(0, 9);

        // Generate a random number
        int randomNum = dist(gen);

        return randomNum;
    }
    /**
     * @brief Get a shared pointer to a Tab object.
     *
     * This function returns a shared pointer to a Tab object, allowing you to interact with and manipulate the Tab's properties.
     *
     * @return A shared pointer to a Tab object.
     */
    std::shared_ptr<Tab> getTab();

    /**
     * @brief Leave the restaurant or dining area.
     *
     * Use this function to signal that a customer is leaving the restaurant or dining area. It may involve clearing the table and making it available for the next customer.
     */
    void leave();

    /**
     * @brief Get a reference to the Kitchen.
     *
     * This function provides access to the Kitchen associated with the restaurant. It allows you to interact with and obtain information from the Kitchen.
     */
    void getKitchenReference();

    /**
     * @brief Set a reference to the Kitchen using a shared pointer.
     *
     * This function allows you to set a reference to the Kitchen by passing a shared pointer to a Kitchen object. This reference can be used to communicate with and access the Kitchen's functionality.
     *
     * @param kitchenPtr A shared pointer to a Kitchen object.
     */
    void setKitchenReference(std::shared_ptr<Kitchen> kitchenPtr);
};

#endif