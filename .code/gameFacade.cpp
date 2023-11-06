#include "gameFacade.h"
#include <iostream>
#include <string>
#include <thread>
using namespace std;

GameFacade::GameFacade()
{
    id = 0;
}

std::vector<std::shared_ptr<Customer>> GameFacade::generateCustomerGroup(int size)
{
    std::vector<std::shared_ptr<Customer>> customers;
    std::vector<std::shared_ptr<gameElement>> customerElements;
    std::shared_ptr<Customer> temp;
    for (size_t i = 0; i < size; i++)
    {
        temp = std::make_shared<Customer>(id, (float)generateRandom(100, 100000));
        temp->setGameEngine(mediator);
        customers.push_back(temp);
        customerElements.push_back(std::dynamic_pointer_cast<gameElement>(temp));
        id++;
    }
    mediator->addGameElements(customerElements);
    return customers;
}

void GameFacade::gameSetUp()
{
    
    std::cout << endl;
    std::cout << "\033[46;30m~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ \033[0m" << std::endl;

    std::cout << "\033[46;30m  W\033[0m";
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    std::cout << "\033[46;30me\033[0m";
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    std::cout << "\033[46;30ml\033[0m";
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    std::cout << "\033[46;30mc\033[0m";
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    std::cout << "\033[46;30mo\033[0m";
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    std::cout << "\033[46;30mm\033[0m";
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    std::cout << "\033[46;30me \033[0m";
    std::this_thread::sleep_for(std::chrono::milliseconds(200));

    std::cout << "\033[46;30mt\033[0m";
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    std::cout << "\033[46;30mo\033[0m";
    std::this_thread::sleep_for(std::chrono::milliseconds(200));


    std::cout << "\033[46;30m H\033[0m";
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    std::cout << "\033[46;30mo\033[0m";
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    std::cout << "\033[46;30mm\033[0m";
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    std::cout << "\033[46;30me\033[0m";
    std::this_thread::sleep_for(std::chrono::milliseconds(200));

    std::cout << "\033[46;30m S\033[0m";
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    std::cout << "\033[46;30ml\033[0m";
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    std::cout << "\033[46;30mi\033[0m";
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    std::cout << "\033[46;30mc\033[0m";
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    std::cout << "\033[46;30me\033[0m";
    std::this_thread::sleep_for(std::chrono::milliseconds(200));

    std::cout << "\033[46;30m :\033[0m";
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    std::cout << "\033[46;30m)  \033[0m";
    std::this_thread::sleep_for(std::chrono::milliseconds(200));

    std::cout << endl;


    std::cout << "\033[46;30m~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ \033[0m" << std::endl;


    std::cout<<endl;


    std::cout << "\033[47;30mWould you like to configure the game before starting? (yes/no)\033[0m" << std::endl;

    string input;
    cin >> input;
    if (input == "no")
    {
        numCustomerGroups = 10;
        floorsize = 4;
        tableSize = 4;
    }
    else
    {
        std::cout << "\033[47;30mHow many rounds of customer would you like the game to have?\033[0m" << std::endl;
        cin >> numCustomerGroups;

        std::cout << "\033[47;30mThe restaurant floor is a square matrix. How many tiles would you like one side of the square to have?\033[0m" << std::endl;
        cin >> floorsize;

        std::cout << "\033[47;30mHow many seats would you like each table to have?\033[0m" << std::endl;
        cin >> tableSize;
    }

    mediator = std::make_shared<Pager>();

    int index = 0;

    if (input == "yes") {
        index = 1;
    }
    else {
        index = 2;
    }

    std::vector<std::shared_ptr<gameElement>> gmElements = createGameElements();
    mediator->addGameElements(gmElements);
}

std::vector<std::shared_ptr<gameElement>> GameFacade::createGameElements()
{
    std::vector<std::shared_ptr<gameElement>> gmElements;


    shared_ptr<Floor> floorObj = make_shared<Floor>(3, 3);

    //Floor* floor1 = new Floor(3,3);
    maitreD = std::make_shared<MaitreD>("Steve", floorObj);
    maitreD->setGameEngine(mediator);
    gmElements.push_back(maitreD);
    //gmElements.push_back();
    shared_ptr<RegularWaiter> VAL = std::make_shared<RegularWaiter>(RegularWaiter(0, { 0 }, floorObj));
    VAL->setGameEngine(mediator);
    gmElements.push_back(VAL);
    // added
    shared_ptr<RegularWaiter> newWaiter1 = RegularWaiter::createRegularWaiter(1, vector<int>{0, 1, 2, 3}, floorObj);
    shared_ptr<RegularWaiter> newWaiter2 = RegularWaiter::createRegularWaiter(2, vector<int>{4, 5, 6}, floorObj);
    newWaiter1->setGameEngine(mediator);
    newWaiter2->setGameEngine(mediator);


    for (int i = 1; i < floorsize + 1; i++)
    {
        int count = 0;
        vector <int> intstables;

        while (count > floorsize) {
            intstables.push_back(count);

        }
        gmElements.push_back(std::make_shared<RegularWaiter>(i, intstables, floorObj));
    }
    shared_ptr<KitchenInterface> t = std::make_shared<KitchenInterface>();
    t->setGameEngine(mediator);
    gmElements.push_back(t);
    return gmElements;
}

void GameFacade::runGame()
{
    gameSetUp();
    for (int i = 0; i < numCustomerGroups; i++)
    {
        singleRound();
        std::cout << "Press Enter to continue" << std::endl;
        std::cin.ignore(1000000000, '\n');
    }

    std::cout << "The game is now done! We hope you enjoyed it!!" << std::endl;
}

void GameFacade::singleRound()
{
    std::vector<std::shared_ptr<Customer>> customers = generateCustomerGroup(generateRandom(1, 10));

    std::cout << endl;
    std::cout << "\033[46;30m ~ A new group of customers has just entered the restuarant! ~\033[0m" << std::endl;


    for (int i = 0; i < customers.size(); i++)
        //std::cout << customers.at(i)->printCustomer() << std::endl;
    std::cout << "Press Enter to continue" << std::endl;
    std::cin.ignore(1000000000, '\n');

    maitreD->seatCustomers(customers);
    std::cout << "\033[46;30m ~ The customer group has been seated! ~\033[0m" << std::endl;


    for (int i = 0; i < customers.size(); i++)
        std::cout << customers.at(i)->printCustomer() << std::endl;
    std::cout << "Press Enter to continue" << std::endl;
    std::cin.ignore(1000000000, '\n');

    for (int i = 0; i < customers.size(); i++)
        customers.at(i)->createOrder();

    for (int i = 0; i < customers.size(); i++)
        customers.at(i)->talkToWaiter();
    std::cout << "\033[46;30m ~ The customers have placed their orders! ~\033[0m" << std::endl;

    for (int i = 0; i < customers.size(); i++)
        std::cout << customers.at(i)->printCustomer() << std::endl;

    std::cout << "Press Enter to continue" << std::endl;
    std::cin.ignore(1000000000, '\n');

    //for (int i = 0; i < customers.size(); i++)
    //    customers.at(i)->requestBill();

    // to request the bill
    customers.at(0)->requestBill();

    for (int i = 0; i < customers.size(); i++)
        mediator->removeGameElement(std::dynamic_pointer_cast<gameElement>(customers.at(i)));

}

int GameFacade::generateRandom(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

GameFacade::~GameFacade()
{
}

void GameFacade::runGame2() {
    shared_ptr<Pager> mediator1 = make_shared<Pager>();
    shared_ptr<KitchenInterface> kitchenInterface = make_shared<KitchenInterface>();
    mediator1->addGameElement(kitchenInterface);
    shared_ptr<Customer> c = make_shared<Customer>(234);
    mediator1->addGameElement(c);
    c->setGameEngine(mediator1);
    c->setOperation("getKitchenReference");
    c->changed();
}
