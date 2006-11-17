#ifndef FILE_READER_H_
#define FILE_READER_H_

#include <fstream>

class FileReader {
	public:
		FileReader();
		~FileReader();
		void putText(char*);
	private:
		char* burnUnit;
		std::ofstream configFile;
};

#endif
