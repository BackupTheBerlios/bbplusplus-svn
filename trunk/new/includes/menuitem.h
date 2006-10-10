#ifndef MENUITEM_H_
#define MENUITEM_H_

#include <string>
//#include "states.h"

class MenuItem{
	public:
		/*
		 * This constructor is not really supposed to be used. It's needed however for
		 * the map of menu entries in the menu class.
		 */
		MenuItem();

		MenuItem(int s, const char* inText );
		
		MenuItem(const MenuItem & mi);

		~MenuItem() { delete[] entryText; }
		
		int getState() const { return state; }
		
		void setEntryText(const char*);
		
		const char* getEntryText() const { return entryText; }

		MenuItem & operator=(MenuItem & m);
		
	private:
		int state;
		char* entryText;
		
};

#endif /*MENUITEM_H_*/
