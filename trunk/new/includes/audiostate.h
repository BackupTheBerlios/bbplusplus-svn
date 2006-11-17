#ifndef AUDIO_STATE_H_
#define AUDIO_STATE_H_

#include  "states.h"

class AudioState : public States {
	public:
		AudioState(Commands & cmd, MenuDisplayer & md, InputHandler & ih);
		virtual ~AudioState();
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
