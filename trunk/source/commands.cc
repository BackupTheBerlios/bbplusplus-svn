#include "../headers/commands.h"
#include <cstring>

/*
 * Command methods
 * We initialize the command pointers to NULL, party because it's
 * good style to do so, and partly because of the SetXXXCommand methods below.
 * If a pointer isn't null, it must first be deleted to free memory when setting
 * a command. If we didn't initialize the pointers, the check whether they are
 * NULL or not would fail since they would point to garbage and therefore not be NULL,
 * with a seg fault as a result. We _could_ choose to not initialize the pointers
 * and add ClearXXXCommand methods to the class. This however would not only be a bad
 * solution, it would also require the coder to remember to run the clear-method
 * before each set-method. Otherwise memory leaks would appear. 
 */
Commands::Commands()
	: mSleepCommand(NULL), mClearCommand(NULL), mBurnCommand(NULL), mReadCDCommand(NULL),
	mCreateImageCommand(NULL), mCDToAudioCommand(NULL), mMp3EncCommand(NULL),
	mOggEncCommand(NULL)
{
	SetSleepCommand("sleep 2s");
	SetClearCommand("clear");
	SetBurnCommand("cdrecord");
	SetReadCDCommand("readcd");
	SetCreateImageCommand("mkisofs");
	SetCDToAudioCommand("cdda2wav");
	SetMp3EncCommand("lame");
	SetOggEncCommand("oggenc");
}

Commands::~Commands()
{
	delete[] mSleepCommand;
	delete[] mClearCommand;
	delete[] mBurnCommand;
	delete[] mReadCDCommand;
	delete[] mCreateImageCommand;
	delete[] mCDToAudioCommand;
	delete[] mMp3EncCommand;
	delete[] mOggEncCommand;
}

/*
 * Methods for the sleep command
 */
void Commands::SetSleepCommand(char* inCommand)
{
	if(GetSleepCommand() != NULL)
		delete[] mSleepCommand;
	mSleepCommand = new char[std::strlen(inCommand) + 1];
	std::strcpy(mSleepCommand, inCommand);
}

char* Commands::GetSleepCommand()
{
	return mSleepCommand;
}

/*
 * Methods for the clear command
 */
void Commands::SetClearCommand(char* inCommand)
{
	if(GetClearCommand() != NULL)
		delete[] mClearCommand;
	mClearCommand = new char[std::strlen(inCommand) + 1];
	std::strcpy(mClearCommand, inCommand);
}

char* Commands::GetClearCommand()
{
	return mClearCommand;
}

/*
 * Methods for the burn command
 */
void Commands::SetBurnCommand(char* inCommand)
{
	if(GetBurnCommand() != NULL)
		delete[] mBurnCommand;
	mBurnCommand = new char[std::strlen(inCommand) + 1];
	std::strcpy(mBurnCommand, inCommand);
}

char* Commands::GetBurnCommand()
{
	return mBurnCommand;
}

/*
 * Methods for the readcd command
 */
void Commands::SetReadCDCommand(char* inCommand)
{
	if(GetReadCDCommand() != NULL)
		delete[] mReadCDCommand;
	mReadCDCommand = new char[std::strlen(inCommand) + 1];
	std::strcpy(mReadCDCommand, inCommand);
}

char* Commands::GetReadCDCommand()
{
	return mReadCDCommand;
}

/*
 * Methods for image creating command
 */
void Commands::SetCreateImageCommand(char* inCommand)
{
	if(GetCreateImageCommand() != NULL)
		delete[] mCreateImageCommand;
	mCreateImageCommand = new char[std::strlen(inCommand) + 1];
	std::strcpy(mCreateImageCommand, inCommand);
}

char* Commands::GetCreateImageCommand()
{
	return mCreateImageCommand;
}

/*
 * Methods for CD ripping
 */
void Commands::SetCDToAudioCommand(char* inCommand)
{
	if(GetCDToAudioCommand() != NULL)
		delete[] mCDToAudioCommand;
	mCDToAudioCommand = new char[std::strlen(inCommand) + 1];
	std::strcpy(mCDToAudioCommand, inCommand);
}

char* Commands::GetCDToAudioCommand()
{
	return mCDToAudioCommand;
}

/*
 * Methods for Mp3 encoding
 */
void Commands::SetMp3EncCommand(char* inCommand)
{
	if(GetMp3EncCommand() != NULL)
		delete[] mMp3EncCommand;
	mMp3EncCommand = new char[std::strlen(inCommand) + 1];
	std::strcpy(mMp3EncCommand, inCommand);
}

char* Commands::GetMp3EncCommand()
{
	return mMp3EncCommand;
}

/*
 * Methods for OGG encoding
 */
void Commands::SetOggEncCommand(char* inCommand)
{
	if(GetOggEncCommand() != NULL)
		delete[] mOggEncCommand;
	mOggEncCommand = new char[std::strlen(inCommand) + 1];
	std::strcpy(mOggEncCommand, inCommand);
}

char* Commands::GetOggEncCommand()
{
	return mOggEncCommand;
}
