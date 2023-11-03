#ifndef SETVISIBILITYVISITOR_H
#define SETVISIBILITYVISITOR_H

#include "visitor.h"//BOBS ADDITION

/**
 * @brief The setVisibilityVisitor class provides a visitor for setting visibility.
 */
class setVisibilityVisitor: public visitor
{
    private:
        int newVisibility; ///< The new visibility value to be set.

    public:
        /**
         * @brief Constructs a setVisibilityVisitor object with a specified visibility value.
         * @param newVis The new visibility value to be set.
         */
        setVisibilityVisitor(int newVis);

        /**
         * @brief Visits a table in the floor plan to set visibility.
         * @param tablePtr The shared pointer to the table being visited.
         * @return An integer indicating success (1 for successful set, 0 for unsuccessful set).
         */
        int visitTable(std::shared_ptr<table> tablePtr);

        /**
         * @brief Visits a floor composite (e.g., a tile) in the floor plan to set visibility.
         * @param floorCompositePtr The shared pointer to the floor composite being visited.
         * @return An integer indicating success (1 for successful set, 0 for unsuccessful set).
         */
        int visitTile(std::shared_ptr<floorComposite> floorCompositePtr);

        /**
         * @brief Destructs the setVisibilityVisitor object.
         */
        ~setVisibilityVisitor(){}
};

#endif
