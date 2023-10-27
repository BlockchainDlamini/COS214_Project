#include "MakeBase.h"
#include "BaseChef.h"
using namespace std;

MakeBase::MakeBase(shared_ptr<Kitchen> state) : MenuItemCommand(state) {}

shared_ptr<FoodItem> MakeBase::execute() {
    return state.execute();
}