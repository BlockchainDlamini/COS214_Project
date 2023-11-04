#include "ToppingsChef.h"
ToppingsChef::ToppingsChef()
{
    nextChef = make_shared<HeadChef>();
}
void ToppingsChef::handleOrder(int waiter_id, int customer_id, vector<shared_ptr<MenuItemCommand>> orders, vector<shared_ptr<FoodItem>>foods)
{
    for (vector<shared_ptr<MenuItemCommand>>::iterator it = orders.begin(); it != orders.end(); it++)
    {
        if (dynamic_pointer_cast<MakeTopping>((*it)))
        {
            cout << "****IN THE ---TOPPINGS CHEFF--- CHEFF COOKING!!!!!!!!" << endl;
            foods.push_back((*it)->execute());
        }
    }
    displayToppingsArt();
    nextChef->handleOrder(waiter_id,customer_id, foods);
}

shared_ptr<FoodItem> ToppingsChef::execute(shared_ptr<MenuItemCommand> val)
{

  
    if (dynamic_pointer_cast<MakeOlives>(val))
    {
        cout << "COOKED UP A OLIVE TOPPING" << endl;
        return make_shared<Olives>();
    }
    else if (dynamic_pointer_cast<MakeMushrooms>(val))
    {
        cout << "COOKED UP A MUSHROOMS TOPPING" << endl;
        return make_shared<Mushrooms>();
    }
    else if (dynamic_pointer_cast<MakeChicken>(val))
    {
        cout << "COOKED UP A CHICKEN TOPPING" << endl;
        return make_shared<Chicken>();
    }
    else if (dynamic_pointer_cast<MakeBeef>(val))
    {
        cout << "COOKED UP A BEEF TOPPING" << endl;
        return make_shared<Beef>();
    }
    else if (dynamic_pointer_cast<MakePeppers>(val))
    {
        cout << "COOKED UP A PEPPERS TOPPING" << endl;
        return make_shared<Peppers>();
    }
    else if (dynamic_pointer_cast<MakePepperoni>(val))
    {
        cout << "COOKED UP A PPEPPERONI TOPPINGS" << endl;
        return make_shared<Pepperoni>();
    }

    return 0;
}

void ToppingsChef::displayToppingsArt() {
    const std::string BROWN_COLOR = "\033[0;33m";
    const std::string RESET_COLOR = "\033[0m";
    std::string text = "Creating pizza toppings";

    int textWidth = 40; // Adjust the width as needed
    int padding = (textWidth - text.length()) / 2;
    std::cout << std::setfill('-') << std::setw(textWidth) << "" << std::setfill(' ') << std::endl;
    std::cout << std::setw(padding) << "" << text << std::setw(padding) << "" << std::endl;
    std::cout << std::setfill('-') << std::setw(textWidth) << "" << std::setfill(' ') << std::endl;

    std::ifstream file("topping.txt"); // Open the file for reading
    if (file.is_open()) { // Check if the file was opened successfully
        std::string line = "";
        // Read and display each line of the file with color
        while (std::getline(file, line)) {
            std::cout << BROWN_COLOR << line << RESET_COLOR << std::endl;
        }
        file.close(); // Close the file when done
    }
    else {
        std::cerr << "Failed to open the file." << std::endl;
    }

}