#ifndef COMMANDS_H_
#define COMMANDS_H_

#include <memory>
#include <string>

class Commands {
	public:
		~Commands();
		static Commands* Instance();
		void setCdBurnCommand(const std::string & command);
		void setDvdBurnCommand(const std::string & command);
		void setClearCommand(const std::string & command);
		void clearScreen();
	/*
	 * Helper methods not supposed to be used outside the class
	 */
	protected:
		Commands();
		void initCommands();
		const char* getCdBurnCommand();
		const char* getDvdBurnCommand();
		const char* getClearCommand();
	private:
		//bool firstTime;
		std::string cdBurnCommand;
		std::string dvdBurnCommand;
		std::string clearCommand;
		static Commands* commandInstance;
};

#endif /*COMMANDS_H_*/
