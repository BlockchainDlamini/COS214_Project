#ifndef Satisfied_H
#define Satisfied_H

#include "Frustrated.h"//BOBS ADDITION

/**
 * @class Satisfied
 * @brief A concrete class representing a satisfied emotional state of a customer.
 */
class Satisfied : public EmotionState {
public:
    /**
     * @brief Default constructor for Satisfied.
     */
    Satisfied();

    /**
     * @brief Handle a change in the customer's emotional state.
     * @param customer A shared pointer to the customer whose state is changing.
     */
    void handleChange(Customer* context);

    /**
     * @brief Get the emotional state of the customer.
     * @return The name of the emotional state (Satisfied).
     */
    std::string getEmotion() {
        return emotion;
    }

    /**
     * @brief Get the tip amount associated with the satisfied emotional state.
     * @return The tip amount.
     */
    float getTip();
};

#endif
