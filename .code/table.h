#ifndef TABLE_H
#define TABLE_H

#include "floorComponent.h"
#include "Customer.h"
#include <vector>
#include <memory>

/**
 * @brief The table class represents a table in the restaurant floor.
 */
class table: public floorComponent
{
    private:
        std::vector<std::shared_ptr<Customer>> customers; ///< Vector of customers seated at the table.
        int space; ///< The available space at the table.
        bool hasCustomers; ///< Flag indicating if the table has customers.
        bool isVisible; ///< Flag indicating if the table is visible.
        bool isMerged; ///< Flag indicating if the table is merged with adjacent tables.

    public:
        /**
         * @brief Constructs a table object with a specified ID and space.
         * @param id The unique identifier of the table.
         * @param space The available space at the table.
         */
        table(int id, int space);

        /**
         * @brief Adds a child component to the table (not supported for tables).
         * @param child The child component to be added.
         */
        void add(std::shared_ptr<floorComponent> child);

        /**
         * @brief Removes a child component from the table (not supported for tables).
         * @param child The child component to be removed.
         */
        void remove(std::shared_ptr<floorComponent> child);

        /**
         * @brief Gets the child component at a specified index (not supported for tables).
         * @param index The index of the child component.
         * @return The shared pointer to the child component.
         */
        std::shared_ptr<floorComponent> getChild(int index);

        /**
         * @brief Gets the number of children of the table (always 0 for tables).
         * @return The number of children.
         */
        int getNumChildren();

        /**
         * @brief Gets the visibility status of the table.
         * @return True if the table is visible, false otherwise.
         */
        bool getIsVisible();

        /**
         * @brief Sets the visibility status of the table.
         * @param vis The new visibility status to be set.
         */
        void setIsVisible(bool vis);

        /**
         * @brief Gets the merging status of the table.
         * @return True if the table is merged, false otherwise.
         */
        bool getIsMerged();

        /**
         * @brief Sets the merging status of the table.
         * @param merge The new merging status to be set.
         */
        void setIsMerged(bool merge);

        /**
         * @brief Checks if there is available space at the table.
         * @return True if space is available, false otherwise.
         */
        bool getIsSpaceAvailable();

        /**
         * @brief Sets the availability of space at the table.
         * @param available The new availability status to be set.
         */
        void setIsSpaceAvailable(bool available);

        /**
         * @brief Gets a depth-first iterator for the table (not supported for tables).
         * @return The shared pointer to the depth-first iterator.
         */
        std::shared_ptr<myIterator> getDepthIterator();

        /**
         * @brief Gets a breadth-first iterator for the table (not supported for tables).
         * @return The shared pointer to the breadth-first iterator.
         */
        std::shared_ptr<myIterator> getBreadthIterator();

        /**
         * @brief Adds new customers to the table.
         * @param newCustomers The vector of shared pointers to customers.
         */
        void newCustomers(std::vector<std::shared_ptr<Customer>> newCustomers);

        /**
         * @brief Removes customers from the table.
         */
        void removeCustomers();

        /**
         * @brief Gets the vector of customers seated at the table.
         * @return The vector of shared pointers to customers.
         */
        std::vector<std::shared_ptr<Customer>> getCustomers();

        /**
         * @brief Calculates the available space at the table.
         * @return The available space.
         */
        int spaceAvailable();

        /**
         * @brief Sets the space available at the table.
         * @param newSpace The new space value to be set.
         */
        void setSpace(int newSpace);

        /**
         * @brief Gets a string representation of the table.
         * @return The string representation.
         */
        virtual std::string toString();

        /**
         * @brief Accepts a visitor for visiting the table.
         * @param visitor The visitor to be accepted.
         * @return The result of the visitation.
         */
        int acceptVisitor(std::shared_ptr<visitor> visitor);

        /**
         * @brief Destructs the table object.
         */
        ~table();
};

#endif
