
#include "gameFacade.h"

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
    std::cout << "Welcome to The Pizzaria game!!" << std::endl;
    std::cout << "Would you like to configure the game before starting?\n1=='YES' and 2=='NO': ";
    int input;
    cin >> input;
    if (input == 2)
    {
        numCustomerGroups = 10;
        floorsize = 4;
        tableSize = 4;
    }
    else
    {
        std::cout << "How many rounds of customer would you like the game to have?" << std::endl;
        cin >> numCustomerGroups;
        std::cout << "The returant floor is a square. How many tile should 1 of the side have?" << std::endl;
        cin >> floorsize;
        std::cout << "How many seats should each ;=table have?" << std::endl;
        cin >> tableSize;
    }

    mediator = std::make_shared<Pager>();

    ;    std::vector<std::shared_ptr<gameElement>> gmElements = createGameElements(input);
    mediator->addGameElements(gmElements);
}

std::vector<std::shared_ptr<gameElement>> GameFacade::createGameElements(int input)
{
    std::vector<std::shared_ptr<gameElement>> gmElements;


    shared_ptr<Floor> floorObj = make_shared<Floor>(3,3);

    //Floor* floor1 = new Floor(3,3);
    maitreD= std::make_shared<MaitreD>("Steve", floorObj);
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
    std::cout << "A new group of customers has just entered the restuarant" << std::endl;
    for (int i = 0; i < customers.size(); i++)
        std::cout << customers.at(i)->printCustomer() << std::endl;
    std::cout << "Press Enter to continue" << std::endl;
    std::cin.ignore(1000000000, '\n');

    maitreD->seatCustomers(customers);
    std::cout << "The customer group has been seated" << std::endl;
    for (int i = 0; i < customers.size(); i++)
        std::cout << customers.at(i)->printCustomer() << std::endl;
    std::cout << "Press Enter to continue" << std::endl;
    std::cin.ignore(1000000000, '\n');

    for (int i = 0; i < customers.size(); i++)
        customers.at(i)->createOrder();

    for (int i = 0; i < customers.size(); i++)
        customers.at(i)->talkToWaiter();
    std::cout << "The customer group has placed their orders" << std::endl;
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
    shared_ptr<Customer> c =make_shared<Customer>(234);
    mediator1->addGameElement(c);
    c->setGameEngine(mediator1);
    c->setOperation("getKitchenReference");
    c->changed();
}
