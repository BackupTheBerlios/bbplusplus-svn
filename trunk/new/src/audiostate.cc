#include "../includes/audiostate.h"

AudioState::AudioState(Commands &cmd, MenuDisplayer &md, InputHandler & ih)
	: mCommands(&cmd), mDisplayer(&md), mHandler(&ih)
{
	mMenu = new Menu("Audio Menu");
	mMenu->addEntry(MenuItem(AUDIOBURNING, "Burn Audio-CD"));
	mMenu->addEntry(MenuItem(MAIN, "Back to Main Menu"));
}

AudioState::~AudioState() {
	delete mMenu;
}

Menu* AudioState::getMenu() {
	return mMenu;
}

int AudioState::run() {
	mCommands->clearScreen();
	mDisplayer->show();
	return mHandler->getInput();
}

