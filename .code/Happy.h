#ifndef Happy_H
#define Happy_H

#include "Disgruntaled.h"//BOBS ADDITION

/**
 * @class Happy
 * @brief A concrete class representing a happy emotional state of a customer.
 */
class Happy : public EmotionState {
public:
    /**
     * @brief Default constructor for Happy.
     */
    Happy();

    /**
     * @brief Handle a change in the customer's emotional state.
     * @param customer A shared pointer to the customer whose state is changing.
     */
    void handleChange(Customer* context);

    /**
     * @brief Get the emotional state of the customer.
     * @return The name of the emotional state (Happy).
     */
    std::string getEmotion() {
        return emotion;
    }

    /**
     * @brief Get the tip amount associated with the happy emotional state.
     * @return The tip amount.
     */
    float getTip();
};

#endif
