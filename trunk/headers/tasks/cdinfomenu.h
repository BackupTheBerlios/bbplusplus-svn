#ifndef CD_INFO_H_
#define CD_INFO_H_

#include "../bbbase.h"
#include "../ui.h"
#include "../units.h"

/*
 * cdinfomenu.h - Definitions of cdinfomenu methods
 */
class CDInfo : public Bbbase
{
    public:
        CDInfo(CD & inCD);
        ~CDInfo();
        int run();
        
        void ReadLabel();
        void SetLabel(const std::string & inLabel);
		const std::string & GetLabel() const;
		
		void ReadAuthor();
		void SetAuthor(const std::string & inAuthor);
		const std::string & GetAuthor() const;
		
		void ReadDescription();
		void SetDescription(const std::string & inDescription);
		const std::string & GetDescription() const;
		
		void ReadCopyright();
		void SetCopyright(const std::string & inCopyRight);
		const std::string & GetCopyright() const;
		
		void ViewCurrentConfig() const;
    private:
        Menu cdInfoMenu;
        int choice;
        CD* mCD;
        std::string mInput;
};

#endif
