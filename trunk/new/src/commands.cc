#include "../includes/commands.h"
#include <cstdlib>
#include <cstring>

/*
 * The commands used should be a singleton
 */
Commands* Commands::commandInstance = 0;
Commands* Commands::Instance() {
	if(commandInstance == 0) {
		commandInstance = new Commands;
	}
	return commandInstance;
}

Commands::Commands() : firstTime(true) {
	initCommands();
}

Commands::~Commands() {
	delete[] cdBurnCommand;
	delete[] dvdBurnCommand;
	delete[] clearCommand;
}

void Commands::initCommands() {
	setCdBurnCommand("cdrecord");
	setDvdBurnCommand("growisofs");
	setClearCommand("clear");
}

void Commands::setCdBurnCommand(const char* command) {
	if(!firstTime) 
		delete[] cdBurnCommand;
	cdBurnCommand = new char[strlen(command) + 1];
	strcpy(cdBurnCommand, command);
	firstTime = false;
}

void Commands::setDvdBurnCommand(const char* command) {
	if(firstTime)
		delete[] dvdBurnCommand;
	dvdBurnCommand = new char[strlen(command) + 1];
	strcpy(dvdBurnCommand, command);
	firstTime = false;
}

void Commands::setClearCommand(const char* command) {
	if(firstTime)
		delete[] clearCommand;
	clearCommand = new char[strlen(command) + 1];
	strcpy(clearCommand, command);
	firstTime = false;
}

void Commands::clearScreen() {
	system(getClearCommand());
}

const char* Commands::getCdBurnCommand() {
	return cdBurnCommand;
}

const char* Commands::getDvdBurnCommand() {
	return dvdBurnCommand;
}

const char* Commands::getClearCommand() {
	return clearCommand;
}
