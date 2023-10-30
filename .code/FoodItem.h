#ifndef FOODITEM_H
#define FOODITEM_H
#include <iostream>
#include <memory>
#include <vector>
#include <string>
using namespace std;
//THIS IS THE CLASS AT THE TOP OF THE LINK BETWEEN FILES
class FoodItem
{
protected:
	double price;
	string name;
public:
	FoodItem(string, double);
	string getName();
	double getPrice();
	string toString();
};
#endif