#ifndef BBBASE_H
#define BBBASE_H

#include "commands.h"
#include <string>


// global version variable for BashBurn++:
static const std::string bbVersion = "::. BashBurn++ v1.0 pre alpha .::";

/*
 * Abstact base class
 * The enums represent the different states of the program.
 * They are:
 * Main menu
 * Audio menu
 * Data menu
 * Image menu
 * Config menu
 * Burner menu
 * CD info menu
 * Temporary directory menu
 * Exit
 */
class Bbbase
{
    public:
        virtual ~Bbbase(){}
        virtual int run() = 0;
        enum returnValues { mMenu , Audio , Data , Images, Config,
        	 bMenu, cdiMenu, tdMenu, Exit };
    protected:
	Commands mCommandSet;
	int mNumChoices;
};

#endif
