#ifndef DATA_STATE_H_
#define DATA_STATE_H_

#include  "states.h"

class DataState : public States {
	public:
		DataState(Commands & cmd, MenuDisplayer & md, InputHandler & ih);
		virtual ~DataState();
		void setState(int);
		Menu* getMenu();
		int run();
	private:
		Menu* mMenu;
		Commands* mCommands;
		MenuDisplayer* mDisplayer;
		InputHandler* mHandler;
		int nextState;
};

#endif
