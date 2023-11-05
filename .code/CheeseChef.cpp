#include "CheeseChef.h"

CheeseChef::CheeseChef()
{
    nextChef = make_shared<SauceChef>();
}

void CheeseChef::displayCheeseArt() {
    const std::string YELLOW_COLOR = "\033[1;33m";
    const std::string RESET_COLOR = "\033[0m";
    std::string text = "Creating pizza cheese";

    int textWidth = 40; // Adjust the width as needed
    int padding = (textWidth - text.length()) / 2;
    std::cout << std::setfill('-') << std::setw(textWidth) << "" << std::setfill(' ') << std::endl;
    std::cout << std::setw(padding) << "" << text << std::setw(padding) << "" << std::endl;
    std::cout << std::setfill('-') << std::setw(textWidth) << "" << std::setfill(' ') << std::endl;

    std::ifstream file("cheese.txt"); // Open the file for reading
    if (file.is_open()) { // Check if the file was opened successfully
        std::string line = "";
        // Read and display each line of the file with color
        while (std::getline(file, line)) {
            std::cout << YELLOW_COLOR << line << RESET_COLOR << std::endl;
        }
        file.close(); // Close the file when done
    }
    else {
        std::cerr << "Failed to open the file." << std::endl;
    }
}


void CheeseChef::handleOrder(int waiter_id, int customer_id, vector<shared_ptr<MenuItemCommand>> orders, vector<shared_ptr<FoodItem>>foods)
{
    //cout << "CHEF_ADDRESS::::::: " << this << endl;
    for (vector<shared_ptr<MenuItemCommand>>::iterator it = orders.begin(); it != orders.end(); it++)
    {
        if (dynamic_pointer_cast<MakeCheese>((*it)))
        {
            cout << "****IN THE ---CHEESE--- CHEFF COOKING!!!!!!!!" << endl;
            foods.push_back((*it)->execute());
        }
    }
    displayCheeseArt();
    nextChef->handleOrder(waiter_id, customer_id, orders, foods);
}

shared_ptr<FoodItem> CheeseChef::execute(MenuItemCommand* val)
{
    if (dynamic_cast<MakeMozzarella*>(val))
    {
        cout << "COOKED UP A MOZZARELLA CHEESE" << endl;
        return make_shared<Mozzarella>();
    }
    else if (dynamic_cast<MakeCheddar*>(val))
    {
        cout << "COOKED UP A CHEDDAR CHEESE" << endl;
        return make_shared<Cheddar>();
    }
    else if (dynamic_cast<MakeGouda*>(val))
    {
        cout << "COOKED UP A GOUDA CHEESE" << endl;
        return make_shared<Gouda>();
    }
    else if (dynamic_cast<MakeParmesan*>(val))
    {
        cout << "COOKED UP A PARMESAN CHEESE" << endl;
        return make_shared<Parmesan>();
    }
    else if (dynamic_cast<MakeBlueCheese*>(val))
    {
        cout << "COOKED UP A BLUCHEESE" << endl;
        return make_shared<BlueCheese>();
    }

    return 0;
}