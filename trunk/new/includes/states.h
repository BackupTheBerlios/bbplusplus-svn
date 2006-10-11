#ifndef STATES_H_
#define STATES_H_

/*
 * States.h is where all the states the program can take are declared.
 * There are "main states" which consist of the main menus, and "sub states"
 * which consist of the actual actions such as burning a CD or create an ISO-file.
 */

#include "menu.h"
#include "menudisplayer.h"
#include "inputhandler.h"

// Main states
enum states { MAIN,
						DATA,
						AUDIO,
						CDCOPY,
						IMAGES,
						CONFIG,
						EXIT
};
// Sub states
enum activities { DATABURNING = 100,
							AUDIOBURNING,
							CD2ISO,
							CD2CD,
							IMAGEBURNING,
							DVDBURNING
};

class States {
	public:
		States();
		~States();
		Menu* getState(int);
		void setState(int);
		void initStates();
		void show() const;
		int getInput() const;
	protected:
		void initMain();
		void initData();
		void initAudio();
		void initCdCopy();
		void initImage();
		void initConfig();
	private:
		std::map<int, Menu*> menuContainer;
		Menu* mainMenu;
		Menu* dataMenu;
		Menu* audioMenu;
		Menu* cdCopyMenu;
		Menu* imageMenu;
		Menu* configMenu;
		MenuDisplayer* displayer;
		InputHandler* handler;
};

#endif /*STATES_H_*/
