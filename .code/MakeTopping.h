#ifndef __MAKE_TOPPING_H__
#define __MAKE_TOPPING_H__

#include "MenuItemCommand.h"

class MakeTopping : public MenuItemCommand {
    public:
        MakeTopping(std::shared_ptr<Kitchen>);
        std::shared_ptr<FoodItem> execute();
};

#endif