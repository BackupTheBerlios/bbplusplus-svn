#include <iostream>
#include "../headers/bbstart.h"

// Just start an instance of BashBurn
int main(int argc, char* argv[])
{
	/*
	if(argc > 1){
		if(argv[1] == "--audio"){
			std::cout << "Audio\n";
			exit(0);
		}else{
			char* selectInstance = argv[1];
			std::cout << selectInstance << std::endl;
			exit(0);
			}
		}
		*/
	Bbstart myInstance;
	myInstance.run();
	return 0;
}
