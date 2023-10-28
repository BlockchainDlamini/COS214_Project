#ifndef EmotionState_H
#define EmotionState_H
#include "Customer.h"
#include <random>
#include <memory>
#include <string>
class Customer;
class EmotionState
{
protected:
    std::shared_ptr<Customer> context;
    float tip;
    std::string emotion;

public:
    EmotionState();
    // virtual bool payBill() = 0;
    virtual void handleChange(std::shared_ptr<Customer> customer) = 0;
   // virtual std::shared_ptr<Customer> getState() = 0;
    virtual float getTip() = 0;
    virtual std::string getEmotion() = 0;
    int getRandomNumber()
    {
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
