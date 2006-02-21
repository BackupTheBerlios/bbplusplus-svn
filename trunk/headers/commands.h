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
		char* GetSleepCommand();
		void SetClearCommand(char* inCommand);
		char* GetClearCommand();
		/*
		 * Burning and image creation commands
		 */		
		void SetBurnCommand(char* inCommand);
		char* GetBurnCommand();
		void SetReadCDCommand(char* inCommand);
		char* GetReadCDCommand();
		void SetCreateImageCommand(char* inCommand);
		char* GetCreateImageCommand();
		/*
		 * Commands related to audio CDs
		 */
		 void SetCDToAudioCommand(char* inCommand);
		 char* GetCDToAudioCommand();
		 void SetMp3EncCommand(char* inCommand);
		 char* GetMp3EncCommand();
		 void SetOggEncCommand(char* inCommand);
		 char* GetOggEncCommand();
	private:
		char* mSleepCommand;
		char* mClearCommand;
		
		char* mBurnCommand;
		char* mReadCDCommand;
		char* mCreateImageCommand;
		
		char* mCDToAudioCommand;
		char* mMp3EncCommand;
		char* mOggEncCommand;	
 };

#endif /*COMMANDS_H_*/

