#include "../headers/units.h"
#include <cstring>
#include <iostream>

/*
 * CD reader methods
 */
CdReader::CdReader()
{
    SetPath("/dev/cdreader"); // Just for testing
}

CdReader::~CdReader() { }

void CdReader::SetPath(const std::string & inPath)
{
    mPath = inPath;
}

const std::string & CdReader::GetPath() const
{
    return mPath;
}

void CdReader::ViewCurrentConfig() const
{
	std::cout << "Path:\t\t\t" << (*this).GetPath() << std::endl;
}


/*
 * CD Burner methods
 */
CdBurner::CdBurner()
{
	// For testing
	SetPath("/dev/cdburner");
    SetSpeed(10);
    SetDriverOptions("burnfree");
    SetOverBurn("no");
    SetDiskTrackAtOnce("TAO");
    SetBlankingType("fast");
}

CdBurner::~CdBurner() {}

void CdBurner::SetSpeed(const int inSpeed)
{
    mSpeed = inSpeed;
}

const int CdBurner::GetSpeed() const
{
    return mSpeed;
}

void CdBurner::SetDriverOptions(const std::string & inDriverOptions)
{
	mDriverOptions = inDriverOptions;
}

const std::string & CdBurner::GetDriverOptions() const
{
	return mDriverOptions;
}

void CdBurner::SetOverBurn(const std::string & inOverburn)
{
	mAllowOverburn = inOverburn;
}

const std::string & CdBurner::GetOverBurn() const
{
	return mAllowOverburn;
}

void CdBurner::SetDiskTrackAtOnce(const std::string & inDTAO)
{
	mDiskTrackAtOnce = inDTAO;
}

const std::string & CdBurner::GetDiskTrackAtOnce() const
{
	return mDiskTrackAtOnce;
}
        
void CdBurner::SetBlankingType(const std::string & inBlankingType)
{
	mBlankingType = inBlankingType;
}
        
const std::string & CdBurner::GetBlankingType() const
{
	return mBlankingType;
}

void CdBurner::ViewCurrentConfig() const
{
	CdReader::ViewCurrentConfig();
	std::cout
		<< "Speed:\t\t\t" << GetSpeed() << std::endl
		<< "Options:\t\t" << GetDriverOptions() << std::endl
		<< "Overburn:\t\t" << GetOverBurn() << std::endl
		<< "Burning mode:\t\t" << GetDiskTrackAtOnce() << std::endl
		<< "Blanking mode:\t\t" << GetBlankingType() << std::endl;
}


/*
 * CD methods
 */
CD::CD()
{
	SetLabel("Test Label"); // For testing
	SetAuthor("Anders Lindén");
	SetCopyright("GNU GPL");
	SetDescription("Test CD");
}

CD::~CD() {}

void CD::SetLabel(const std::string & inLabel)
{
	mLabel = inLabel;
}

const std::string & CD::GetLabel() const
{
	return mLabel;
}

void CD::SetAuthor(const std::string & inAuthor)
{
	mAuthor = inAuthor;
}

const std::string & CD::GetAuthor() const
{
	return mAuthor;
}

void CD::SetCopyright(const std::string & inCopyRight)
{
	mCopyRight = inCopyRight;
}

const std::string & CD::GetCopyright() const
{
	return mCopyRight;
}

void CD::SetDescription(const std::string & inDescription)
{
	mDescription = inDescription;
}

const std::string & CD::GetDescription() const
{
	return mDescription;
}

void CD::ViewCurrentConfig() const
{
	std::cout
		<< "Label:\t\t\t" << GetLabel() << std::endl
		<< "Author:\t\t\t" << GetAuthor() << std::endl
		<< "Description:\t\t" << GetDescription() << std::endl
		<< "Copyright:\t\t" << GetCopyright() << std::endl;
}

/*
 * Temporary file storage directory methods
 */
TempDir::TempDir()
{
	SetPath("/tmp/burn"); // only for testing
	SetDeleteTemp("no");
}

TempDir::~TempDir() { }

void TempDir::SetPath(const std::string & inPath)
{
	mPath = inPath;
}

const std::string & TempDir::GetPath() const
{
	return mPath;
}

void TempDir::SetDeleteTemp(const std::string & inChoice)
{
	mDeleteContents = inChoice;
}

const std::string & TempDir::GetDeleteTemp() const
{
	return mDeleteContents;
}

void TempDir::ViewCurrentConfig() const
{
	std::cout
		<< "Path:\t\t\t" << GetPath() << std::endl
		<< "Delete after burn:\t" << GetDeleteTemp() << std::endl;
}
