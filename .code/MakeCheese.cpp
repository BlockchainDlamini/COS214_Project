/*@file MakeCheese.cpp
 *@brief 
  *@brief contains the MakeCheese class
  *       which is a subclass of MenuItemCommand
  *       and creates a sauce for a food item
  *       in the kitchen
  *@bug No known bugs.
*/
#include "MakeCheese.h"
#include "CheeseChef.h"
using namespace std;

MakeCheese::MakeCheese(shared_ptr<Kitchen> state) : MenuItemCommand() {
    this->state = state;
    while (!dynamic_pointer_cast<CheeseChef>(this->state))
      this->state = this->state->getNextChef();
}

shared_ptr<FoodItem> MakeCheese::execute() {
    return state->execute(this);
}