#ifndef MENUS_H_
#define MENUS_H_

#include "../bbbase.h"
#include "../ui.h"

/*
 * menus.h - Contains menu definitions for misc menus.
 * (Will probably be broken into smaller files at one point.
 */
class MainMenu : public Bbbase
{
    public:
        MainMenu();
        ~MainMenu();
        int run();
    private:
        //MenuBase mMenu;
	Menu mMenu;
        int choice;
	int input;
	std::vector<std::string> choices;
};

#endif
