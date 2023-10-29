#ifndef __MAKE_DOUBLE_DECKER_H__
#define __MAKE_DOUBLE_DECKER_H__

#include "MakeBase.h"

class MakeDoubleDecker : public MakeBase{
    public:
        MakeDoubleDecker(std::shared_ptr<Kitchen>);
        std::shared_ptr<FoodItem> execute();
};

#endif