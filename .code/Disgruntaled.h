#ifndef Disgruntaled_H
#define Disgruntaled_H

#include "Satisfied.h"//BOBS ADDITION

/**
 * @class Disgruntled
 * @brief A concrete class representing a disgruntled emotional state of a customer.
 */
class Disgruntaled : public EmotionState {
public:
    /**
     * @brief Default constructor for Disgruntled.
     */
    Disgruntaled();

    /**
     * @brief Handle a change in the customer's emotional state.
     * @param customer A shared pointer to the customer whose state is changing.
     */
    void handleChange(Customer* context);

    /**
     * @brief Get the emotional state of the customer.
     * @return The name of the emotional state (Disgruntled).
     */
    std::string getEmotion() {
        return emotion;
    }

    /**
     * @brief Get the tip amount associated with the disgruntled emotional state.
     * @return The tip amount.
     */
    float getTip();
};

#endif
