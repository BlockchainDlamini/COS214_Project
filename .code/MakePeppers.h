#ifndef __MAKE_PEPPERS_H__
#define __MAKE_PEPPERS_H__

#include "MakeTopping.h"

class MakePeppers : public MakeTopping {
    public:
        MakePeppers(std::shared_ptr<Kitchen>);
        std::shared_ptr<FoodItem> execute();
};

#endif

