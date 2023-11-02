#include "gameFacade.h"
#include <memory>

int main ()
{
    std::shared_ptr<GameFacade> pizzaria = std::make_shared<GameFacade>();
    pizzaria->runGame();
    return 0;
}