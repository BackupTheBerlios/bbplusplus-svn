#include "../includes/filehandler.h"
#include <iostream>

FileHandler::FileHandler(const char* inFile) {
	inConfigFile.open(inFile);
	outConfigFile.open(inFile);

}

FileHandler::~FileHandler() {
	inConfigFile.close();
	outConfigFile.close();	
}

void FileHandler::putText(const char* inputText) {
	outConfigFile << inputText;
}
