#include "../../headers/tasks/datamenu.h"
#include <iostream>

/*
 * Data Menu methods
 */
DataMenu::DataMenu(TempDir & inTempDir, CdBurner & inCdBurner)
{
    mTempDir = &inTempDir;
    mCdBurner = &inCdBurner;
    dMenu.setTitle("Data Menu");
    dMenu.setChoice(0, "Burn data CD from files", "");
    dMenu.setChoice(1, "Copy data CD (CD to CD)", "");
    dMenu.setChoice(2, "Burn DVD from files", "");
    dMenu.setChoice(3, "Copy DVD (DVD to DVD)", "");
    dMenu.setChoice(4, "Back to Main Menu", "");
}

DataMenu::~DataMenu()
{
	std::cout << "\nDeleting data menu...";
}

int DataMenu::run()
{
    while(true)
    {
        int choice;
	do {
	  system(mCommandSet.GetClearCommand());
	  dMenu.show();
	} while (! dMenu.askForInteger("|> ", 0, dMenu.getNumberOfChoices(), choice));

        switch(choice)
        {
        	case 0:
        		BurnCDFromFiles();
        		break;
        	case 1:
        		CopyCDToCD();
        		break;
        	case 2:
        		BurnDVDFromFiles();
        		break;
        	case 3:
        		CopyDVDToDVD();
        		break;
	        case 4:
		        return mMenu;
			break;
        }
    }
}

void DataMenu::BurnCDFromFiles()
{
	std::cout << "\nBurn CD from files in " << mTempDir->GetPath() << " with "
		<< mCdBurner->GetPath() << std::endl;
	system(mCommandSet.GetSleepCommand());
}

void DataMenu::CopyCDToCD()
{
	std::cout << "\nCopy CD to CD\n";
	system(mCommandSet.GetSleepCommand());
}
/*
 * When burning DVDs, we change the burn command from cdrecord to growisofs.
 * When finished we make sure to change it back.
 */
void DataMenu::BurnDVDFromFiles()
{
	mCommandSet.SetBurnCommand("growisofs");
	std::cout << "\nBurn DVD from files\n";
	mCommandSet.SetBurnCommand("cdrecord");
	system(mCommandSet.GetSleepCommand());
}

void DataMenu::CopyDVDToDVD()
{
	mCommandSet.SetBurnCommand("growisofs");
	std::cout << "\nCopy DVD to DVD\n";
	mCommandSet.SetBurnCommand("cdrecord");
	system(mCommandSet.GetSleepCommand());
}
