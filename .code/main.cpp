#include <iostream>
#include "ManagerChef.h"
using namespace std;
int main()
{
	//ADDING INGREDIANTS TO THE CUSTOMERS ORDER
	//AND ALSO ADDING THE ID NUMBER OF THE ORDER
	vector<shared_ptr<Order>> tak;
	shared_ptr<ManagerChef> mng_chef = make_shared<ManagerChef>();
	mng_chef->cycle();
	vector<shared_ptr<Kitchen>> chefs = mng_chef->getChefs();
	shared_ptr<Order> val = make_shared<Order>(55667);
	val->addMenuItemOrderCommand(make_shared<MakePepperoni>(chefs[3]));
	val->addMenuItemOrderCommand(make_shared<MakeDeepDish>(chefs[0]));
	val->addMenuItemOrderCommand(make_shared<MakeBeef>(chefs[3]));
	val->addMenuItemOrderCommand(make_shared<MakeBlueCheese>(chefs[1]));
	val->addMenuItemOrderCommand(make_shared<MakeChutneySauce>(chefs[2]));
	val->addMenuItemOrderCommand(make_shared<MakeOlives>(chefs[3]));
	val->addMenuItemOrderCommand(make_shared<MakeMushrooms>(chefs[3]));
	val->addMenuItemOrderCommand(make_shared<MakeTomatoPaste>(chefs[2]));
	tak.push_back(val);

	shared_ptr<Order> tal = make_shared<Order>(996);
	tal->addMenuItemOrderCommand(make_shared<MakeBoiledCrust>(chefs[0]));
	tal->addMenuItemOrderCommand(make_shared<MakeMushrooms>(chefs[3]));
	tal->addMenuItemOrderCommand(make_shared<MakeMushrooms>(chefs[3]));
	tal->addMenuItemOrderCommand(make_shared<MakeCheddar>(chefs[1]));
	tal->addMenuItemOrderCommand(make_shared<MakeGouda>(chefs[1]));
	tal->addMenuItemOrderCommand(make_shared<MakeSweetChilli>(chefs[2]));
	tak.push_back(tal);

	mng_chef->handleOrder(make_pair(4489, tak));

	cout << endl << endl << endl;
	/*vector<shared_ptr<Order>> spec;
	for (int j = 1; j <= 3; j++)
	{
		shared_ptr<Order> in = make_shared<Order>(996+j);
		for (int i = 0; i < 12; i++)
		{
			switch (i % 4)
			{
			case 0: 
				in->addMenuItemOrderCommand(make_shared<MakeMushrooms>(chefs[3]));
				break;
			case 1:
				in->addMenuItemOrderCommand(make_shared<MakeSweetChilli>(chefs[2]));
				break;
			case 2:
				in->addMenuItemOrderCommand(make_shared<MakeBoiledCrust>(chefs[0]));
				break;
			case 3:
				in->addMenuItemOrderCommand(make_shared<MakePepperoni>(chefs[3]));
				break;
			case 4:
				in->addMenuItemOrderCommand(make_shared<MakeDeepDish>(chefs[0]));
				break;
			}
		}
		spec.push_back(in);
	}	
	
	mng_chef->handleOrder(make_pair(55669, spec));*/
	cout << "this is me man" << endl;
	return 0;
}