#ifndef DATAMENU_H_
#define DATAMENU_H_

#include "../bbbase.h"
#include "../ui.h"
#include "../units.h"

class DataMenu : public Bbbase
{
    public:
        DataMenu(TempDir & inTempDir, CdBurner & inCdBurner);
        ~DataMenu();
        void BurnCDFromFiles();
        void CopyCDToCD();
        void BurnDVDFromFiles();
        void CopyDVDToDVD();
        int run();
    private:
        Menu dMenu;
        int choice;
        TempDir* mTempDir;
        CdBurner* mCdBurner;
};

#endif /*DATAMENU_H_*/
