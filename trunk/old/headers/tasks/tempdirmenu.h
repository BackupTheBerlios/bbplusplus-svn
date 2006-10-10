#ifndef TEMPDIRMENU_H_
#define TEMPDIRMENU_H_

#include "../bbbase.h"
#include "../ui.h"
#include "../units.h"

/*
 * tempdirmenu.h - Definitions for tempdirmenu methods
 */
class TempDirMenu : public Bbbase
{
	public:
		TempDirMenu(TempDir & inTempDir);
		~TempDirMenu();
		int run();
		void ReadPath();
		void SetPath(const std::string & inPath);
		const std::string & GetPath() const;
		void ReadDeleteTemp();
		void SetDeleteTemp(const std::string & inChoice);
		const std::string & GetDeleteTemp() const;
		void ViewCurrentConfig() const;
	private:
		Menu tempDirMenu;
		TempDir* mTempDir;
		int mChoice;
		std::string mInput;
};

#endif /*TEMPDIRMENU_H_*/
