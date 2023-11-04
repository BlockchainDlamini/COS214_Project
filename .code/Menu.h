//
// Created by User on 29/10/2023.
//


#ifndef COS214_PROJECT_MENU_H
#define COS214_PROJECT_MENU_H


#include <string>
#include <map>
#include <iostream>
using namespace std;

//TODO:This class has not been tested
/**
 * @class Menu
 * @brief A class to represent the menu.
 */
class Menu {
public:
/**
* @brief Construct a new Menu object
*/
    Menu();

/**
 * @brief Add an item to the menu.
 * @param category The category of the item.
 * @param item The name of the item.
 * @param price The price of the item.
 */
    void add_item(const std::string& category, const std::string& item, int price) {
        menu[category][item] = price;
    }
    //void Prompt();

/**
 * @brief Display the general types of items in the menu.
 */
    void displayGeneralTypes();

    void displaySpecificTypes(int index);
private:
/**
* @brief A map to hold the menu items. The key is a string representing the category,
* and the value is another map where the key is a string representing the item name and
* the value is an integer representing the price.
*/
    map<string, map<string, int>> menu;
};


#endif //COS214_PROJECT_MENU_H
