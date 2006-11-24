#ifndef INPUTHANDLER_H_
#define INPUTHANDLER_H_

#include "menu.h"

class InputHandler {
	public:
		InputHandler() : menu(NULL) { }
		InputHandler(const Menu* m);
		~InputHandler();
		const int getInput();
		void setNewHandled(const Menu* m);
	private:
		Menu* menu;
		int input;
};

#endif /*INPUTHANDLER_H_*/
