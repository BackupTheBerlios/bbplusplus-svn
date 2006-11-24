#include "../includes/filehandler.h"
#include <iostream>

FileHandler::FileHandler() {
	inConfigFile.open("/home/conny/bb.rc");
	outConfigFile.open("/home/conny/bb.rc");

}

FileHandler::~FileHandler() {
	inConfigFile.close();
	outConfigFile.close();	
}

void FileHandler::putText(const char* inputText) {
	outConfigFile << inputText;
}
