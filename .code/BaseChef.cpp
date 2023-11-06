#include "BaseChef.h"
#include <thread>

BaseChef::BaseChef()
{
    nextChef = make_shared<CheeseChef>();
}
void BaseChef::handleOrder(int waiter_id, int customer_id, vector<shared_ptr<MenuItemCommand>> orders, vector<shared_ptr<FoodItem>>foods)
{
    for (vector<shared_ptr<MenuItemCommand>>::iterator it = orders.begin(); it != orders.end(); it++)
    {
        if (dynamic_pointer_cast<MakeBase>((*it)))
        {
            foods.push_back((*it)->execute());
        }
    }
    displayBaseArt();
    nextChef->handleOrder(waiter_id,customer_id,orders, foods);
}

shared_ptr<FoodItem> BaseChef::execute(MenuItemCommand* val, string t)
{
    if (dynamic_cast<MakeStuffedCrust*>(val))
    {
        cout << "COOKED UP A STUFFED CRUST" << endl;
        return make_shared<StuffedCrust>(t);
    }
    else if (dynamic_cast<MakeThinCrust*>(val))
    {
        cout << "COOKED UP A THIN CRUST" << endl;
        return make_shared<ThinCrust>(t);
    }
    else if (dynamic_cast<MakeDoubleDecker*>(val))
    {
        cout << "COOKED UP A DOUBLE-DECKER CRUST" << endl;
        return make_shared<DoubleDecker>(t);
    }
    else if (dynamic_cast<MakeBoiledCrust*>(val))
    {
        cout << "COOKED UP A BOILED CRUST" << endl;
        return make_shared<Boiled>(t);
    }
    else if (dynamic_cast<MakeDeepDish*>(val))
    {
        cout << "COOKED UP A DEEPDISH CRUST" << endl;
        return make_shared<DeepDish>(t);
    }

    return 0;
}

//void BaseChef::displayBaseArt() {
//    const std::string BROWN_COLOR = "\033[0;33m";
//    const std::string RESET_COLOR = "\033[0m";
//    std::string text = "Creating pizza base";
//
//    int textWidth = 40; // Adjust the width as needed
//    int padding = (textWidth - text.length()) / 2;
//    std::cout << std::setfill('-') << std::setw(textWidth) << "" << std::setfill(' ') << std::endl;
//    std::cout << std::setw(padding) << "" << text << std::setw(padding) << "" << std::endl;
//    std::cout << std::setfill('-') << std::setw(textWidth) << "" << std::setfill(' ') << std::endl;
//
//    std::ifstream file("base.txt"); // Open the file for reading
//    if (file.is_open()) { // Check if the file was opened successfully
//        std::string line = "";
//        // Read and display each line of the file with color
//        while (std::getline(file, line)) {
//            std::cout << BROWN_COLOR << line << RESET_COLOR << std::endl;
//        }
//        file.close(); // Close the file when done
//    }
//    else {
//        std::cerr << "Failed to open the file." << std::endl;
//    }
//}

void BaseChef::displayBaseArt() {
    const std::string RED_COLOR = "\033[0;31m";
    const std::string BROWN_COLOR = "\033[0;33m";
    const std::string RESET_COLOR = "\033[0m";
    std::string text = "Creating pizza base";

    int textWidth = 40; // Adjust the width as needed
    int padding = (textWidth - text.length()) / 2;
    std::cout << std::setfill('-') << std::setw(textWidth) << "" << std::setfill(' ') << std::endl;
    std::cout << std::setw(padding) << "" << text << std::setw(padding) << "" << std::endl;
    std::cout << std::setfill('-') << std::setw(textWidth) << "" << std::setfill(' ') << std::endl;

    std::ifstream file("base.txt"); // Open the file for reading
    if (file.is_open()) { // Check if the file was opened successfully
        std::string line = "";
        // Read and display each line of the file with "(_)" in red color
        while (std::getline(file, line)) {
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
            size_t pos = 0;
            while ((pos = line.find("(_)", pos)) != std::string::npos) {
                line.replace(pos, 3, RED_COLOR + "(_)" + BROWN_COLOR);
                pos += 8; // Move past the replaced portion to avoid infinite loop
            }
            std::cout << BROWN_COLOR << line << RESET_COLOR << std::endl;
        }
        file.close(); // Close the file when done
    }
    else {
        std::cerr << "Failed to open the file." << std::endl;
    }
}