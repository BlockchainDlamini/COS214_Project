/*@file Pizza.h
@brief contains the Pizza class
       *which is a subclass of gameElement
       *and creates a pizza for the player
       *to eat
*/
#ifndef __PIZZA_H_
#define __PIZZA_H_

#include "gameElement.h"
#include "FoodItem.h"
#include "Cheese.h"
#include "Toppings.h"
#include "Sauce.h"
#include "Base.h"
#include <vector>
#include <list>
#include <string>
using namespace std;

class Pizza : gameElement {
    public:
        /*@brief constructor for Pizza
         *@param none
         *@return none
        */
        Pizza();
        /*@brief constructor for Pizza
         *@param vector<shared_ptr<FoodItem>>
         *@return none
        */
        string getDescription();
        float getPrice();
    private:
        shared_ptr<FoodItem> base;
        list<shared_ptr<FoodItem>> cheeseList;
        list<shared_ptr<FoodItem>> sauceList; 
        list<shared_ptr<FoodItem>> toppingsList;
        float price;

};

#endif 