#include "../includes/menu.h"

/*
 * For "internal" use.
 */
Menu::Menu(const char* t) : menuSize(0) {
	menuTitle = new char[strlen(t) + 1 ];
	strcpy(menuTitle, t);
}

// Copy constructor
Menu::Menu(Menu* m) : menuSize(0) {
	menuTitle = new char[strlen(m->menuTitle) + 1 ];
	strcpy(menuTitle, m->menuTitle);
	menuItems = m->getEntries();
	menuSize = m->getMenuSize();
}	

// Assignment operator
Menu* Menu::operator=(Menu* m) {
	if(this == m) {
		return this;
	}
	delete[] menuTitle;
	menuTitle = new char[strlen(m->menuTitle) + 1 ];
	strcpy(menuTitle, m->menuTitle);
	menuItems = m->getEntries();
	menuSize = m->getMenuSize();
	return this;
}

Menu::~Menu() {
	delete[] menuTitle; 
}

void Menu::addEntry(const MenuItem & item) {
	MenuItem temp = item;
	++menuSize;
	menuItems[menuSize] = temp;
}

EntryContainer & Menu::getEntries() {
	return menuItems;
}

int Menu::getMenuSize() const {
	return menuSize;	
}

const char* Menu::getMenuTitle() {
	return menuTitle;
}
