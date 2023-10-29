#ifndef __PREDIFINED_ORDERS_H__
#define __PREDIFINED_ORDERS_H__

#include "gameElement.h"
#include "Pizza.h"
#include "Mozzarella.h"
#include "ThinCrust.h"
#include "Pepperoni.h"
#include "Cheddar.h"
#include "Chicken.h"
#include "DoubleDecker.h"
#include "HeadChef.h"
#include "PredefinedOrders.h"
#include <memory>
#include <vector>

class PredefinedOrders : public gameElement {
    public:
        PredefinedOrders();
        std::shared_ptr<Pizza> makeMozzarellaPizza();
        std::shared_ptr<Pizza> makePepperoniPizza();
        std::shared_ptr<Pizza> makeChickenDoubleDeckerPizza();
        std::shared_ptr<Pizza> makeCheesyPizza();
    private:
        shared_ptr<HeadChef> headChef;
};

#endif