#ifndef UI_H
#define UI_H

#include <string>
#include <vector>
#include <iterator>


/*
TODO:
- create global class variables "MaxNumberOfChoices", "MaxLengthOfInput"
*/



/*
This is the user-interface class for all tasks which human needs
to communicate with BashBurn (input and output). It is called
"Menu" because all communication between user and BashBurn is done via
MENUS, or DIALOGS called from a menu (input-request, info-text).

This class provides configuration-, output- and input-operations.
*/
class Menu
{
    private:
        // Define the set of language(s) bb2 currently supports (default==English):
        enum _Language {ENGLISH = 0};

        /*
        Defines a rule, how the input reader should look, feel and behave.
          - DEFAULT: basic c++ streams for input and output is used.
          - RL0: GNU "readline" is used to provide self-defined completion and history.
	         The data must be defined with "_setCompletionData()"!!
          - RL1: GNU "readline" is used to provide file completion and history.
          (- PASSWORD: The input is not printed directly - usable for password input.
	               Is NOT implemented, yet!!) */
        enum _InputMode {DEFAULT = 0, RL0, RL1};


    public:
  	// ---------- CONFIGURATION OPERATIONS --------------
        // IN1: title of the menu
  	Menu(const std::string & title = "Menu (no title given!)");

  	// Destructor - currently with no real function:
  	virtual ~Menu();

  	/* Method for adding menu choices (entrys). Note that choice 0 is treated
        as highest priority. This can have a meaning in some input dialog, which could treat the
        first choice as the default choice if the user has nothing else typed in.
        IN1: number where the menu choice should appear (0 == first menu choice,
              -1 == add after the currently last choice).
        IN2: name of the choice (it should be short, descriptive and unique).
        IN3: Help to the menu choice. Will be printed if requested with help function.
        RET: 1 == ok; 0 == failure. */
  	bool setChoice(int number, const std::string & choice, const std::string & help);

  	/* Method for getting a single menu choice (entry).
        IN1: number of menu choice (-1 == the currently last choice).
        RET: Returned name of the choice if there is one. */
  	std::string & getChoice(unsigned int number);

  	/* Method for getting all menu choices (entrys).
        IN1: returned choices.
        RET: 1 == ok; 0 == no choice available. */
  	std::vector<std::string> & getChoices();

        /*
	IN1: Number which menu choice you want delete.
        RET: 1=ok, 0=failure (nothing deleted). */
        bool deleteChoice(int number);

        /*
	RET: Number (count) of all registered choices in the menu. "-1" will be
             returned if a error occurs. */
        int & getNumberOfChoices();

  	/*
	IN1: Sets the title of menu object.
        RET: 1 == ok, title set; 0 == no title was set. */
	bool setTitle(const std::string & title);

  	// RET: Title of menu object.
  	const std::string & getTitle() const;

        /* Set the language for input and output of the menu user-interface.
        The possible translation could maybe done with GNU "gettext".
        Note that the configuration menu
        should call this method to inform this user-interface about a language
        changing, or if another than the default one should be taken.
        IN1: Language number (0 == default (English)).
        RET: 0 if requested language is not supported and therefore could not be choosen. */
	bool setLanguage(_Language language);


   	//  ---------- OUTPUT OPERATIONS --------------
   	/* Display a error "message" for the current menu or dialog.
   	This should be used if the programm is not able to go allong without
   	the help of the user or if it is a critical problem with BashBurn itself
   	(which - we hope - will never occur  ;-) ).
        IN1: Title for the current message.
        IN2: Message to print which should describe the error user-friendly.
        RET: 0 if something could not be showed correctly. */
        bool showError(const std::string & title, const std::string & message);

        /* Display a info "message" for the current menu or dialog. A info
   	should be used if the programm wants to say something to the user which
   	is task specific, e.g. a info-message that no CD is mounted if a user want
   	to eject it.
        IN1: Title for the current message.
        IN2: Message to print.
        RET: 0 if something could not be showed correctly. */
  	bool showInfo(const std::string & title, const std::string & message) const;

        /* Display a table described with "table" and "columns".
        IN1: Title for the table displayed.
        IN2: Vector with table data. The data should be start at index "0" and should
	     continously grow. So if you have a table head, you had to store it at first
	     in the vector. The data will be printed in the order it is stored in the vector.
	     With the following "columns" argument, the vector will be divided in rows each
	     "columns"-time.
        IN3: Number of columns the table has.
	IN4: 1 == table has head; 0 == table has no head (this is for pretty printing).
        RET: 0 if something could not be showed correctly, 1 if ok.*/
  	bool showTable(const std::string & title, std::vector<std::string> & table,
		       int columns, bool has_head);
  	
        /* Display the help "message" for the current menu which was given with
	"setChoice()".
        RET: 0 if something could not be showed correctly. */
	bool showHelp();

  	/* Show the menu with all it's options:
        RET: 0 == menu could probably not be showed correctly, 1 otherwise. */
  	bool show();


        // ---------- INPUT OPERATIONS --------------
        /* Prints "message" and asks for a number "number" to type in. It returns "0"
        if no valid input is given. The input is taken as valid if: it is no string and
	"value_min" >= input-value <= "value_max".
        IN1: message to print to ask the user for a integer number to type in.
        IN2: minimum value the input must have.
        IN3: maximum value the input must have.
	IN4: Where to store given input (only used if return is not false).
        RET: 0 == got no valid input; 1==ok, got valid integer in "input". */
        bool askForInteger(const std::string & message, int value_min, int value_max,
			   int & input);

        /* Prints "message" and asks for a string "input" to type in. It returns "0"
	if no valid input is given (after 3 choices by error). The input is taken
	as valid if:  "length_min" >= input-length <= "length_max".
	NOTE: also a string "4534" could be valid (even if it looks like a
	number) because we interpret it simply as a string!
        IN1: message to print to ask the user for a string to type in.
        IN2: minimum length the input must have.
        IN3: maximum length the input must have.
	IN4: Where to store given input - if return is not false.
        RET: 0 == got no valid input; 1 == ok, got valid string in "input" */
  	bool askForString(const std::string & message, unsigned int length_min, unsigned int length_max,
			  std::string & input);

        /* Prints "message" who requests the user to type in one choice.
        If the user types return - the default (first element in vector) is automatically selected
        (after user-confirmation).
        IN1: message to print and asking the user for a choice to type in.
        IN2: List of choices the user must choice exactly ONE.
	IN3: Where to store (completed) input string if return is not false.
        RET: 0 == got no valid input; 1==ok, got valid choice in "input". */
        bool askForChoice(const std::string & message, const std::vector<std::string> & choices,
			  std::string & input);


    protected:
        /* Low level function for reading user input without any checking.
	This must only used inside this class.
	The user normally NEVER should use this method directly!!
	IN1: Mode which should be used as input feel and behaviour.
	IN2: Where to store given input - if return is not false.
	RET: 0 == got no valid input; 1 == got valid input in "input".*/
        bool _readUserInput(_InputMode mode, std::string & input);

        /* Low level function for setting the choice data for completion.
	This must only used inside this class.
	The user normally NEVER should use this method directly!!
	IN1: Referenz to data which defines a set of choices where completion should work with.
	RET: 0 == nothing set, 1 == data was set. */
        bool _setCompletionData(const std::vector<std::string> & choices);

    private:
	// Title for the menu:
	std::string Title;

	// current number of set choices:
	int choice_count;

	// Container for all added menu choices:
  	std::vector<std::string> Choices;

	// Container for all added menu help:
  	std::vector<std::string> Help;

	// Iterator for a list like above:
  	std::vector<std::string>::iterator it;
};




/* Alternative user-interface without menus. It "only" provides command
line input and output (like a shell). Maybe this will be usefull for
some things. But currently this is only thought as a place-holder, to show
where such possible declarations should be placed and why this file is
called "ui.h" and not "menu.h".

class CommandLine
{
}

*/


#endif
