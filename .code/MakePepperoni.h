#ifndef __MAKE_PEPPERONI_H__
#define __MAKE_PEPPERONI_H__

#include "MakeTopping.h"

class MakePepperoni : public MakeTopping {
    public:
        MakePepperoni(std::shared_ptr<Kitchen>);
        std::shared_ptr<FoodItem> execute();
};

#endif
