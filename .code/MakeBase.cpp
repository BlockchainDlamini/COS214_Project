#include "MakeBase.h"
#include "BaseChef.h"

MakeBase::MakeBase(shared_ptr<Kitchen> state) : MenuItemCommand(state) {}

shared_ptr<FoodItem> MakeBase::execute() {
    if (typeid(state) == typeid(BaseChef)) {
        return state.execute();
    }
    return nullptr;
}