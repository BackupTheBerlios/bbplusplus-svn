#include "../../headers/tasks/burnermenu.h"
#include <iostream>
#include <cctype>

/*
 * Burner menu methods
 */
BurnerMenu::BurnerMenu(CdBurner & inBurner)
{
  mBurner = &inBurner;
  brnMenu.setTitle("Burner setup");
  brnMenu.setChoice(0, "Burner path", "");
  brnMenu.setChoice(1, "Burner speed", "");
  brnMenu.setChoice(2, "Driver options", "");
  brnMenu.setChoice(3, "Overburn", "");
  brnMenu.setChoice(4, "DAO/TAO", "");
  brnMenu.setChoice(5, "Blanking type", "");
  brnMenu.setChoice(6, "View settings", "");
  brnMenu.setChoice(7, "Back", "");
}

BurnerMenu::~BurnerMenu()
{
	std::cout << "\nDeleting burner menu...";
}

int BurnerMenu::run()
{
    while(true)
    {
        int choice;
	do {
	  system(mCommandSet.GetClearCommand());
	  brnMenu.show();
	} while (! brnMenu.askForInteger("|> ", 0, brnMenu.getNumberOfChoices(), choice));

        switch(choice)
        {
            case 0:
	      ReadPath();
                break;
            case 1:
	      ReadSpeed();
                break;
            case 2:
	      ReadDriverOptions();
	      break;
	    case 3:
	      ReadOverBurn();
	      break;
	    case 4:
	      ReadDiskTrackAtOnce();
	      break;
            case 5:
	      ReadBlankingType();
	      break;
            case 6:
	      std::cout << "\n -- Burner configuration -- \n";
	      mBurner->ViewCurrentConfig();
	      break;
            case 7:
	      return Config;
	      break;
        }
    }
}

void BurnerMenu::ReadPath()
{
	std::cout << "\nEnter the path to your CD-burner: ";
	std::cin.get();
	std::getline(std::cin, mInput);
	SetPath(mInput);	
}

void BurnerMenu::SetPath(const std::string & inPath)
{
	mBurner->SetPath(inPath);
}

const std::string & BurnerMenu::GetPath() const
{
	return mBurner->GetPath();
}

void BurnerMenu::ReadSpeed()
{
	std::cout << "Enter burner speed: ";
	while(!(std::cin >> mInputDigit))
	{
		std::cin.clear(); // Reset input in case of bad input
		while(std::cin.get() != '\n')
			continue;
		std::cout << "Burner speed must be a number. Try again: ";
	}
	mBurner->SetSpeed(mInputDigit);
}

void BurnerMenu::SetSpeed(const int inSpeed)
{
	mBurner->SetSpeed(inSpeed);
}

const int BurnerMenu::GetSpeed() const
{
	return mBurner->GetSpeed();
}

void BurnerMenu::ReadDriverOptions()
{
	std::cout << "\nEnter driver options to use, separate\n"
		<< "multiple ones with a comma, but no space: ";
	std::cin.get();
	std::getline(std::cin, mInput);
	SetDriverOptions(mInput);
}

void BurnerMenu::SetDriverOptions(const std::string & inBurnerOptions)
{
	mBurner->SetDriverOptions(inBurnerOptions);
}

const std::string & BurnerMenu::GetDriverOptions() const
{
	return mBurner->GetDriverOptions();
}

void BurnerMenu::ReadOverBurn()
{
	std::cout << "Do you want to use overburn? (yes/no): ";
	std::cin.get();
	std::getline(std::cin, mInput);
	SetOverBurn(mInput);
}

void BurnerMenu::SetOverBurn(const std::string & inOverBurn)
{
	mBurner->SetOverBurn(inOverBurn);
}

const std::string & BurnerMenu::GetOverBurn() const
{
	return mBurner->GetOverBurn();
}	

void BurnerMenu::ReadDiskTrackAtOnce()
{
	std::cout << "DAO/TAO: ";
	std::cin.get();
	std::getline(std::cin, mInput);
	SetDiskTrackAtOnce(mInput);
}

void BurnerMenu::SetDiskTrackAtOnce(const std::string & inDTAO)
{
	mBurner->SetDiskTrackAtOnce(inDTAO);
}

const std::string & BurnerMenu::GetDiskTrackAtOnce() const
{
	return mBurner->GetDiskTrackAtOnce();
}

void BurnerMenu::ReadBlankingType()
{
	std::cout << "Enter type of disk blanking to use: ";
	std::cin.get();
	std::getline(std::cin, mInput);
	SetBlankingType(mInput);
}

void BurnerMenu::SetBlankingType(const std::string & inBlankingType)
{
	mBurner->SetBlankingType(inBlankingType);
}

const std::string & BurnerMenu::GetBlankingType() const
{
	return mBurner->GetBlankingType();
}

void BurnerMenu::ViewCurrentConfig() const
{
	std::cout << "\n [-- Burner settings --] \n";
	mBurner->ViewCurrentConfig();
}
