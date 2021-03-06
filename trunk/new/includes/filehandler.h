#ifndef FILE_HANDLER_H_
#define FILE_HANDLER_H_

#include <fstream>

class FileHandler {
	public:
		FileHandler(const char*);
		~FileHandler();
		void putText(const char*);
		void getConfig(const char*);
	private:
		std::ifstream inConfigFile;
		std::ofstream outConfigFile;
		
};

#endif
