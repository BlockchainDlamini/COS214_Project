#ifndef GAMEFACADE_H
#define GAMEFACADE_H

#include "KitchenInterface.h"

/**
 * @class GameFacade
 * @brief The main class responsible for running the game simulation.
 */
class GameFacade
{
    private:
        int numCustomerGroups, floorsize, tableSize, id; /**< Number of customer groups, floor size, table size, and an identifier. */
        std::shared_ptr<Pager> mediator; /**< Shared pointer to the Pager class. */
        std::shared_ptr<MaitreD> maitreD; /**< Shared pointer to the MaitreD class. */

        /**
         * @brief Set up the initial state of the game.
         */
        void gameSetUp();

        /**
         * @brief Generate a vector of shared pointers to Customer objects.
         * @param n Number of customers in the group.
         * @return A vector of shared pointers to Customer objects.
         */
        std::vector<std::shared_ptr<Customer>> generateCustomerGroup(int n);

        /**
         * @brief Creates all the game elements required to run the game.
         * @return A vector of shared pointers to gameElement objects.
         */
        std::vector<std::shared_ptr<gameElement>> createGameElements();

        /**
         * @brief Generate a random number within a specified range.
         * @param min The minimum value of the range.
         * @param max The maximum value of the range.
         * @return The generated random number.
         */
        int generateRandom(int min, int max);

        /**
         * @brief Execute a single round of the game.
         */
        void singleRound();
        void waiterToKitchen();
        void donut();
        void delay(int);

    public:

        /**
         * @brief Run the game simulation. For testing purposes.
         */
        void runGame2();

        /**
         * @brief Constructor for GameFacade.
         */
        GameFacade();

        /**
         * @brief Run the game simulation.
         */
        void runGame();

        /**
         * @brief Destructor for GameFacade.
         */
        ~GameFacade();
};
#endif