#include "../includes/mainstate.h"

MainState::MainState(Commands &cmd, MenuDisplayer &md, InputHandler & ih)
	: mCommands(&cmd), mDisplayer(&md), mHandler(&ih)
{
	mMenu = new Menu("Main Menu");
	mMenu->addEntry(MenuItem(DATA, "Data"));
	mMenu->addEntry(MenuItem(AUDIO, "Audio"));
	mMenu->addEntry(MenuItem(CDCOPY, "Copy CD"));
	mMenu->addEntry(MenuItem(IMAGES, "Images"));
	mMenu->addEntry(MenuItem(CONFIG, "Config"));
	mMenu->addEntry(MenuItem(EXIT, "Exit"));

	//mDisplayer->setDisplayee(mMenu);
	//mHandler->setNewHandled(mMenu);
}

MainState::~MainState() {
	delete mMenu;
}

Menu* MainState::getMenu() {
	return mMenu;
}

int MainState::run() {
	mCommands->clearScreen();
	mDisplayer->show();
	return mHandler->getInput();
}
