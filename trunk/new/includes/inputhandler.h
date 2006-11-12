#ifndef INPUTHANDLER_H_
#define INPUTHANDLER_H_

#include "menu.h"

class InputHandler {
	public:
		InputHandler() : menu(NULL) { }
		InputHandler(Menu & m);
		~InputHandler();
		int getInput();
		void setNewHandled(Menu & m);
	private:
		Menu* menu;
		int input;
};

#endif /*INPUTHANDLER_H_*/
