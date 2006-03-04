#include "../../headers/tasks/tempdirmenu.h"
#include "../../headers/units.h"
#include <iostream>

TempDirMenu::TempDirMenu(TempDir & inTempDir) : mTempDir(NULL)
{
	mTempDir = &inTempDir;
	tempDirMenu.setTitle("Temporary storage directory information");
	tempDirMenu.setChoice(0, "Path", "");
	tempDirMenu.setChoice(1, "Delete after burn", "");
	tempDirMenu.setChoice(2, "View settings", "");
	tempDirMenu.setChoice(3, "Back", "Go back to previous menu.");
}

TempDirMenu::~TempDirMenu() 
{
	std::cout << "\nDeleting temp dir menu...";
}

int TempDirMenu::run()
{
	while(true)
	{
	     int choice;
	     do {
	       system(mCommandSet.GetClearCommand());
	       tempDirMenu.show();
	     } while (! tempDirMenu.askForInteger("|> ", 0, tempDirMenu.getNumberOfChoices() - 1, choice));

		switch(choice)
		{
			case 0:
				ReadPath();
				break;
			case 1:
				ReadDeleteTemp();
				break;
			case 2:
				mTempDir->ViewCurrentConfig();
				break;
			case 3:
				return Config;
				break;
		}
	}
}

void TempDirMenu::ReadPath()
{
        tempDirMenu.askForString("Enter path to temporary storage directory: ", 0, 256, mInput);
	SetPath(mInput);
}

void TempDirMenu::SetPath(const std::string & inPath)
{
	mTempDir->SetPath(inPath);
}

const std::string & TempDirMenu::GetPath() const
{
	return mTempDir->GetPath();
}

void TempDirMenu::ReadDeleteTemp()
{
	std::cout 
		<< "\nShould contents in temporary directory be\n"
		<< "deleted after completed burn? (yes/no): ";
	std::cin.get();
	std::getline(std::cin, mInput);
	SetDeleteTemp(mInput);
}

void TempDirMenu::SetDeleteTemp(const std::string & inChoice)
{
	mTempDir->SetDeleteTemp(inChoice);
}

const std::string & TempDirMenu::GetDeleteTemp() const
{
	return mTempDir->GetDeleteTemp();
}

void TempDirMenu::ViewCurrentConfig() const
{
	std::cout << "\n [ -- Temporary storage directory settings -- ] \n";
	mTempDir->ViewCurrentConfig();
}
