#ifndef FLOOR_H 
#define FLOOR_H

#include "floorComponent.h"
#include "Customer.h"
#include <iostream>

/**
 * @brief The Floor class represents the floor the restaurant.
 */
class Floor
{
    private:
        std::shared_ptr<floorComponent> theFloor; ///< The root component representing the floor.
        int sideLenght; ///< The length of the sides of the floor. The floor is a square
        int tableSpace; ///< The number of seats each table will have

        /**
         * @brief Merges tiles in the floor to make enough space to seat large groups
         * @param amount Amount of space needed for the group of customers. Used to figure out haw many tables to merdge
         * @return True if merging was successful, false otherwise.
         */
        bool merdgeTile(int amount);

        /**
         * @brief Unmerges previously merged tiles. Called when customer leaves
         */
        void unmerdgeTiles();

    public:
        /**
         * @brief Constructs a Floor object with specified side length and table space.
         * @param sideLength The length of the sides of the floor.
         * @param tableSpace The number of seats each table will have
         */
        Floor(int sideLength, int tableSpace);

        /**
         * @brief Checks if the floor has enough space for a customer group.
         * @param amount The size of the customer group.
         * @return True if there is enough space, false otherwise.
         */
        bool hasSpace(int amount);

        /**
         * @brief Seats a group of customers in the floor. Also assigns the table id to the customer
         * @param customers The vector of shared pointers to customers.
         * @return True if seating was successful, false otherwise.
         */
        bool seatCustomer(std::vector<std::shared_ptr<Customer>> customers);

        /**
         * @brief Unmerges the floor when customers leave.
         * @param id The table id of the leaving customer group.
         */
        void customersLeft(int id);

        /**
         * @brief Prints the floor in depth-first order.
         */
        void printDepth();

        /**
         * @brief Gets the table with specified id.
         * @param id The id of the table.
         * @return The shared pointer to the table.
         */
        std::shared_ptr<table> getTableAt(int id);

        /**
         * @brief Destructs the Floor object.
         */
        virtual ~Floor();
};

#endif
