#ifndef ISAVAILABLEVISITOR_H
#define ISAVAILABLEVISITOR_H

#include "visitor.h"
#include <memory>

/**
 * @brief The getIsAvailableVisitor class provides a visitor for checking availability of elements.
 */
class getIsAvailableVisitor: public visitor
{
    public:
        /**
         * @brief Constructs a getIsAvailableVisitor object.
         */
        getIsAvailableVisitor():visitor(){}

        /**
         * @brief Visits a table in the floor plan to check availability.
         * @param tablePtr The shared pointer to the table being visited.
         * @return An integer indicating availability (1 for available, 0 for not available).
         */
        int visitTable(std::shared_ptr<table> tablePtr);

        /**
         * @brief Visits a floor composite (e.g., a tile) in the floor plan to check availability.
         * @param floorCompositePtr The shared pointer to the floor composite being visited.
         * @return An integer indicating availability (1 for available, 0 for not available).
         */
        int visitTile(std::shared_ptr<floorComposite> floorCompositePtr);

        /**
         * @brief Destructs the getIsAvailableVisitor object.
         */
        ~getIsAvailableVisitor(){}
};

#endif
