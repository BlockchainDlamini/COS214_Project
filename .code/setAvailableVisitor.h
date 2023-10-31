#ifndef GETAVAILABLEVISITOR_H
#define GETAVAILABLEVISITOR_H

#include "visitor.h"
#include <memory>

/**
 * @brief The setIsAvailableVisitor class provides a visitor for setting availability.
 */
class setIsAvailableVisitor: public visitor
{
    private:
        bool newVis; ///< The new availability value to be set.

    public:
        /**
         * @brief Constructs a setIsAvailableVisitor object.
         * @param vis The new availability value to be set.
         */
        setIsAvailableVisitor(bool vis):visitor(){newVis=vis;};

        /**
         * @brief Visits a table in the floor plan to set availability.
         * @param tablePtr The shared pointer to the table being visited.
         * @return An integer indicating success (1 for successful set, 0 for unsuccessful set).
         */
        int visitTable(std::shared_ptr<table> tablePtr);

        /**
         * @brief Visits a floor composite (e.g., a tile) in the floor plan to set availability.
         * @param floorCompositePtr The shared pointer to the floor composite being visited.
         * @return An integer indicating success (1 for successful set, 0 for unsuccessful set).
         */
        int visitTile(std::shared_ptr<floorComposite> floorCompositePtr);

        /**
         * @brief Destructs the setIsAvailableVisitor object.
         */
        ~setIsAvailableVisitor(){};
};

#endif
