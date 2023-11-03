#ifndef GETMERGEVISITOR_H
#define GETMERGEVISITOR_H

#include "getVisibilityVisitor.h"//BOBS ADDITION
/**
 * @brief The getMergeVisitor class provides a visitor for merging elements.
 */
class getMergeVisitor: public visitor
{
    public:
        /**
         * @brief Constructs a getMergeVisitor object.
         */
        getMergeVisitor():visitor(){}

        /**
         * @brief Visits a table in the floor plan for merging.
         * @param tablePtr The shared pointer to the table being visited.
         * @return An integer indicating success (1 for successful merge, 0 for unsuccessful merge).
         */
        int visitTable(std::shared_ptr<table> tablePtr);

        /**
         * @brief Visits a floor composite (e.g., a tile) in the floor plan for merging.
         * @param floorCompositePtr The shared pointer to the floor composite being visited.
         * @return An integer indicating success (1 for successful merge, 0 for unsuccessful merge).
         */
        int visitTile(std::shared_ptr<floorComposite> floorCompositePtr);

        /**
         * @brief Destructs the getMergeVisitor object.
         */
        ~getMergeVisitor(){}
};

#endif
