#include "../includes/filereader.h"
#include <iostream>

FileReader::FileReader() {
	configFile.open("test.txt");
}

FileReader::~FileReader() {
	configFile.close();
}

void FileReader::putText(char* inputText) {
	configFile << inputText;
}
