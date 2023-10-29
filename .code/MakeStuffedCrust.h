#ifndef __MAKE_STUFFED_CRUST_H__
#define __MAKE_STUFFED_CRUST_H__

#include "MakeBase.h"

class MakeStuffedCrust : public MakeBase{
    public:
        MakeStuffedCrust(std::shared_ptr<Kitchen>);
        std::shared_ptr<FoodItem> execute();
};

#endif