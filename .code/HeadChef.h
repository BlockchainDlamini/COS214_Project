/**
 * @file HeadChef.h
 * @brief Contains the HeadChef class, a subclass of Kitchen, responsible for creating pizza in the kitchen.
 * @bug No known bugs.
 */

#ifndef __HEAD_CHEF_H__
#define __HEAD_CHEF_H__
#include "Order.h"//BOBS ADDITION

/**
 * @class HeadChef
 * @brief Represents the HeadChef class, responsible for creating pizzas.
 */
class HeadChef : public Kitchen, public enable_shared_from_this<HeadChef> {
public:
    /**
     * @brief Constructor for the HeadChef class.
     */
    HeadChef();

    /**
     * @brief Bake a pizza using the provided food items.
     *        Implements the Builder Pattern to define pizza construction.
     * @param foodItems A vector of shared pointers to FoodItem objects.
     * @return A shared pointer to the created Pizza object.
     */
    std::shared_ptr<Pizza> bakePizza(std::vector<std::shared_ptr<FoodItem>> foodItems);

    /**
     * @brief Add a topping to a pizza.
     * @param pizza A shared pointer to the Pizza object.
     * @param topping A shared pointer to the FoodItem representing the topping.
     */
    void addTopping(std::shared_ptr<Pizza> pizza, std::shared_ptr<FoodItem> topping);

    /**
     * @brief Add a sauce to a pizza.
     * @param pizza A shared pointer to the Pizza object.
     * @param sauce A shared pointer to the FoodItem representing the sauce.
     */
    void addSauce(std::shared_ptr<Pizza> pizza, std::shared_ptr<FoodItem> sauce);

    /**
     * @brief Add a base to a pizza.
     * @param pizza A shared pointer to the Pizza object.
     * @param base A shared pointer to the FoodItem representing the pizza base.
     */
    void addBase(std::shared_ptr<Pizza> pizza, std::shared_ptr<FoodItem> base);

    /**
     * @brief Add cheese to a pizza.
     * @param pizza A shared pointer to the Pizza object.
     * @param cheese A shared pointer to the FoodItem representing the cheese.
     */
    void addCheese(std::shared_ptr<Pizza> pizza, std::shared_ptr<FoodItem> cheese);

    /**
     * @brief Get the ID of the waiter.
     * @return The ID of the waiter.
     */
    int getWaiterID();

    /**
     * @brief Handle the order from the waiter.
     * @param orderID The ID of the order.
     * @param waiterID The ID of the waiter.
     * @param foodItems A vector of shared pointers to the FoodItem objects in the order.
     */
    void handleOrder(int orderID, int waiterID, std::vector<std::shared_ptr<FoodItem>> foodItems); 
    
    /**
     * @brief Collect the completed orders.
     * @return A pair containing the order ID and a vector of shared pointers to the prepared pizzas.
     */
    pair<int, std::vector<std::shared_ptr<pair<int, std::shared_ptr<Pizza>>>>> collectOrder();

private:
    pair<int, std::vector<std::shared_ptr<pair<int, std::shared_ptr<Pizza>>>>> completeOrders; 
    std::vector<std::shared_ptr<pair<int, std::shared_ptr<Pizza>>>> pizzaPairs; 
    std::shared_ptr<Kitchen> nextChef; 
};

#endif
