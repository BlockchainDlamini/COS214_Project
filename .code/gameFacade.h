#ifndef GAMEFACADE_H
#define GAMEFACADE_H

#include "KitchenInterface.h"
class Customer;
class Mediator;
class MaitreD;

class GameFacade
{
    private:
        int numCustomerGroups, floorsize, tableSize, id;
        std::shared_ptr<Mediator> mediator;
        std::shared_ptr<MaitreD> maitreD;
        void gameSetUp();
        std::vector<std::shared_ptr<Customer>> generateCustomerGroup(int);
        std::vector<std::shared_ptr<gameElement>> createGameElements(int);
        int generateRandom(int, int);
        void singleRound();
    public:
        void runGame2();
        GameFacade();
        void runGame();
        ~GameFacade();
};
#endif