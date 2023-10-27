#ifndef __MAKE_SAUCE_H__
#define __MAKE_SAUCE_H__

#include "MenuItemCommand.h"

class MakeSauce : public MenuItemCommand {
    public:
        MakeSauce(std::shared_ptr<Kitchen>);
        std::shared_ptr<FoodItem> execute();
};

#endif