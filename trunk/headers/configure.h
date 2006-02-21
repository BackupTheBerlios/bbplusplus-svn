#ifndef CONFIGURE_H_
#define CONFIGURE_H_

#include "bbbase.h"
#include "ui.h"
#include "units.h"
#include "tasks/burnermenu.h"
#include "tasks/cdinfomenu.h"
#include "tasks/tempdirmenu.h"

class Configure : public Bbbase
{
    public:
        Configure();
        virtual ~Configure();
        void ReadReader();
        void SetReader(const std::string & inPath);
        const void ViewCurrentConfig() const;
        // Small help functions
        CdBurner & ReturnBurner();
        CdReader & ReturnReader();
        CD & ReturnCD();
        TempDir & ReturnTempDir();
		int run();
    private:
    	int mCurrentState;
        CdReader mReader;
        CdBurner mBurner;
        CD mCD;
        TempDir mTempDir;
        Menu configMenu;
        BurnerMenu* burnerMenu;
        CDInfo* cdInfo;
        TempDirMenu* tempDirMenu;
        int mChoice;
        std::string mInput;
};

#endif
