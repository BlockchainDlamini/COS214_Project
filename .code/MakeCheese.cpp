#include "MakeCheese.h"
#include "CheeseChef.h"
using namespace std;

MakeCheese::MakeCheese(shared_ptr<Kitchen> state) : MenuItemCommand(state) {}

shared_ptr<FoodItem> MakeCheese::execute() {
    return state.execute();
}