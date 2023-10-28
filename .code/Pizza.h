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
#include <vector>
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
        Pizza(vector<shared_ptr<FoodItem>>);
    private:
        shared_ptr<FoodItem> base;
        shared_ptr<FoodItem> cheese;
        shared_ptr<FoodItem> sauce; 
        shared_ptr<FoodItem> toppings;

};

#endif 