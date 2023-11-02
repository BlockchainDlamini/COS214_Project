#ifndef GAMEFACADE_H
#define GAMEFACADE_H

#include <vector>
#include <memory>

class Customer;
class Mediator;

class gameFacade
{
    private:
        int numCustomerGroups, floorsize, tableSize;
        std::shared_ptr<Mediator> mediator;
        void gameSetUp();
        std::vector<std::shared_ptr<Customer>> generateCustomerGroup(int);
        std::vector<std::shared_ptr<gameElement>> createGameElements(int);
    public:
        gameFacade();
        void runGame();
        ~gameFacade();
};


#endif