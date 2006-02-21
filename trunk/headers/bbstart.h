#ifndef BBSTART_H
#define BBSTART_H

#include "bbbase.h"
#include "commands.h"
#include "tasks/mainmenu.h"
#include "tasks/burnermenu.h"
#include "tasks/cdinfomenu.h"
#include "tasks/tempdirmenu.h"
#include "tasks/datamenu.h"
#include "tasks/audiomenu.h"
#include "tasks/imagemenu.h"
#include "configure.h"
#include <string>

class Bbstart : public Bbbase
{
    public:
        Bbstart();
        virtual ~Bbstart();
        int run();
    private:
    	int mNextState;
        MainMenu* mMainMenu; // Menu pointer
        AudioMenu* mAudioMenu;
        DataMenu* mDataMenu;
        ImageMenu* mImageMenu;
        Configure* mConfiguration; // Configuration pointer
        BurnerMenu* mBurnerMenu;
        CDInfo* mCdInfoMenu;
        TempDirMenu* mTempDirMenu;
        Bbbase* mCurrentState; // Current state pointer
};

#endif
