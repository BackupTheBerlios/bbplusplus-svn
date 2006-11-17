#ifndef STATES_H_
#define STATES_H_

/*
 * States.h is where all the states the program can take are declared.
 * There are "main states" which consist of the main menus, and "sub states"
 * which consist of the actual actions such as burning a CD or create an ISO-file.
 */

#include "menu.h"
#include "action.h"
#include "menudisplayer.h"
#include "inputhandler.h"
#include "commands.h"

// Main states (Or menus, except for exit)
enum states { MAIN,
						DATA,
						AUDIO,
						CDCOPY,
						IMAGES,
						CONFIG,
						EXIT
};
// Sub states (Actual actions taking place)
enum activities { DATABURNING = 100,
							AUDIOBURNING,
							CD2ISO,
							CD2CD,
							IMAGEBURNING,
							DVDBURNING
};

class States {
	public:
		States() {};
		virtual ~States() {}
		virtual int run() = 0;
		virtual Menu* getMenu() {}
};

#endif /*STATES_H_*/
