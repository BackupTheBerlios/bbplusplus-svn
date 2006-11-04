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

	// System commands used by BashBurn++
	Commands executer;

	/*
	 * Here we create not only the different states, but also the displayer used to print the menus
	 * and the input handler used to get input from the user. All we have to do in the switch statement
	 * below is to set the new handled state.
	 */
	States states(executer);
	
	// Let it rip!
	int nextState;
	/*
	 * Here we clear the screen, display the menu and recieves user input.
	 * Depending on what the input is, we either exit or set our next state
	 * (Which could be a menu or an action) and continue.
	 */
	while(true) {
		executer.clearScreen();
		states.show();
		nextState = states.getInput();
		if(nextState == EXIT) {
			return 0;
		} else {
			states.setState(nextState);
		}
	}
}
