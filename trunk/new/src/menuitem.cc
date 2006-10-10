#include "menuitem.h"
#include "states.h"

MenuItem::MenuItem() : state(MAIN) {
	entryText = new char[strlen("Empty string") + 1];
	strcpy(entryText, "Empty");
}

MenuItem::MenuItem(int s, const char* t) : state(s) {
	entryText = new char[strlen(t) + 1];
	strcpy(entryText, t);
}

MenuItem::MenuItem(const MenuItem & mi) {
	state = mi.getState();
	entryText = new char[strlen(mi.getEntryText()) + 1 ];
	strcpy(entryText, mi.getEntryText());
}

MenuItem & MenuItem::operator=(MenuItem & m) {
	if(this == &m) {
		return m;
	}
	delete[] entryText;
	state = m.getState();
	entryText = new char[strlen(m.getEntryText()) + 1];
	strcpy(entryText, m.getEntryText());
	return *this;
}

void MenuItem::setEntryText(const char* s) {
	delete[] entryText;
	entryText = new char[strlen(s) + 1];
	strcpy(entryText, s);
}
