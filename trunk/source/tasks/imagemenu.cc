#include "../../headers/tasks/imagemenu.h"
#include <iostream>

/*
 * Image Menu methods
 */
ImageMenu::ImageMenu(TempDir & inTempDir, CdBurner & inCdBurner)
	: mTempDir(NULL), mCdBurner(NULL)
{
    mTempDir = &inTempDir; 	
    mCdBurner = &inCdBurner;
    iMenu.setTitle("CD Image Menu"); // iMenu (c) Apple
    iMenu.setChoice(0, "Burn CD image", "");
    iMenu.setChoice(1, "Burn DVD image", "");
    iMenu.setChoice(2, "Create ISO-image from files on harddrive", "");
    iMenu.setChoice(3, "Create ISO-image from CD/DVD", "");
    iMenu.setChoice(4, "Back to Main Menu", "");
}

ImageMenu::~ImageMenu()
{
	std::cout << "\nDeleting image menu...";
}

int ImageMenu::run()
{
	while(true)
	{
	        int choice;
		do {
		  system(mCommandSet.GetClearCommand());
		  iMenu.show();
		} while (! iMenu.askForInteger("|> ", 0, iMenu.getNumberOfChoices() - 1, choice));

		switch (choice)
		  {
			case 0:
				BurnCDImage();
				break;
			case 1:
				BurnDVDImage();
				break;
			case 2:
				CreateISOFromHarddrive();
				break;
			case 3:
				CreateISOFromDisc();
				break;
			case 4:
				return mMenu;
				break;
		}
	}
}

void ImageMenu::BurnCDImage()
{
	std::cout << "\nBurn CD image in " << mTempDir->GetPath() << " with "
		<< mCdBurner->GetPath() << std::endl;
	system(mCommandSet.GetSleepCommand());
}

void ImageMenu::BurnDVDImage()
{
	mCommandSet.SetBurnCommand("growisofs");
	std::cout << "\nBurn DVD image\n";
	mCommandSet.SetBurnCommand("cdrecord");
	system(mCommandSet.GetSleepCommand());
}

void ImageMenu::CreateISOFromHarddrive()
{
	std::cout << "\nCreate ISO from harddrive\n";
	system(mCommandSet.GetSleepCommand());
}

void ImageMenu::CreateISOFromDisc()
{
	std::cout << "\nCreate ISO from Disc\n";
	system(mCommandSet.GetSleepCommand());
}
