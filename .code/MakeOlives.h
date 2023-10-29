#ifndef __MAKEOLIVES_H__
#define __MAKEOLIVES_H__

#include "MakeTopping.h"

class MakeOlives : public MakeTopping {
    public:
        MakeOlives(std::shared_ptr<Kitchen>);
        std::shared_ptr<FoodItem> execute();
};

#endif
