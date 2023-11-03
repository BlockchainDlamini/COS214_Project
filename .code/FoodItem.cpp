#include "FoodItem.h"
#include <cmath>

FoodItem::FoodItem(string nm, float p)
{
	price = p;
	name = nm;
}

string FoodItem::getName()
{
	return name;
}

float FoodItem::getPrice()
{
	return price;
}

string FoodItem::toString()
{
	string val = "";
	val += "Name: " + name + "\tPrice: R" + to_string(price) + "\n";
	return val;
}