#ifndef FOODITEM_H
#define FOODITEM_H
#include <iostream>
#include <memory>
#include <vector>
#include <string>
using namespace std;
class FoodItem
{
protected:
	double price;
	string name;
public:
	FoodItem(string);
	string getName();
	double getPrice();
	string toString();
};
#endif