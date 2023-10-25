#include "MenuItemCommand.h"

MenuItemCommand::MenuItemCommand(shared_ptr<Kitchen> state) : state(state) {}

shared_ptr<Kitchen> MenuItemCommand::getState() {
    return state;
}
