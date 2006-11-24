#include "../includes/menuitem.h"
#include "../includes/states.h"

MenuItem::MenuItem() : state(MAIN) {
	entryText = new char[strlen("Empty string") + 1];
	strcpy(entryText, "Empty");
}

MenuItem::MenuItem(const int s, const char* t) : state(s) {
	entryText = new char[strlen(t) + 1];
	strcpy(entryText, t);
}

MenuItem::MenuItem(const MenuItem & mi) {
	state = mi.getState();
	entryText = new char[strlen(mi.getEntryText()) + 1 ];
	strcpy(entryText, mi.getEntryText());
}

const MenuItem & MenuItem::operator=(const MenuItem & m) {
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
