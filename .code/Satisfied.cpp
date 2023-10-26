#include "Satisfied.h"
Satisfied::Satisfied()
{
    emotion = "Satisfied";
}
float Satisfied::getTip()
{
    tip = 0.10;
    return tip;
}
void Satisfied ::handleChange(std::shared_ptr<Customer> context)
{
    std::shared_ptr<EmotionState> ptr;
    int num = getRandomNumber();
    if (num <= 25)
    {
        ptr = make_shared<Satisfied>();
    }
    else if (num > 25 && num <= 50)
    {
        ptr = make_shared<Disgruntaled>();
    }
    else if (num > 50 && num <= 75)
    {
        ptr = make_shared<Frustrated>();
    }
    else
    {
        ptr = make_shared<Happy>();
    }
    context->setEmotionState(ptr);
}