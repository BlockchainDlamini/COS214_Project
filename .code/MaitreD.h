/**
 * @file MaitreD.h
 * @brief Defines the MaitreD class, responsible for seating customers and managing Waiters.
 */
#ifndef MAITRED_H
#define MAITRED_H

#include "RegularWaiter.h"//BOBS ADDITION

using namespace std;

/**
 * @class MaitreD
 * @brief Represents a MaitreD responsible for seating customers and managing Waiters.
 */
class MaitreD : public Waiter {
public:
    /**
     * @brief Constructor for the MaitreD class.
     * @param name The name of the MaitreD.
     * @param floor A shared pointer to the Floor.
     */
    MaitreD(string name, shared_ptr<Floor> floor);

    /**
     * @brief Seat customers at assigned tables.
     * @param customers A vector of shared pointers to Customer objects.
     */
    void seatCustomers(std::vector<std::shared_ptr<Customer>> customers);

    /**
     * @brief Get function for Pager.
     * @details This function is used to get information from the Pager.
     * @return A string containing information from the Pager.
     */
    virtual string get();

    /**
     * @brief Changed function for Pager.
     * @details This function is called when the Pager needs to notify the MaitreD of a change.
     */
    //void changed();

    /**
     * @brief Set function for Pager.
     * @details This function is used to send a request to the Pager with a specified operation.
     * @param op The operation to be performed by the Pager.
     */
    void setOperation(string op);

    /**
     * @brief Notifies the floor that the customers are leaving.
     * @details Will call the floorObj leave function.
     * @param tableNum The tableNum that the customers are leaving.
     */
    void customersLeft(int tableNum);

private:
    shared_ptr<Floor> floorobj;
    string name;
};

#endif // MAITRED_H
