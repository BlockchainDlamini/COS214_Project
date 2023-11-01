#include "OrderProcessState.h"
OrderProcessState::OrderProcessState()
{
}
void OrderProcessState::printStateChange()
{
    std::cout << "Customer state has changed to " + stateName + "\n";
};