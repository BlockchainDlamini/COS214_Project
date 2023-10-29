/*@file MakeBlueCheese.h
*@brief Contains the class declarations for the MakeBlueCheese class
*/
#ifndef __MAKE_BLUECHEESE_H__
#define __MAKE_BLUECHEESE_H__

#include "MakeCheese.h"

class MakeBlueCheese : public MakeCheese {
    public:
        MakeBlueCheese(std::shared_ptr<Kitchen>);
        std::shared_ptr<FoodItem> execute();
};

#endif

