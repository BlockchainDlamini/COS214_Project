#include "gameFacade.h"
#include "Customer.h"
#include "Mediator.h"
#include "maitreD.h"
#include <iostream>

gameFacade::gameFacade()
{
    gameSetUp();
}

std::vector<std::shared_ptr<Customer>> gameFacade::generateCustomerGroup(int size)
{
    std::vector<std::shared_ptr<Customer>> customers;
    for (size_t i = 0; i < size; i++)
        customers.push_back(std::make_shared<Customer>());
    
    return customers;    
}

void userConfigureSystem()
{
    
}

void gameFacade::gameSetUp()
{
    std::cout<<"Welcome to The Pizzaria game!!"<<std::endl;
    std::cout<<"Would you like to configure the game before starting? 1=YES and 2=NO"<<std::endl;
    int input; 
    cin>>input;
    if(input==2)
    {
        numCustomerGroups=10;
        floorsize = 4;
        tableSize = 4;
    }
    else
    {
        std::cout<<"How many rounds of customer would you like the game to have?"<<std::endl;
        cin>>numCustomerGroups;
        std::cout<<"The returant floor is a square. How many tile should 1 of the side have?"<<std::endl;
        cin>>floorsize;
        std::cout<<"How many seats should each table have?"<<std::endl;
        cin>>tableSize;
    }    
    
    mediator  = std::make_shared<Mediator>();

    std::vector<std::shared_ptr<gameElement>> gmElements = createGameElements(input);
    mediator->addGameElements(gmElements);
}

std::vector<std::shared_ptr<gameElement>> gameFacade::createGameElements(int input)
{
    std::vector<std::shared_ptr<gameElement>> gmElements;

    gmElements.push_back(std::make_shared<MaitreD>()); //only 1 maitreD in the game
}

void gameFacade::runGame()
{
    for (int i = 0; i < numCustomerGroups; i++)
    {
        
    }

    std::cout<<"The game is now done! We hope you enjoyed it!!"<<std::endl;
    
}

gameFacade::~gameFacade()
{
}