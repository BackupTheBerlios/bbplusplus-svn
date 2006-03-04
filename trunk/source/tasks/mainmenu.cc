#include "../../headers/tasks/mainmenu.h"
#include <iostream>

/*
 * Main Menu methods
 */
MainMenu::MainMenu()
{
    mMenu.setTitle("Main Menu");
    mMenu.setChoice(0, "Audio", "Make all audio CD's.");
    mMenu.setChoice(1, "Data", "Make data CD's.");
    mMenu.setChoice(2, "CD Images", "doc_image");
    mMenu.setChoice(3, "Configuration", "Do settings of bashburn.");
    mMenu.setChoice(4, "Exit", "Exit bashburn and return to the shell.");
}

MainMenu::~MainMenu()
{
	std::cout << "\nDeleting main menu...";
}

int MainMenu::run()
{
  while (true)
    {
    	int choice;
    	do {
    		system(mCommandSet.GetClearCommand());
    		mMenu.show();
    	} while (! mMenu.askForInteger("|> ", 0, mMenu.getNumberOfChoices() - 1, choice));
    	
    	switch (choice)
    	{
            case 0:
                return Audio;
                break;
            case 1:
                return Data;
                break;
            case 2:
                return Images;
                break;
            case 3:
                return Config;
                break;
            case 4:
                return Exit;
                break;
	  	}	
    }
}
