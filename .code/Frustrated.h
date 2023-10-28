#ifndef Frustrated_H
#define Frustrated_H

#include "EmotionState.h"

/**
 * @class Frustrated
 * @brief A concrete class representing a frustrated emotional state of a customer.
 */
class Frustrated : public EmotionState {
public:
    /**
     * @brief Default constructor for Frustrated.
     */
    Frustrated();

    /**
     * @brief Handle a change in the customer's emotional state.
     * @param customer A shared pointer to the customer whose state is changing.
     */
    void handleChange(std::shared_ptr<Customer> customer);

    /**
     * @brief Get the emotional state of the customer.
     * @return The name of the emotional state (Frustrated).
     */
    std::string getEmotion() {
        return emotion;
    }

    /**
     * @brief Get the tip amount associated with the frustrated emotional state.
     * @return The tip amount.
     */
    float getTip();
};

#endif
