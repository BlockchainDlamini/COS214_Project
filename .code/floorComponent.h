#ifndef FLOORCOMPONENT_H
#define FLOORCOMPONENT_H

#include <vector>
#include <memory>
#include <string>
#include "visitor.h"

class myIterator;
class depthFirstIterator;
class breadthFirstIterator;

/**
 * @brief The floorComponent class represents a component in the floor hierarchy.
 */
class floorComponent: public std::enable_shared_from_this<floorComponent>
{
    protected:
        int id; ///< The unique identifier of the floor component.

    public:
        /**
         * @brief Constructs a floorComponent with a specified ID.
         * @param id The unique identifier of the floor component.
         */
        floorComponent(int id);

        /**
         * @brief Adds a child component to the current component.
         * @param child The child component to be added.
         */
        virtual void add(std::shared_ptr<floorComponent> child) = 0;

        /**
         * @brief Removes a child component from the current component.
         * @param child The child component to be removed.
         */
        virtual void remove(std::shared_ptr<floorComponent> child) = 0;

        /**
         * @brief Gets the child component at a specified index.
         * @param index The index of the child component.
         * @return The shared pointer to the child component.
         */
        virtual std::shared_ptr<floorComponent> getChild(int index) = 0;

        /**
         * @brief Gets the number of children of the current component.
         * @return The number of children.
         */
        virtual int getNumChildren() = 0;

        /**
         * @brief Gets a depth-first iterator for the component hierarchy.
         * @return The shared pointer to the depth-first iterator.
         */
        virtual std::shared_ptr<myIterator> getDepthIterator() = 0;

        /**
         * @brief Gets a breadth-first iterator for the component hierarchy.
         * @return The shared pointer to the breadth-first iterator.
         */
        virtual std::shared_ptr<myIterator> getBreadthIterator() = 0;

        /**
         * @brief Gets a string representation of the component.
         * @return The string representation.
         */
        virtual std::string toString() = 0;

        /**
         * @brief Accepts a visitor for visiting the component.
         * @param visitor The visitor to be accepted.
         * @return The result of the visitation.
         */
        virtual int acceptVisitor(std::shared_ptr<visitor> visitor) = 0;

        /**
         * @brief Gets the unique identifier of the component.
         * @return The ID of the component.
         */
        virtual int getID();

        /**
         * @brief Destructs the floorComponent object.
         */
        virtual ~floorComponent(){};
};

#endif
