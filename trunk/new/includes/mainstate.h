#ifndef MAIN_STATE_H_
#define MAIN_STATE_H_

#include  "states.h"

class MainState : public States {
	public:
		MainState(Commands & cmd, MenuDisplayer & md, InputHandler & ih);
		virtual ~MainState();
		void setState(int);
		int run();
	private:
		Menu* mMenu;
		Commands* mCommands;
		MenuDisplayer* mDisplayer;
		InputHandler* mHandler;
		int nextState;
};

#endif
