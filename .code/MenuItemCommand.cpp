/*@file MenuItemCommand.cpp
 *@brief contains the MenuItemCommand class
 *       which is the base class for all the
 *       commands that can be executed by the
 *       kitchen
 @bug No known bugs.
*/

#include "MenuItemCommand.h"
using namespace std;

MenuItemCommand::MenuItemCommand() {}

shared_ptr<Kitchen> MenuItemCommand::getState() {
    return state;
}
