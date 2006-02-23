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
 * 1 - Main menu
 * 2 - Audio menu
 * 4 - Data menu
 * 8 - Image menu
 * 16 - Config menu
 * 32 - Burner menu
 * 64 - CD info menu
 * 128 - Temporary directory menu
 * 256 - Exit
 */
class Bbbase
{
    public:
        virtual ~Bbbase(){}
        virtual int run() = 0;
        enum returnValues {mMenu = 1, Audio = 2, Data = 4,
			   Images = 8, Config = 16, bMenu = 32,
			   cdiMenu = 64, tdMenu = 128, Exit = 256};
    protected:
	Commands mCommandSet;
	int mNumChoices;
};

#endif
