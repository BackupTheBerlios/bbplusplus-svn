#include "states.h"

States::States() {
	initStates();
	menuContainer[MAIN] = mainMenu;
	menuContainer[DATA] = dataMenu;
	menuContainer[AUDIO] = audioMenu;
	menuContainer[CDCOPY] = cdCopyMenu;
	menuContainer[IMAGES] = imageMenu;
	menuContainer[CONFIG] = configMenu;
	displayer = new MenuDisplayer(*(getState(MAIN)));
	handler = new InputHandler(*(getState(MAIN)));
}

States::~States() {
	delete mainMenu;
	delete dataMenu;
	delete audioMenu;
	delete cdCopyMenu;
	delete imageMenu;
	delete configMenu;
	delete displayer;
	delete handler;
}

void States::show() const {
	displayer->show();
}

int States::getInput() const {
	return handler->getInput();
}

Menu* States::getState(int i) {
	return menuContainer[i];
}

void States::setState(int i) {
	displayer->setDisplayee(*(getState(i)));
	handler->setNewHandled(*(getState(i)));
}

void States::initStates() {
	initMain();
	initData();
	initAudio();
	initCdCopy();
	initImage();
	initConfig();
}

void States::initMain() {
	mainMenu = new Menu("Main Menu");
	mainMenu->addEntry(MenuItem(DATA, "Data"));
	mainMenu->addEntry(MenuItem(AUDIO, "Audio"));
	mainMenu->addEntry(MenuItem(CDCOPY, "Copy CD"));
	mainMenu->addEntry(MenuItem(IMAGES, "Images"));
	mainMenu->addEntry(MenuItem(CONFIG, "Config"));
	mainMenu->addEntry(MenuItem(EXIT, "Exit"));
}

void States::initData() {
	dataMenu = new Menu("Data");
	dataMenu->addEntry(MenuItem(DATABURNING, "Burn Data"));
	dataMenu->addEntry(MenuItem(MAIN, "Back"));
}

void States::initAudio() {
	audioMenu = new Menu("Audio");
	audioMenu->addEntry(MenuItem(AUDIOBURNING, "Burn Audio"));
	audioMenu->addEntry(MenuItem(MAIN, "Back"));
}

void States::initCdCopy() {
	cdCopyMenu = new Menu("Copy CD");
	cdCopyMenu->addEntry(MenuItem(CD2ISO, "Rip CD to ISO"));
	cdCopyMenu->addEntry(MenuItem(CD2CD, "CD to CD copy"));
	cdCopyMenu->addEntry(MenuItem(MAIN, "Back"));
}

void States::initImage() {
	imageMenu = new Menu("Images");
	imageMenu->addEntry(MenuItem(IMAGEBURNING, "Burn CD/DVD Image"));
	imageMenu->addEntry(MenuItem(MAIN, "Back"));
}

void States::initConfig() {
	configMenu = new Menu("Config");
	configMenu->addEntry(MenuItem(MAIN, "Back"));
}
