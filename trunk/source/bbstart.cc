#include "../headers/bbstart.h"
#include <iostream>

/*
 * Sends the program along to a new state, depending on
 * what the currentState pointer gets set to.
 */

Bbstart::Bbstart() 
{
    mMainMenu = new MainMenu();
    mConfiguration = new Configure();
    /*
     * The following menus needs an object to work on.
     * Because of this, we use some help functions from
     * the configure class to pass these objects to their
     * respective menu.
     */
    mBurnerMenu = new BurnerMenu(mConfiguration->ReturnBurner());
    mCdInfoMenu = new CDInfo(mConfiguration->ReturnCD());
    mTempDirMenu = new TempDirMenu(mConfiguration->ReturnTempDir());
    mAudioMenu = new AudioMenu(mConfiguration->ReturnTempDir(), mConfiguration->ReturnBurner(),
			       mConfiguration->ReturnReader());
    mDataMenu = new DataMenu(mConfiguration->ReturnTempDir(), mConfiguration->ReturnBurner());
    mImageMenu = new ImageMenu(mConfiguration->ReturnTempDir(), mConfiguration->ReturnBurner());
}

Bbstart::~Bbstart()
{
    delete mMainMenu;
    delete mConfiguration;
    delete mAudioMenu;
    delete mDataMenu;
    delete mImageMenu;
    delete mBurnerMenu;
    delete mCdInfoMenu;
    delete mTempDirMenu;
}

int Bbstart::run()
{
/*
 * Always start with the main menu. I guess here you could also
 * check if any arguments (Like --iso, --audio, --data) were given
 * to the program and set the currentState pointer to respective state right away.
 * For now, we're happy with just starting the main menu.
 * (Because we all know that what is good enough for Anders is good enough for you!)
 */
    mCurrentState = mMainMenu;

    while(true)
    {
        mNextState = mCurrentState->run();

        if(mNextState == mMenu)
        {
            mCurrentState = mMainMenu;
        }
        else if(mNextState == Audio)
        {
            mCurrentState = mAudioMenu;
        }
        else if(mNextState == Data)
        {
            mCurrentState = mDataMenu;
        }
        else if(mNextState == Images)
        {
            mCurrentState = mImageMenu;
        }
        else if(mNextState == Config)
        {
            mCurrentState = mConfiguration;
        }
        else if(mNextState == bMenu)
        {
        	mCurrentState = mBurnerMenu;
        }
        else if(mNextState == cdiMenu)
        {
        	mCurrentState = mCdInfoMenu;
        }
        else if(mNextState == tdMenu)
        {
        	mCurrentState = mTempDirMenu;
        }
        else if(mNextState == Exit)
        {
	  	std::cout << "\nThank you for using " << bbVersion << std::endl
                 << "For info and updates, visit http://bashburn.sf.net\n";
		return 0;
        }
    }
}
