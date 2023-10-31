#ifndef BREADTHFIRSTITERATOR_H
#define BREADTHFIRSTITERATOR_H

#include "iterator.h"

/**
 * @brief The breadthFirstIterator class provides an iterator for traversing a tree in breadth-first order.
 */
class breadthFirstIterator: public myIterator
{
    private:
        std::queue<std::shared_ptr<floorComponent>> flattenedTree; ///< Queue to store flattened tree nodes.

        /**
         * @brief Flattens the tree for breadth-first traversal.
         * @param currNode The current node being processed.
         */
        void treeFlatten(std::shared_ptr<floorComponent> currNode);

        /**
         * @brief Calculates the height of the tree starting from the specified node.
         * @param curr The current node being processed.
         * @return The height of the tree.
         */
        int height(std::shared_ptr<floorComponent> curr);

        /**
         * @brief Pushes nodes from the current level to the flattened tree.
         * @param hd The head node of the current level.
         * @param level The current level being processed.
         */
        void pushCurrentLevel(std::shared_ptr<floorComponent> hd, int level);

    public:
        /**
         * @brief Constructs a breadthFirstIterator with the specified head node.
         * @param head The head node of the tree to be iterated.
         */
        breadthFirstIterator(std::shared_ptr<floorComponent> head);

        /**
         * @brief Returns the first item in the iteration.
         * @return The first item.
         */
        std::shared_ptr<floorComponent> first() {return myIterator::first();};

        /**
         * @brief Moves to the next item in the iteration.
         */
        void next() {};

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
         * @brief Destructs the breadthFirstIterator.
         */
        ~breadthFirstIterator();
};

#endif
