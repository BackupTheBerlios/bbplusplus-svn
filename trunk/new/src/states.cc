#include "states.h"
#include <iostream>

/*
 * Constructor first initializes the different menus and actions, and then
 * adds them to their respective container. Also the menu displayer and 
 * input handler are set to handle the main menu.
 */
States::States() {
	initStates();
	menuContainer[MAIN] = mainMenu;
	menuContainer[DATA] = dataMenu;
	menuContainer[AUDIO] = audioMenu;
	menuContainer[CDCOPY] = cdCopyMenu;
	menuContainer[IMAGES] = imageMenu;
	menuContainer[CONFIG] = configMenu;
	initActions();
	actionContainer[DATABURNING] = dataBurning;
	actionContainer[AUDIOBURNING] = audioBurning;
	actionContainer[CD2ISO] = cd2iso;
	actionContainer[CD2CD] = cd2cd;
	actionContainer[IMAGEBURNING] = imageBurning;
	actionContainer[DVDBURNING] = dvdBurning;
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
	delete dataBurning;
	delete audioBurning;
	delete cd2iso;
	delete cd2cd;
	delete imageBurning;
	delete dvdBurning;
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

/*
 * setState checks whether the entered state is a menu or an action.
 * Is it a menu, setState sets the menu displayer and input handler to the
 * correct menu, otherwise it executes the correct action.
 */
void States::setState(int i) {
	if(menuContainer.find(i) != menuContainer.end()) {
		displayer->setDisplayee(*(getState(i)));
		handler->setNewHandled(*(getState(i)));
	} else if(actionContainer.find(i) != actionContainer.end()) {
		// DEBUG!
		std::cout << (getAction(i))->run();
	}
}

void States::initStates() {
	initMain();
	initData();
	initAudio();
	initCdCopy();
	initImage();
	initConfig();
}

void States::initActions() {
	initDataBurning();
	initAudioBurning();
	initCd2Iso();
	initCd2Cd();
	initImageBurning();
	initDvdBurning();
}

Action* States::getAction(int i) {
	return actionContainer[i];
}

/*
 * Initialization of the menus
 */
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

/*
 * Initialization of the actions
 */
void States::initDataBurning() {
	dataBurning = new Action();
}

void States::initAudioBurning() {
	audioBurning = new Action();
}

void States::initCd2Iso() {
	cd2iso = new Action();
}

void States::initCd2Cd() {
	cd2cd = new Action();
}

void States::initImageBurning() {
	imageBurning = new Action();
}

void States::initDvdBurning() {
	dvdBurning = new Action();
}
