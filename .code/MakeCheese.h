#ifndef __MAKE_CHEESE_H__
#define __MAKE_CHEESE_H__

#include "MenuItemCommand.h"

class MakeCheese : public MenuItemCommand {
    public:
        MakeCheese(std::shared_ptr<Kitchen>);
        std::shared_ptr<FoodItem> execute();
};

#endif