#ifndef __MAKE_CHEDDAR_H__
#define __MAKE_CHEDDAR_H__

#include "MakeCheese.h"

class MakeCheddar : public MakeCheese {
    public:
        MakeCheddar(std::shared_ptr<Kitchen>);
        std::shared_ptr<FoodItem> execute();
};

#endif

