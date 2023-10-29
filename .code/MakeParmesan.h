#ifndef __MAKE_PARMESAN_H__
#define __MAKE_PARMESAN_H__

#include "MakeCheese.h"

class MakeMozzarella : public MakeCheese {
    public:
        MakeMozzarella(std::shared_ptr<Kitchen>);
        std::shared_ptr<FoodItem> execute();
};

#endif

