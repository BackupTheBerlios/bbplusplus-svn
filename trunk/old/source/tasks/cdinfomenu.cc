#include "../../headers/tasks/cdinfomenu.h"
#include <iostream>

/*
 * Methods for setting/getting CD info
 */
CDInfo::CDInfo(CD & inCD) : mCD(NULL)
{
    mCD = &inCD;
    cdInfoMenu.setTitle("CD Information");
    cdInfoMenu.setChoice(0, "Label", "");
    cdInfoMenu.setChoice(1, "Author", "");
    cdInfoMenu.setChoice(2, "Description", "");
    cdInfoMenu.setChoice(3, "Copyright", "");
    cdInfoMenu.setChoice(4, "View settings", "");
    cdInfoMenu.setChoice(5, "Back", "");
}

CDInfo::~CDInfo() 
{
	std::cout << "\nDeleting CD-info menu...";
}

int CDInfo::run()
{
  while(true)
    {
        int choice;
	do {
	  system(mCommandSet.GetClearCommand());
	  cdInfoMenu.show();
	} while (! cdInfoMenu.askForInteger("|> ", 0, cdInfoMenu.getNumberOfChoices() - 1, choice));

        switch(choice)
        {
            case 0:
                ReadLabel();
                break;
            case 1:
	        ReadAuthor();
                break;
            case 2:
	        ReadDescription();
            	break;
	    case 3:
	        ReadCopyright();
		break;
            case 4:
	        ViewCurrentConfig();
		break;
            case 5:
                return Config;
                break;
        }
    }
}

void CDInfo::ReadLabel()
{
        cdInfoMenu.askForString("Enter the label of your CD: ", 0, 256, mInput);
	SetLabel(mInput);
}

void CDInfo::SetLabel(const std::string & inLabel)
{
	mCD->SetLabel(inLabel);
}

const std::string & CDInfo::GetLabel() const
{
	return mCD->GetLabel();
}

void CDInfo::ReadAuthor()
{
	std::cout << "\nEnter the author of your CD: ";
	std::cin.get();
	std::getline(std::cin, mInput);
	SetAuthor(mInput);
}

void CDInfo::SetAuthor(const std::string & inAuthor)
{
	mCD->SetAuthor(inAuthor);
}

const std::string & CDInfo::GetAuthor() const
{
	return mCD->GetAuthor();
}

void CDInfo::ReadDescription()
{
	std::cout << "\nEnter a description of the contents of the CD: ";
	std::cin.get();
	std::getline(std::cin, mInput);
	SetDescription(mInput);
}

void CDInfo::SetDescription(const std::string & inDescription)
{
	mCD->SetDescription(inDescription);
}

const std::string & CDInfo::GetDescription() const
{
	return mCD->GetDescription();
}

void CDInfo::ReadCopyright()
{
	std::cout << "\nEnter the license your CD is released under: ";
	std::cin.get();
	std::getline(std::cin, mInput);
	SetCopyright(mInput);
}

void CDInfo::SetCopyright(const std::string & inCopyRight)
{
	mCD->SetCopyright(inCopyRight);
}

const std::string & CDInfo::GetCopyright() const
{
	return mCD->GetCopyright();
}

void CDInfo::ViewCurrentConfig() const
{
	std::cout << "\n [ -- CD information settings -- ] \n";
	mCD->ViewCurrentConfig();
}
