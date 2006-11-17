#include "../includes/datastate.h"

DataState::DataState(Commands &cmd, MenuDisplayer &md, InputHandler & ih)
	: mCommands(&cmd), mDisplayer(&md), mHandler(&ih)
{
	mMenu = new Menu("Data Menu");
	mMenu->addEntry(MenuItem(DATABURNING, "Burn Data"));
	mMenu->addEntry(MenuItem(IMAGEBURNING, "Burn Images"));
	mMenu->addEntry(MenuItem(DVDBURNING, "Burn a Data DVD"));
	mMenu->addEntry(MenuItem(MAIN, "Back to Main Menu"));

	//mDisplayer->setDisplayee(mMenu);
	//mHandler->setNewHandled(mMenu);
}

DataState::~DataState() {
	delete mMenu;
}

Menu* DataState::getMenu() {
	return mMenu;
}

int DataState::run() {
	mCommands->clearScreen();
	mDisplayer->show();
	return mHandler->getInput();
}

