//
// Created by User on 29/10/2023.
//

#include "Menu.h"

Menu::Menu() {
    add_item("1) Bread", "Stuffed-crust", 34);
    add_item("1) Bread", "Thin crust", 45);
    add_item("1) Bread", "Double-Decker", 68);
    add_item("1) Bread", "Boiled", 52);
    add_item("1) Bread", "Deep-dish", 89);

    // 2) Sauce
    add_item("2) Sauce", "Sweet-chilli", 76);
    add_item("2) Sauce", "Ranch", 63);
    add_item("2) Sauce", "Tomato Paste", 47);
    add_item("2) Sauce", "Chutney sauce", 85);

    // 3) Toppings
    add_item("3) Toppings", "Pepperoni", 91);
    add_item("3) Toppings", "Olives", 73);
    add_item("3) Toppings", "Mushrooms", 58);
    add_item("3) Toppings", "Chicken", 82);
    add_item("3) Toppings", "Beef", 69);
    add_item("3) Toppings", "Peppers", 94);

    // 4) Cheese
    add_item("4) Cheese", "Mozzarella", 87);
    add_item("4) Cheese", "Cheddar", 72);
    add_item("4) Cheese", "Gouda", 56);
    add_item("4) Cheese", "Parmesan", 81);
    add_item("4) Cheese", "Blue cheese", 96);
}

void Menu::displayGeneralTypes() {
    for (const auto& category : menu) {
        std::cout << category.first << ":\n";
        std::cout << "\n";
    }

    cout << "5) Cancel ordering" << endl;

    string category="";

    cout << "Please choose a category: ";
    //cin >> category;
    if (isdigit(std::stoi( category ))) {
        switch (std::stoi( category )) {
            case 1:

                break;
            case 2:

                break;
            case 3:

                break;
            case 4:

                break;
            case 5:

                break;
            default:
                break;
        }
    }else{

    }

}

void Menu::displaySpecificTypes(int index) {
        for (const auto& category : menu) {
            //std::cout << category.first << ":\n";
            for (const auto& item : category.second) {
                std::cout << "- " << item.first << ": R" << item.second << "\n";
            }
            //std::cout << "\n";
        }

}
