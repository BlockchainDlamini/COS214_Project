#ifndef MYITERATOR_H
#define MYITERATOR_H

#include "PredefinedOrders.h"//BOBS ADDITION

/**
 * @brief The myIterator class provides an abstract iterator interface for traversing a tree.
 */
class floorComponent;
class myIterator
{
    protected:
        std::queue<std::shared_ptr<floorComponent>> flattenedTree; ///< Queue to store flattened tree nodes.
        std::shared_ptr<floorComponent> head; ///< The head of the tree.
        std::shared_ptr<floorComponent> current; ///< The current node in the iteration.

        /**
         * @brief Flattens the tree for traversal.
         * @param currNode The current node being processed.
         */
        virtual void treeFlatten(std::shared_ptr<floorComponent> currNode) = 0;

    public:
        /**
         * @brief Constructs a myIterator object with a specified head node.
         * @param head The head node of the tree to be iterated.
         */
        myIterator(std::shared_ptr<floorComponent> head);

        /**
         * @brief Gets the first item in the iteration.
         * @return The first item.
         */
        virtual std::shared_ptr<floorComponent> first();

        /**
         * @brief Moves to the next item in the iteration.
         */
        virtual void next(); 

        /**
         * @brief Gets the current item in the iteration.
         * @return The current item.
         */
        virtual std::shared_ptr<floorComponent> currentItem();

        /**
         * @brief Checks if there are more items in the iteration.
         * @return True if there are more items, false otherwise.
         */
        virtual bool hasNext();

        /**
         * @brief Destructs the myIterator object.
         */
        virtual ~myIterator();
};

#endif
