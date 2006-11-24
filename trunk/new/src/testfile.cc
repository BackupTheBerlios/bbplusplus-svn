#include "../includes/menuitem.h"
#include "../includes/menu.h"
#include "../includes/menudisplayer.h"
#include "../includes/mainstate.h"
#include "../includes/datastate.h"
#include "../includes/audiostate.h"
#include "../includes/inputhandler.h"
#include "../includes/commands.h"
#include "../includes/filehandler.h"
#include <iostream>
using std::cout;
using std::auto_ptr;

int main()
{
	/*
	 *  System commands used by BashBurn++
	 * We use a smart pointer to not have to worry about deleting it later on.
	 */
	auto_ptr<Commands> executer = (auto_ptr<Commands>)Commands::Instance();
	
	MenuDisplayer displayer;
	InputHandler handler;

	FileHandler filemanager;
	filemanager.putText("Yo mama");
	
	
	/*
	 * Here we create the different states of the program, and pass along
	 * the commands used, the menu displayer and the input handler.
	 */
	States* mainState = new MainState(*executer, displayer, handler);
	States* dataState = new DataState(*executer, displayer, handler);
	States* audioState = new AudioState(*executer, displayer, handler);
	// Let it rip!
	States* currentState = mainState;
	/*
	 * Here we clear the screen, display the menu and recieves user input.
	 * Depending on what the input is, we either exit or set our next state
	 * (Which could be a menu or an action) and continue.
	 */
	while(true) {
		displayer.setDisplayee(currentState->getMenu());
		handler.setNewHandled(currentState->getMenu());
		switch(currentState->run()) {
			case EXIT:
				delete mainState;
				delete dataState;
				delete audioState;
				cout << "\nThank you for using BashBurn++\n";
				return 0;
			case MAIN:
				currentState = mainState;
				break;
			case DATA:
				currentState = dataState;
				break;
			case AUDIO:
				currentState = audioState;
				break;
			default:
				cout << "Not implemented\n";
				break;
		}
	}
}
