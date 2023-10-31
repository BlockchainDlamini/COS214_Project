#ifndef DEPTHFIRSTITERATOR_H
#define DEPTHFIRSTITERATOR_H

#include "iterator.h"

/**
 * @brief The depthFirstIterator class provides an iterator for traversing a tree in depth-first order.
 */
class depthFirstIterator: public myIterator
{
    private:
        /**
         * @brief Flattens the tree for depth-first traversal.
         * @param currNode The current node being processed.
         */
        void treeFlatten(std::shared_ptr<floorComponent> currNode);

    public:
        /**
         * @brief Constructs a depthFirstIterator with the specified head node.
         * @param head The head node of the tree to be iterated.
         */
        depthFirstIterator(std::shared_ptr<floorComponent> head);

        /**
         * @brief Returns the first item in the iteration.
         * @return The first item.
         */
        std::shared_ptr<floorComponent> first() {return myIterator::first();};

        /**
         * @brief Moves to the next item in the iteration.
         */
        void next() {return myIterator::next();};

        /**
         * @brief Returns the current item in the iteration.
         * @return The current item.
         */
        std::shared_ptr<floorComponent> currentItem() {return myIterator::currentItem();};

        /**
         * @brief Checks if there are more items in the iteration.
         * @return True if there are more items, false otherwise.
         */
        bool hasNext() {return myIterator::hasNext();};

        /**
         * @brief Destructs the depthFirstIterator.
         */
        ~depthFirstIterator();
};

#endif
