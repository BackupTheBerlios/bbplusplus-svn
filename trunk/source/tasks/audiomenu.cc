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
	} while (! auMenu.askForInteger("|> ", 0, auMenu.getNumberOfChoices(), choice));

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
	std::cout << "\nGoing to burn CD from files in " << mTempDir->GetPath() << " with " 
		<< mCdBurner->GetPath() << " using " << mCommandSet.GetBurnCommand() << std::endl;
	system(mCommandSet.GetSleepCommand());
}

void AudioMenu::CopyCDToCD()
{
	std::cout << "\nCopy CD to CD\n";
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
	std::cout << "\nCreate Oggs\n";
	system(mCommandSet.GetSleepCommand());
}

void AudioMenu::CreateFlacs()
{
	std::cout << "\nCreate FLACSs\n";
	system(mCommandSet.GetSleepCommand());
}
