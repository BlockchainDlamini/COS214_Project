#ifndef __MAKE_DEEP_DISH_H__
#define __MAKE_DEEP_DISH_H__

#include "MakeBase.h"

class MakeDeepDish : public MakeBase{
    public:
        MakeDeepDish(std::shared_ptr<Kitchen>);
        std::shared_ptr<FoodItem> execute();
};

#endif