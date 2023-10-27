#include "MakeSauce.h"
#include "SauceChef.h"
using namespace std;

MakeSauce::MakeSauce(shared_ptr<Kitchen> state) : MenuItemCommand(state) {}

shared_ptr<FoodItem> MakeSauce::execute() {
    if (typeid(state) == typeid(SauceChef)) {
        return state.execute();
    }
    return nullptr;
}