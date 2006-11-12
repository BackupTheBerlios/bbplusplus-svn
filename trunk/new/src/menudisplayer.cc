#include "../includes/menudisplayer.h"
#include <iostream>

using std::cout;
using std::endl;

MenuDisplayer::MenuDisplayer(Menu* m) {
	menu = new Menu(m);
}

MenuDisplayer::~MenuDisplayer() {
	delete menu;
}

/*
 * Displays the menu by iterating over each map entry and printing its first element
 * (The menu number) and getting the entry text from its second element.
 */

void MenuDisplayer::show() const {
	EntryContainer entries = menu->getEntries();
	EntryContainer::iterator it;
	cout << "\n" << menu->getMenuTitle() << endl;
	
	for(it = entries.begin(); it != entries.end(); ++it)
		cout << (*it).first << ") " <<  (*it).second.getEntryText() << endl;
}

/*
 * Make sure to delete previous displayee
 */
void MenuDisplayer::setDisplayee(Menu* m) {
	delete menu;
	menu = new Menu(m);
}
