#ifndef FINDSPACEVISITOR_H
#define FINDSPACEVISITOR_H

#include "getIsAvailableVisitor.h"//BOBS ADDITION
/**
 * @brief The findSpaceVisitor class provides a visitor for finding the available space in of each floorComponent.
 */
class findSpaceVisitor: public visitor
{
    public:
        /**
         * @brief Constructs a findSpaceVisitor object.
         */
        findSpaceVisitor():visitor(){}

        /**
         * @brief Visits a table and returns numbet of seats of the table if the table is visible.
         * @param tablePtr The shared pointer to the table being visited.
         * @return An integer indicating availability of space.
         */
        int visitTable(std::shared_ptr<table> tablePtr);

        /**
         * @brief Visits a floor composite. Always returns 0 since the floorComposites do not have number of seats
         * @param floorCompositePtr The shared pointer to the floorComposite being visited.
         * @return 0.
         */
        int visitTile(std::shared_ptr<floorComposite> floorCompositePtr);

        /**
         * @brief Destructs the findSpaceVisitor object.
         */
        ~findSpaceVisitor(){}
};

#endif
