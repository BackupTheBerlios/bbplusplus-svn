#ifndef IMAGEMENU_H_
#define IMAGEMENU_H_

#include "../bbbase.h"
#include "../ui.h"
#include "../units.h"

class ImageMenu : public Bbbase
{
    public:
        ImageMenu(TempDir & inTempDir, CdBurner & inCdBurner);
        ~ImageMenu();
        void BurnCDImage();
        void BurnDVDImage();
        void CreateISOFromHarddrive();
        void CreateISOFromDisc();
        int run();
    private:
        Menu iMenu;
        int choice;
        TempDir* mTempDir;
        CdBurner* mCdBurner;
};

#endif /*IMAGEMENU_H_*/
