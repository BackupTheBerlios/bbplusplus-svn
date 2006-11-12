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
		States(Commands &, MenuDisplayer &, InputHandler &);
		~States();
		Menu* getState(int);
		void setState(int);
		void initStates();
		void initActions();
		Action* getAction(int);
		void show() const;
		int getInput() const;
	protected:
	/*
	 * Help methods used to initialize individual states/actions
	 */
		void initMain();
		void initData();
		void initAudio();
		void initCdCopy();
		void initImage();
		void initConfig();
		void initDataBurning();
		void initAudioBurning();
		void initCd2Iso();
		void initCd2Cd();
		void initImageBurning();
		void initDvdBurning();
	private:
		/*
		 * System commands used
		 */
		Commands* commands;
		/*
		 * The menu container and menus used
		 */
		std::map<int, Menu*> menuContainer;
		Menu* mainMenu;
		Menu* dataMenu;
		Menu* audioMenu;
		Menu* cdCopyMenu;
		Menu* imageMenu;
		Menu* configMenu;
		/*
		 * The action container and the actions that perform tasks.
		 */
		std::map<int, Action*> actionContainer;
		Action* dataBurning;
		Action* audioBurning;
		Action* cd2iso;
		Action* cd2cd;
		Action* imageBurning;
		Action* dvdBurning;
		/*
		 * Menu displayer and input handler used by the program.
		 * They are both created by the main file and passed as arguments to
		 * the states constructor.
		 */
		MenuDisplayer* displayer;
		InputHandler* handler;
};

#endif /*STATES_H_*/
