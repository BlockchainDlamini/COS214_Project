#ifndef FOODITEM_H
#define FOODITEM_H
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include "gameElement.h"
using namespace std;
//THIS IS THE CLASS AT THE TOP OF THE LINK BETWEEN FILES
class FoodItem: public gameElement
{
protected:
	float price;
	string name;
public:
	FoodItem(string, float);
	string getName();
	float getPrice();
	string toString();
};
#endif