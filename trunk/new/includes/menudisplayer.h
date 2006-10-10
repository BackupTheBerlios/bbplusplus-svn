#ifndef MENUDISPLAYER_H_
#define MENUDISPLAYER_H_

#include "menu.h"

class MenuDisplayer {
	public:
		MenuDisplayer(Menu & m);
		~MenuDisplayer();
		void setDisplayee(Menu & m);
		void show() const;
	private:
		Menu* menu;
};
	


#endif /*MENUDISPLAYER_H_*/
