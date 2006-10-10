#include "../../headers/tasks/audiomenu.h"
#include <iostream>

/*
 * Audio Menu methods
 */
AudioMenu::AudioMenu(TempDir & inTempDir, CdBurner & inCdBurner, CdReader & inCdReader)
	: mTempDir(NULL), mCdBurner(NULL), mCdReader(NULL)
{
  mTempDir = &inTempDir;
  mCdBurner = &inCdBurner;
  mCdReader = &inCdReader;
  auMenu.setTitle("Audio Menu");
  auMenu.setChoice(0, "Burn audio CD from Mp3s/Oggs/Wavs/FLACs", "");
  auMenu.setChoice(1, "Copy audio CD (CD to CD)", "");
  auMenu.setChoice(2, "Rip audio CD to harddrive", "");
  auMenu.setChoice(3, "Create Mp3s from Wavs", "");
  auMenu.setChoice(4, "Create Oggs from Wavs", "");
  auMenu.setChoice(5, "Create FLACs from Wavs", "");
  auMenu.setChoice(6, "Back to Main Menu", "");
}

AudioMenu::~AudioMenu()
{
  std::cout << "\nDeleting audio menu...";
}

int AudioMenu::run()
{
    while(true)
    {
        int choice;
	do {
	  system(mCommandSet.GetClearCommand());
	  auMenu.show();
	} while (! auMenu.askForInteger("|> ", 0, auMenu.getNumberOfChoices() - 1, choice));

        switch(choice)
        {
	        case 0:
        		BurnCDFromFiles();
        		break;
        	case 1:
        		CopyCDToCD();
        		break;
        	case 2:
        		RipCDToHarddrive();
        		break;
        	case 3:
        		CreateMp3s();
        		break;
        	case 4:
        		CreateOggs();
        		break;
        	case 5:
        		CreateFlacs();
        		break;
	        case 6:
		        return mMenu;
			break;
        }
    }

}

void AudioMenu::BurnCDFromFiles()
{
	// Backup old command
	std::string oldBurnCmd = mCommandSet.GetBurnCommand();
	// Set the new one
	std::string newBurnCmd = oldBurnCmd + ' ' + mCdBurner->GetPath() + ' ' + mTempDir->GetPath();
	
	mCommandSet.SetBurnCommand(&newBurnCmd[0]);	
	
	std::cout << "New burn command is: " << mCommandSet.GetBurnCommand() << std::endl;
	system(mCommandSet.GetSleepCommand());
	
	std::cout << "Resetting burn command" << std::endl;
	mCommandSet.SetBurnCommand(&oldBurnCmd[0]);
	
	std::cout << "Burn command is once again: " << mCommandSet.GetBurnCommand();
	system(mCommandSet.GetSleepCommand());
}

void AudioMenu::CopyCDToCD()
{
        auMenu.showInfo("State:", "Copy CD to CD...");
	system(mCommandSet.GetSleepCommand());
}

void AudioMenu::RipCDToHarddrive()
{
	std::cout << "\nGoing to rip Rip CD in " << mCdReader->GetPath() << " to harddrive\n";
	system(mCommandSet.GetSleepCommand());
}

void AudioMenu::CreateMp3s()
{
	std::cout << "\nCreate Mp3s from files in " << mTempDir->GetPath() << std::endl;
	system(mCommandSet.GetSleepCommand());
}

void AudioMenu::CreateOggs()
{
        auMenu.showInfo("State:", "Create Oggs...");
	system(mCommandSet.GetSleepCommand());
}

void AudioMenu::CreateFlacs()
{
        auMenu.showInfo("State:", "Create FLACS...");
	system(mCommandSet.GetSleepCommand());
}
