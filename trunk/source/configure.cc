#include "../headers/configure.h"
#include <iostream>

/*
 * Methods for the configuration menu
 */
Configure::Configure()
{
    burnerMenu = new BurnerMenu(mBurner);
    cdInfo = new CDInfo(mCD);
    tempDirMenu = new TempDirMenu(mTempDir);
    configMenu.setTitle("Configuration");
    configMenu.setChoice(0, "Reader path", "Device where CD reader lives.");
    configMenu.setChoice(1, "Burner setup", "");
    configMenu.setChoice(2, "Temporary space options", "");
    configMenu.setChoice(3, "CD information", "");
    configMenu.setChoice(4, "View config", "");
    configMenu.setChoice(5, "Save config", "");
    configMenu.setChoice(6, "Back to Main Menu", "");
}

Configure::~Configure()
{
	std::cout << "\nDeleting configure menu...";
	delete burnerMenu;
	delete cdInfo;
	delete tempDirMenu;
}

int Configure::run()
{
    while(true)
    {
        int choice;
	do {
	  system(mCommandSet.GetClearCommand());
	  configMenu.show();
	} while (! configMenu.askForInteger("|> ", 0, configMenu.getNumberOfChoices(), choice));

	switch(choice)
        {
            case 0:
	      ReadReader();
	      break;
            case 1:
	      return bMenu;
	      break;
            case 2:
	      return tdMenu;
	      break;
            case 3:
	      return cdiMenu;
	      break;
            case 4:
	      ViewCurrentConfig();
	      system(mCommandSet.GetSleepCommand());
	      break;
            case 5:
	      configMenu.showInfo("Info:", "Saving configuration...");
	      system(mCommandSet.GetSleepCommand());
	      break;
            case 6:
	      return mMenu;
        }
    }
}

void Configure::ReadReader()
{
	std::cout << "Enter the path to your CD-reader: ";
	std::cin.get();
	std::getline(std::cin, mInput);
	SetReader(mInput);
}

void Configure::SetReader(const std::string & inPath)
{
	mReader.SetPath(inPath);
}

void const Configure::ViewCurrentConfig() const
{
	std::cout << "\n >> Current config << \n\n";
	std::cout << "\n -- Reader settings -- \n";
	mReader.ViewCurrentConfig();
	burnerMenu->ViewCurrentConfig();
	cdInfo->ViewCurrentConfig();
	tempDirMenu->ViewCurrentConfig();    
}

CdBurner & Configure::ReturnBurner()
{
	return mBurner;
}

CdReader & Configure::ReturnReader()
{
	return mReader;
}

CD & Configure::ReturnCD()
{
	return mCD;
}

TempDir & Configure::ReturnTempDir()
{
	return mTempDir;
}
