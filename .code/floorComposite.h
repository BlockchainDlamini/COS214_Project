#ifndef FLOORCOMPOSITE_H
#define FLOORCOMPOSITE_H
#include "floorComponent.h"//BOBS ADDITION
/**
 * @brief The floorComposite class represents a composite floor component.
 */
class floorComposite: public floorComponent
{
    protected:
        std::vector<std::shared_ptr<floorComponent>> next; ///< Vector of child components.

    public:
        /**
         * @brief Constructs a floorComposite with a specified ID.
         * @param id The unique identifier of the floorComposite.
         */
        floorComposite(int id);

        /**
         * @brief Adds a child component to the composite.
         * @param child The child component to be added.
         */
        void add(std::shared_ptr<floorComponent> child);

        /**
         * @brief Removes a child component from the composite.
         * @param child The child component to be removed.
         */
        void remove(std::shared_ptr<floorComponent> child);

        /**
         * @brief Gets the child component at a specified index.
         * @param index The index of the child component.
         * @return The shared pointer to the child component.
         */
        std::shared_ptr<floorComponent> getChild(int index);

        /**
         * @brief Gets the number of children of the composite.
         * @return The number of children.
         */
        int getNumChildren();

        /**
         * @brief Gets a depth-first iterator for the composite hierarchy.
         * @return The shared pointer to the depth-first iterator.
         */
        std::shared_ptr<myIterator> getDepthIterator();

        /**
         * @brief Gets a breadth-first iterator for the composite hierarchy.
         * @return The shared pointer to the breadth-first iterator.
         */
        //std::shared_ptr<myIterator> getBreadthIterator();

        /**
         * @brief Gets a string representation of the composite.
         * @return The string representation.
         */
        virtual std::string toString();

        /**
         * @brief Accepts a visitor for visiting the composite.
         * @param visitor The visitor to be accepted.
         * @return The result of the visitation.
         */
        int acceptVisitor(std::shared_ptr<visitor> visitor);

        /**
         * @brief Destructs the floorComposite object.
         */
        virtual ~floorComposite();    
};

#endif

