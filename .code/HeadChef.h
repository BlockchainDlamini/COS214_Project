/*@file HeadChef.h
 *@brief contains the HeadChef class
 *       which is a subclass of Kitchen
 *       and creates a pizza for a food item
 *       in the kitchen
 *@bug No known bugs.
*/
#ifndef __HEAD_CHEF_H__
#define __HEAD_CHEF_H__

#include "Kitchen.h"
#include "Pizza.h"
#include "FoodItem.h"
#include <queue>
#include <vector>
#include <memory>
using namespace std;

class HeadChef : public Kitchen {
    public: 
        /*@brief constructor for HeadChef
            *@param none
            *@return returns HeadChef object
        */
        HeadChef();
        /*@brief handleOrder function for HeadChef
            * handles the pasted request from the chain of responsibility
            *@param vecto<shared_ptr<FoodItem>>
            *@return none
        */
        void handleOrder(vector<shared_ptr<FoodItem>>);
        /*@brief bakePizza function for HeadChef
            * bakes the pizza
            * defines the build function from the Builder Pattern 
            *@param vecto<shared_ptr<FoodItem>>
            *@return none
        */
        void bakePizza(vector<shared_ptr<FoodItem>>);
        /*@brief getPizza function for HeadChef
            * returns the baked pizza
            * defines the getResult function from the Builder Pattern
            * @param none
            * @return shared_ptr<Pizza> pizza
        */
        shared_ptr<Pizza> getPizza();
    private:
        shared_ptr<Pizza> pizza;
        shared_ptr<Kitchen> next;
};

#endif