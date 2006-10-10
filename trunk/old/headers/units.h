#ifndef UNITS_H_
#define UNITS_H_

#include <string>

/*
 * Definitions for "units" used by BashBurn
 */

 /*
  * The CD reader class represents the CD reader unit used by BashBurn.
  * It contains methods for setting/getting the path to it.
  * (No need for anything else regarding the reader)
  */
class CdReader
{
    public:
        CdReader();
        virtual ~CdReader();
        void SetPath(const std::string & inPath);
        const std::string & GetPath() const;
        void ViewCurrentConfig() const;
    private:
        std::string mPath;
};

/*
 * The burner unit inherits from the reader and adds functionality
 * to set the burner specific features.
 */
class CdBurner : public CdReader
{
    public:
        CdBurner();
        ~CdBurner();
        void SetSpeed(const int speed);
        const int GetSpeed() const;

        void SetDriverOptions(const std::string & inDriverOptions);
        const std::string & GetDriverOptions() const;

        void SetOverBurn(const std::string & inOverburn);
        const std::string & GetOverBurn() const;

        void SetDiskTrackAtOnce(const std::string & inDTAO);
        const std::string & GetDiskTrackAtOnce() const;

        void SetBlankingType(const std::string & inBlankingType);
        const std::string & GetBlankingType() const;

        void ViewCurrentConfig() const;
    private:
        int mSpeed;
        std::string mDriverOptions;
        std::string mAllowOverburn;
        std::string mDiskTrackAtOnce;
        std::string mBlankingType;
};

/*
 * The CD contains functions for setting/getting info
 * about its contents.
 */
class CD
{
	public:
		CD();
		~CD();
		void SetLabel(const std::string & inLabel);
		const std::string & GetLabel() const;
		void SetAuthor(const std::string & inAuthor);
		const std::string & GetAuthor() const;
		void SetCopyright(const std::string & inCopyRight);
		const std::string & GetCopyright() const;
		void SetDescription(const std::string & inDescription);
		const std::string & GetDescription() const;
		void ViewCurrentConfig() const;
	private:
		std::string mLabel;
		std::string mAuthor;
		std::string mCopyRight;
		std::string mDescription;
};

/*
 * Just as with the CD not a unit in the strictest sense of the world.
 * Contains functions for setting temporary directory info
 */
class TempDir
{
	public:
		TempDir();
		~TempDir();
		void SetPath(const std::string & inPath);
		const std::string & GetPath() const;
		void SetDeleteTemp(const std::string & inChoice);
		const std::string & GetDeleteTemp() const;
		void ViewCurrentConfig() const;
	private:
		std::string mPath;
		std::string mDeleteContents;
};

#endif
