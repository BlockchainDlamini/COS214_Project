#ifndef SETSPACEVISITOR_H
#define SETSPACEVISITOR_H

#include "visitor.h"
#include <memory>

/**
 * @brief The setSpaceVisitor class provides a visitor for setting space value.
 */
class setSpaceVisitor: public visitor
{
    private:
        int space; ///< The new space value to be set.

    public:
        /**
         * @brief Constructs a setSpaceVisitor object with a specified space value.
         * @param newSpace The new space value to be set.
         */
        setSpaceVisitor(int newSpace);

        /**
         * @brief Visits a table in the floor plan to set space value.
         * @param tablePtr The shared pointer to the table being visited.
         * @return An integer indicating success (1 for successful set, 0 for unsuccessful set).
         */
        int visitTable(std::shared_ptr<table> tablePtr);

        /**
         * @brief Visits a floor composite (e.g., a tile) in the floor plan to set space value.
         * @param floorCompositePtr The shared pointer to the floor composite being visited.
         * @return An integer indicating success (1 for successful set, 0 for unsuccessful set).
         */
        int visitTile(std::shared_ptr<floorComposite> floorCompositePtr);

        /**
         * @brief Destructs the setSpaceVisitor object.
         */
        ~setSpaceVisitor(){};
};

#endif
