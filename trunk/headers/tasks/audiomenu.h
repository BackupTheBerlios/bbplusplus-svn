#ifndef AUDIOMENU_H_
#define AUDIOMENU_H_

#include "../bbbase.h"
#include "../ui.h"
#include "../units.h"

class AudioMenu : public Bbbase
{
    public:
    /*
     * The audio menu constructor.
     * IN1: The temporary directory for files to burn
     * IN2: Burner unit to use
     * IN3: Reader unit to use
     */
     AudioMenu(TempDir & inTempDir, CdBurner & inCdBurner, CdReader & inCdReader);
        ~AudioMenu();
        void BurnCDFromFiles();
        void CopyCDToCD();
        void RipCDToHarddrive();
        void CreateMp3s();
        void CreateOggs();
        void CreateFlacs();
        int run();
    private:
        Menu auMenu;
        int choice;
        TempDir* mTempDir; 
        CdBurner* mCdBurner;
        CdReader* mCdReader;
};

#endif /*AUDIOMENU_H_*/
