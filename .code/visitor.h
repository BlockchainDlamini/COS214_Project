#ifndef VISITOR_H
#define VISITOR_H

#include <memory>

class floorComposite;
class table;

/**
 * @brief The visitor class provides an interface for visiting elements in a floor plan.
 */
class visitor
{
    public:
        /**
         * @brief Constructs a visitor object.
         */
        visitor(){}

        /**
         * @brief Visits a table in the floor plan.
         * @param tablePtr The shared pointer to the table being visited.
         * @return An integer result of the visitation.
         */
        virtual int visitTable(std::shared_ptr<table> tablePtr) = 0;

        /**
         * @brief Visits a floor composite (e.g., a tile) in the floor plan.
         * @param floorCompositePtr The shared pointer to the floor composite being visited.
         * @return An integer result of the visitation.
         */
        virtual int visitTile(std::shared_ptr<floorComposite> floorCompositePtr) = 0;

        /**
         * @brief Destructs the visitor object.
         */
        virtual ~visitor(){}
};

#endif
