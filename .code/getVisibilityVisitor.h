#ifndef GETVISIBILITYVISITOR_h
#define GETVISIBILITYVISITOR_h

#include "visitor.h"
#include <memory>

/**
 * @brief The getVisibilityVisitor class provides a visitor for determining visibility.
 */
class getVisibilityVisitor: public visitor
{
    public:
        /**
         * @brief Constructs a getVisibilityVisitor object.
         */
        getVisibilityVisitor():visitor(){}

        /**
         * @brief Visits a table in the floor plan to determine visibility.
         * @param tablePtr The shared pointer to the table being visited.
         * @return An integer indicating visibility (1 for visible, 0 for not visible).
         */
        int visitTable(std::shared_ptr<table> tablePtr);

        /**
         * @brief Visits a floor composite (e.g., a tile) in the floor plan to determine visibility.
         * @param floorCompositePtr The shared pointer to the floor composite being visited.
         * @return An integer indicating visibility (1 for visible, 0 for not visible).
         */
        int visitTile(std::shared_ptr<floorComposite> floorCompositePtr);

        /**
         * @brief Destructs the getVisibilityVisitor object.
         */
        ~getVisibilityVisitor(){}
};

#endif
