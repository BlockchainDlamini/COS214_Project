#include "MakeTopping.h"
#include "ToppingsChef.h"
using namespace std;

MakeTopping::MakeTopping(shared_ptr<Kitchen> state) : MenuItemCommand(state) {}

shared_ptr<FoodItem> MakeTopping::execute() {
    return state.execute();
}