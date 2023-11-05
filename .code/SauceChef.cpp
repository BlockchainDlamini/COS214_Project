#include "SauceChef.h"

SauceChef::SauceChef()
{
    nextChef = make_shared<ToppingsChef>();
}
void SauceChef::handleOrder(int waiter_id, int customer_id, vector<shared_ptr<MenuItemCommand>> orders, vector<shared_ptr<FoodItem>>foods)
{
    cout << "CHEF_ADDRESS::::::: " << this << endl;
    for (vector<shared_ptr<MenuItemCommand>>::iterator it = orders.begin(); it != orders.end(); it++)
    {
        if (dynamic_pointer_cast<MakeSauce>((*it)))
        {
            cout << "****IN THE ---SAUCECHEFF--- CHEFF COOKING!!!!!!!!" << endl;

            foods.push_back((*it)->execute());
        }
    }
    displaySauceArt();
    nextChef->handleOrder(waiter_id, customer_id, orders, foods);
}

shared_ptr<FoodItem> SauceChef::execute(MenuItemCommand* val)
{
    if (dynamic_cast<MakeSweetChilli*>(val))
    {
        cout << "COOKED UP A SWEETCHILLI SAUCE" << endl;
        return make_shared<SweetChilli>();
    }
    else if (dynamic_cast<MakeSweetChilli*>(val))
    {
        cout << "COOKED UP A RANCH SAUCE" << endl;
        return make_shared<Ranch>();
    }
    else if (dynamic_cast<MakeSweetChilli*>(val))
    {
        cout << "COOKED UP A TOMATOPASTE SAUCE" << endl;
        return make_shared<TomatoPaste>();
    }
    else if (dynamic_cast<MakeChutneySauce*>(val))
    {
        cout << "COOKED UP A CHUTNEY SAUCE" << endl;
        return make_shared<Chutney>();
    }
  
    return 0;
}


void SauceChef::displaySauceArt() {
    const std::string RED_COLOR = "\033[1;31m";
    const std::string RESET_COLOR = "\033[0m";
    std::string text = "Creating pizza sauce";

    int textWidth = 40; // Adjust the width as needed
    int padding = (textWidth - text.length()) / 2;
    std::cout << std::setfill('-') << std::setw(textWidth) << "" << std::setfill(' ') << std::endl;
    std::cout << std::setw(padding) << "" << text << std::setw(padding) << "" << std::endl;
    std::cout << std::setfill('-') << std::setw(textWidth) << "" << std::setfill(' ') << std::endl;

    std::ifstream file("sauce.txt"); // Open the file for reading
    if (file.is_open()) { // Check if the file was opened successfully
        std::string line = "";
        // Read and display each line of the file with color
        while (std::getline(file, line)) {
            std::cout << RED_COLOR << line << RESET_COLOR << std::endl;
        }
        file.close(); // Close the file when done
    }
    else {
        std::cerr << "Failed to open the file." << std::endl;
    }

}