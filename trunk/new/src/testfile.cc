#include "../includes/menuitem.h"
#include "../includes/menu.h"
#include "../includes/menudisplayer.h"
#include "../includes/states.h"
#include "../includes/inputhandler.h"
#include "../includes/commands.h"
#include <iostream>
using namespace std;

int main()
{	
	/*
	 *  System commands used by BashBurn++
	 * We use a smart pointer to not have to worry about deleting it later on.
	 */
	auto_ptr<Commands> executer = (auto_ptr<Commands>)Commands::Instance();
	
	MenuDisplayer displayer;
	InputHandler handler;

	/*
	 * Here we create the different states of the program, and pass along
	 * the commands used, the menu displayer and the input handler.
	 */
	States states(*executer, displayer, handler);
	
	// Let it rip!
	int nextState;
	/*
	 * Here we clear the screen, display the menu and recieves user input.
	 * Depending on what the input is, we either exit or set our next state
	 * (Which could be a menu or an action) and continue.
	 */
	while(true) {
		executer->clearScreen();
		states.show();
		nextState = states.getInput();
		if(nextState == EXIT) {
			return 0;
		} else {
			states.setState(nextState);
		}
	}
}
