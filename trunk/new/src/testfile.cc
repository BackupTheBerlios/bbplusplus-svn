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
	/*
	 * Here we create not only the different states, but also the displayer used to print the menus
	 * and the input handler used to get input from the user. All we have to do in the switch statement
	 * below is to set the new handled state.
	 */
	States states;

	// System commands used by BashBurn++
	Commands executer;
	
	// Let it rip!
	while(true) {
		executer.clearScreen();
		states.show();
		switch(states.getInput()) {
			case DATA:
				states.setState(DATA);
				break;
			case AUDIO:
				states.setState(AUDIO);
				break;
			case CDCOPY:
				states.setState(CDCOPY);
				break;
			case IMAGES:
				states.setState(IMAGES);
				break;
			case CONFIG:
				states.setState(CONFIG);
				break;
			case MAIN:
				states.setState(MAIN);
				break;
			case DATABURNING:
				states.setState(DATABURNING);
				break;
			case AUDIOBURNING:
				states.setState(AUDIOBURNING);
				break;
			case CD2ISO:
				states.setState(CD2ISO);
				break;
			case CD2CD:
				states.setState(CD2CD);
				break;
			case IMAGEBURNING:
				states.setState(IMAGEBURNING);
				break;
			case DVDBURNING:
				states.setState(DVDBURNING);
				break;
			case EXIT:
				return 0;
		}
	}
}
