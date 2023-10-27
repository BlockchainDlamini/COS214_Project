#ifndef __MENU_ITEM_COMMAND_H__
#define __MENU_ITEM_COMMAND_H__

#include "Kitchen.h"
#include "FoodItem.h"
#include "gameElement.h"
#include <memory>

class MenuItemCommand : gameElement {
    public:
        MenuItemCommand(std::shared_ptr<Kitchen>);
        std::shared_ptr<FoodItem> virtual execute() = 0;
        std::shared_ptr<Kitchen> getState();
    protected: 
        std::shared_ptr<Kitchen> state;
};

#endif