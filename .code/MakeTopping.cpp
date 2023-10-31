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

MakeTopping::MakeTopping(shared_ptr<Kitchen> state) : MenuItemCommand(state) {
    while (typeid(state) != typeid(ToppingsChef))
        state = state->getNextChef();
}

shared_ptr<FoodItem> MakeTopping::execute() {
    return state->execute();
}