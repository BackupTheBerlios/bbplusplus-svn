#include "../includes/commands.h"
#include <cstdlib>

/*
 * The command set used should be a singleton
 */
Commands* Commands::commandInstance = 0;

Commands* Commands::Instance() {
	if(commandInstance == 0) {
		commandInstance = new Commands;
	}
	return commandInstance;
}

Commands::Commands() {
	initCommands();
}

Commands::~Commands() {
	//delete commandInstance;
}

void Commands::initCommands() {
	setCdBurnCommand("cdrecord");
	setDvdBurnCommand("growisofs");
	setClearCommand("clear");
}

void Commands::setCdBurnCommand(const std::string & command) {
	/*
	 * if(!firstTime)
	 * 	delete[] cdBurnCommand;
	 * cdBurnCommand = new char[strlen(command) + 1];
	 * strcpy(cdBurnCommand, command);
	 * firstTime = false;
	 */
	 cdBurnCommand = command;
}

void Commands::setDvdBurnCommand(const std::string & command) {
	/*
	 * if(firstTime)
	 * 	delete[] dvdBurnCommand;
	 * dvdBurnCommand = new char[strlen(command) + 1];
	 * strcpy(dvdBurnCommand, command);
	 * firstTime = false;
	 */
	 dvdBurnCommand = command;
}

void Commands::setClearCommand(const std::string & command) {
	/*
	 * if(firstTime)
	 * 	delete[] clearCommand;
	 * clearCommand = new char[strlen(command) + 1];
	 * strcpy(clearCommand, command);
	 * firstTime = false;
	 */
	 clearCommand = command;
}

void Commands::clearScreen() {
	system(getClearCommand());
}

const char* Commands::getCdBurnCommand() {
	return cdBurnCommand.c_str();
}

const char* Commands::getDvdBurnCommand() {
	return dvdBurnCommand.c_str();
}

const char* Commands::getClearCommand() {
	return clearCommand.c_str();
}
