#ifndef BURNER_MENU_H_
#define BURNER_MENU_H_

#include "../bbbase.h"
#include "../ui.h"
#include "../units.h"

/*
 * burnermenu.h - definitions of burnermenu methods
 */
class BurnerMenu : public Bbbase
{
    public:
        BurnerMenu(CdBurner & inBurner);
        ~BurnerMenu();
        int run();
        
		void ReadPath();
        void SetPath(const std::string & inPath);
		const std::string & GetPath() const;
		
		void ReadSpeed();
		void SetSpeed(const int inSpeed);
		const int GetSpeed() const;
		
		void ReadDriverOptions();
		void SetDriverOptions(const std::string & inDriverOptions);
		const std::string & GetDriverOptions() const;
		
		void ReadOverBurn();
		void SetOverBurn(const std::string & inOverBurn);
		const std::string & GetOverBurn() const;
		
		void ReadDiskTrackAtOnce();
		void SetDiskTrackAtOnce(const std::string & inDTAO);
		const std::string & GetDiskTrackAtOnce() const;
		
		void ReadBlankingType();
		void SetBlankingType(const std::string & inBlankingType);
		const std::string & GetBlankingType() const;
		
		void ViewCurrentConfig() const;
    private:
        Menu brnMenu;
        int mChoice;
		int mInputDigit;
        std::string mInput;
        CdBurner* mBurner;
};

#endif
