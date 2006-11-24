#ifndef MENU_H_
#define MENU_H_

#include <vector>
#include <map>
#include "menuitem.h"

typedef std::map<int, MenuItem> EntryContainer;

class Menu {
	public:
		Menu(const char* inTitle = "No title");
		Menu(const Menu* m);
		~Menu(); 
		void addEntry(const MenuItem & item);
		const EntryContainer & getEntries() const;
		const int getMenuSize() const;
		const char* getMenuTitle() const;
		Menu* operator=(const Menu* m);
		int run();
	private:
		char* menuTitle;
		EntryContainer menuItems;
		int menuSize;
};

#endif /*MENU_H_*/
