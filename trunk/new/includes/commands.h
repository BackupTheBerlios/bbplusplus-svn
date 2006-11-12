#ifndef COMMANDS_H_
#define COMMANDS_H_

class Commands {
	public:
		Commands();
		~Commands();
		void setCdBurnCommand(const char* command);
		void setDvdBurnCommand(const char* command);
		void setClearCommand(const char* command);
		void clearScreen();
	/*
	 * Helper methods not supposed to be used outside the class
	 */
	protected:
		void initCommands();
		const char* getCdBurnCommand();
		const char* getDvdBurnCommand();
		const char* getClearCommand();
	private:
		bool firstTime;
		char* cdBurnCommand;
		char* dvdBurnCommand;
		char* clearCommand;
};

#endif /*COMMANDS_H_*/
