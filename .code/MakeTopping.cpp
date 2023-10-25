#include "MakeTopping.h"
#include "ToppingsChef.h"

MakeTopping::MakeTopping(shared_ptr<Kitchen> state) : MenuItemCommand(state) {}

shared_ptr<FoodItem> MakeTopping::execute() {
    if (typeid(state) == typeid(ToppingsChef)) {
        return state.execute();
    }
    return nullptr;
}