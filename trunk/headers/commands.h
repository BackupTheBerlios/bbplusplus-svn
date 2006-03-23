#ifndef COMMANDS_H_
#define COMMANDS_H_

/*
 * This file contains definitions of methods to get and set
 * the commands used by BashBurn.
 */
 class Commands
 {
	public:
		Commands();
		~Commands();
		/*
		 * General system commands not related to burning or copying
		 */
		void SetSleepCommand(char* inCommand);
		const char* GetSleepCommand() const;
		void SetClearCommand(char* inCommand);
		const char* GetClearCommand() const;
		/*
		 * Burning and image creation commands
		 */		
		void SetBurnCommand(char* inCommand);
		const char* GetBurnCommand()const;
		void SetReadCDCommand(char* inCommand);
		const char* GetReadCDCommand()const;
		void SetCreateImageCommand(char* inCommand);
		const char* GetCreateImageCommand()const;
		/*
		 * Commands related to audio CDs
		 */
		 void SetCDToAudioCommand(char* inCommand);
		 const char* GetCDToAudioCommand()const;
		 void SetMp3EncCommand(char* inCommand);
		 const char* GetMp3EncCommand()const;
		 void SetOggEncCommand(char* inCommand);
		 const char* GetOggEncCommand()const;
	private:
		char* mSleepCommand;
		char* mClearCommand;
		
		char* mBurnCommand;
		char* mReadCDCommand;
		char* mCreateImageCommand;
		
		char* mCDToAudioCommand;
		char* mMp3EncCommand;
		char* mOggEncCommand;
		
		char* operator+(char*);

 };

#endif /*COMMANDS_H_*/
