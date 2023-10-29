#ifndef __MAKE_CHICKEN_H__
#define __MAKE_CHICKEN_H__

#include "MakeTopping.h"

class MakeChicken : public MakeTopping {
    public:
        MakeChicken(std::shared_ptr<Kitchen>);
        std::shared_ptr<FoodItem> execute();
};

#endif

