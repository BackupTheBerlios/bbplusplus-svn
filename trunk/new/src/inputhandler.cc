#include "../includes/inputhandler.h"
#include <iostream>
#include <cstdlib>

	
InputHandler::InputHandler(Menu* m) {
	menu = new Menu(m);
}

InputHandler::~InputHandler() {
	delete menu;
}

/*
 * Reads input and checks whether the entered value has a match. If so, returns the next state to choose.
 * Should input not be valid (Say a character or string instead of an integer), it is ignored and a new value
 * is to be entered.
 */
int InputHandler::getInput() {
	std::cout << "|> ";
    while(!(std::cin >> input) || !(menu->getEntries().find(input) != menu->getEntries().end())) {
       	std::cout << "Bad entry try again\n" << "|> ";
       	std::cin.clear();
       	std::cin.ignore(100, '\n');
    }
    return menu->getEntries()[input].getState();
}

/*
 * Must delete previously handled menu
 */
void InputHandler::setNewHandled(Menu* m) {
	delete menu;
	menu = new Menu(m);
}
