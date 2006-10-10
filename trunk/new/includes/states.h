#ifndef STATES_H_
#define STATES_H_

/*
 * States.h is where all the states the program can take are declared.
 * There are "main states" which consist of the main menus, and "sub states"
 * which consist of the actual actions such as burning a CD or create an ISO-file.
 */


#include "menu.h"

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
		Menu* getMenu(int);
		void initMenus();
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
};

#endif /*STATES_H_*/
