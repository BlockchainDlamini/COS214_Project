#ifndef SETMERGEVISITOR_H
#define SETMERGEVISITOR_H

#include "visitor.h"
#include <memory>

/**
 * @brief The setMergeVisitor class provides a visitor for setting merging status.
 */
class setMergeVisitor: public visitor
{
    private:
        int merge; ///< The new merging status to be set.

    public:
        /**
         * @brief Constructs a setMergeVisitor object with a specified merging status.
         * @param newSpace The new merging status to be set.
         */
        setMergeVisitor(int newSpace);

        /**
         * @brief Visits a table in the floor plan to set merging status.
         * @param tablePtr The shared pointer to the table being visited.
         * @return An integer indicating success (1 for successful set, 0 for unsuccessful set).
         */
        int visitTable(std::shared_ptr<table> tablePtr);

        /**
         * @brief Visits a floor composite (e.g., a tile) in the floor plan to set merging status.
         * @param floorCompositePtr The shared pointer to the floor composite being visited.
         * @return An integer indicating success (1 for successful set, 0 for unsuccessful set).
         */
        int visitTile(std::shared_ptr<floorComposite> floorCompositePtr);

        /**
         * @brief Destructs the setMergeVisitor object.
         */
        ~setMergeVisitor(){};
};

#endif
