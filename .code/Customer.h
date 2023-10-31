#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

/**
 * @class Customer
 * @brief Represents a customer in a restaurant with various states and actions.
 */
class Customer : public enable_shared_from_this<Customer>
{
    private:
        float bankAccountAmount;                                                   /**< The amount of money in the customer's bank account. */
        int tableNum;                                                              /**< The table number where the customer is seated. */

    public:
        Customer(int id, int bankAccountAmount);
        ~Customer(){}
};

#endif
