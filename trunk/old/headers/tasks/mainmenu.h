#ifndef MENUS_H_
#define MENUS_H_

#include "../bbbase.h"
#include "../ui.h"

/*
 * mainmenu.h - Well...it's the main menu
 */
class MainMenu : public Bbbase
{
    public:
        MainMenu();
        ~MainMenu();
        int run();
    private:
		Menu mMenu;
		int choice;
		int input;
		std::vector<std::string> choices;
};

#endif
