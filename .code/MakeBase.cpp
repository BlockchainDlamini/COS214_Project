/*@file MakeBase.cpp
*@brief 
 *@brief contains the MakeBase class
 *       which is a subclass of MenuItemCommand
 *       and creates a base for a food item
 *       in the kitchen
 *@bug No known bugs.
*/
#include "MakeBase.h"
#include "BaseChef.h"
using namespace std;

MakeBase::MakeBase(shared_ptr<Kitchen> state) : MenuItemCommand(state) {}

shared_ptr<FoodItem> MakeBase::execute() {
    return state->execute();
} 