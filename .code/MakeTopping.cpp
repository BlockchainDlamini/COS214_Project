/*@file MakeTopping.cpp
 *@brief contains the MakeTopping class
 *       which is a subclass of MenuItemCommand
 *       and creates a topping for a food item
 *       in the kitchen
 *@bug No known bugs.
*/

#include "MakeTopping.h"
#include "ToppingsChef.h"
using namespace std;

MakeTopping::MakeTopping(shared_ptr<Kitchen> state) : MenuItemCommand() {
    this->state = state;
    while (typeid(state) != typeid(ToppingsChef))
        this->state = this->state->getNextChef();
}

shared_ptr<FoodItem> MakeTopping::execute() {
    return state->execute(enable_shared_from_this<MakeTopping>::shared_from_this());
}