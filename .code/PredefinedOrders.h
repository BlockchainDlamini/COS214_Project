/**
 * @file PredefinedOrders.h
 * @brief Contains the class declarations for the PredefinedOrders class, responsible for creating predefined pizza orders.
 */

#ifndef __PREDEFINED_ORDERS_H__
#define __PREDEFINED_ORDERS_H__

#include "Customer.h"//BOBS ADDITION

/**
 * @class PredefinedOrders
 * @brief Represents the PredefinedOrders class, responsible for creating predefined pizza orders.
 */
class PredefinedOrders : public gameElement {
public:
    /**
     * @brief Constructor for the PredefinedOrders class.
     */
    PredefinedOrders();

    /**
     * @brief Make a predefined Mozzarella pizza order.
     * @param quantity The quantity of Mozzarella pizzas to make.
     */
    void makeMozzarellaPizza(int quantity, string);

    /**
     * @brief Make a predefined Pepperoni pizza order.
     * @param quantity The quantity of Pepperoni pizzas to make.
     */
    void makePepperoniPizza(int quantity, string);

    /**
     * @brief Make a predefined Chicken Double Decker pizza order.
     * @param quantity The quantity of Chicken Double Decker pizzas to make.
     */
    void makeChickenDoubleDeckerPizza(int quantity, string);

    /**
     * @brief Make a predefined Cheesy pizza order.
     * @param quantity The quantity of Cheesy pizzas to make.
     */
    void makeCheesyPizza(int quantity, string);

private:
    shared_ptr<HeadChef> headChef;
};

#endif
