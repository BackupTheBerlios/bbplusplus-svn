#include "menuitem.h"
#include "menu.h"
#include "menudisplayer.h"
#include "states.h"
#include "inputhandler.h"
#include "commands.h"
#include <iostream>
using namespace std;

int main()
{	
	// Create menus
	States states;
	
	/*
	 * Create a menu displayer and set it to show the main menu.
	 * Also set the input handler to manage input from this menu state.
	 */
	MenuDisplayer displayer(*(states.getMenu(MAIN)));
	InputHandler handler(*(states.getMenu(MAIN)));

	// System commands used by BashBurn++
	Commands executer;
	
	// Let it rip!
	while(true) {
		executer.clearScreen();
		displayer.show();
		switch(handler.getInput()) {
			case DATA:
				displayer.setDisplayee(*(states.getMenu(DATA)));
				handler.setNewHandled(*(states.getMenu(DATA)));
				break;
			case AUDIO:
				displayer.setDisplayee(*(states.getMenu(AUDIO)));
				handler.setNewHandled(*(states.getMenu(AUDIO)));
				break;
			case CDCOPY:
				displayer.setDisplayee(*(states.getMenu(CDCOPY)));
				handler.setNewHandled(*(states.getMenu(CDCOPY)));
				break;
			case IMAGES:
				displayer.setDisplayee(*(states.getMenu(IMAGES)));
				handler.setNewHandled(*(states.getMenu(IMAGES)));
				break;
			case CONFIG:
				displayer.setDisplayee(*(states.getMenu(CONFIG)));
				handler.setNewHandled(*(states.getMenu(CONFIG)));
				break;
			case MAIN:
				displayer.setDisplayee(*(states.getMenu(MAIN)));
				handler.setNewHandled(*(states.getMenu(MAIN)));
				break;
			case EXIT:
				return 0;
		}
	}
}
