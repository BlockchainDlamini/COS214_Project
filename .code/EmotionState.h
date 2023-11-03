#ifndef EmotionState_H
#define EmotionState_H

#include "Tab.h"
#include <random>
#include <memory>
#include <string>

class Customer;
//forward declaration
/**
 * @class EmotionState
 * @brief Abstract base class representing the emotional state of a customer.
 */
class EmotionState {
protected:
    std::shared_ptr<Customer> context; ///< The customer context associated with this emotion state.
    float tip; ///< The tip amount associated with this emotion state.
    std::string emotion; ///< The emotional state's name.

public:
    /**
     * @brief Default constructor for EmotionState.
     */
    EmotionState();

    /**
     * @brief Handle a change in the customer's emotional state.
     * @param customer A shared pointer to the customer whose state is changing.
     */
    virtual void handleChange(Customer* context) = 0;

    /**
     * @brief Get the tip amount associated with the emotional state.
     * @return The tip amount.
     */
    virtual float getTip() = 0;

    /**
     * @brief Get the name of the emotional state.
     * @return The name of the emotional state.
     */
    virtual std::string getEmotion() = 0;

    /**
     * @brief Generate a random number between 0 and 100.
     * @return A random number between 0 and 100.
     */
    int getRandomNumber() {
        // Seed the random number generator with a value based on the current time
        std::random_device rd;
        std::mt19937 gen(rd());

        // Define the range (0 to 100)
        std::uniform_int_distribution<int> dist(0, 100);

        // Generate a random number
        int randomNum = dist(gen);

        return randomNum;
    }
};

#endif
