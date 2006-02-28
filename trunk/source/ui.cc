#include "../headers/ui.h"
#include <iostream>

namespace Readline {
  extern "C" {
#include <readline/readline.h>
#include <readline/history.h>
  }
}


namespace ReadlineHelper {
  // holds data for choice-completion:
  std::vector<std::string> completion_data;
  std::vector<std::string>::iterator it;
  char * giveMatch(const char *, int);  // forward declaration

  char ** doChoiceCompletion(const char *text, int start, int end) {
    char **matches;
    matches = (char **)NULL;

    matches = Readline::rl_completion_matches(text, giveMatch);
    return matches;
  }

  char ** doFileCompletion(const char *text, int start, int end) {
    char **matches;
    matches = (char **)NULL;

    if (start == 0)
      matches = Readline::rl_completion_matches(text, giveMatch);
    return matches;
  }


  /* Helper function for readline.
  IN1: text which should be tried to complete
  IN2: 0==first completion, otherwise some completion was already done.
  RET: completion string if found, NULL pointer otherwise. */
  char * giveMatch(const char *text, int state) {
    static unsigned int list_index, len;
    char *name, *name_new;
    std::string sname;

    if (!state) {
      list_index = 0;
      len = strlen(text);
    }
    while (list_index < completion_data.size()) {  // return next name
      sname = completion_data[list_index++];
      if (strncmp(sname.c_str(), text, len) == 0) {
	// name_new must be allocated per "malloc()" because readline free's it if it
	// is finished with it:
	name_new = (char *)(malloc(strlen(sname.c_str()) + 1));
	strcpy(name_new, sname.c_str());
	return name_new;
      }
    }
    return (char *)NULL;
  }
}



/*
 * Member initialized in the initializer list (That's what it's called right?) should
 * be initialized in the same order they are declared in the class.
 */
Menu::Menu(const std::string & title)
  : Title(title), choice_count(0)
{
  // Allow conditional parsing of the ~/.inputrc file.
  Readline::rl_readline_name = "bash_burn_2";
}


Menu::~Menu() 
{
  std::cout << "\nDeleting UI...";
}


bool Menu::setChoice(int number, const std::string & choice, const std::string & help)
{
  if (number >= 0) {  // store at position
    Choices.insert(Choices.begin() + number, choice);
    Help.insert(Help.begin() + number, help);
    ++choice_count;
    return 1;
  }
  else {  // store after current end-position
    Choices.push_back(choice);
    Help.push_back(help);
    ++choice_count;
    return 1;
  }

  return 0;
}


std::string & Menu::getChoice(unsigned int number)
{
  if ((number >= 0) && (number <= Choices.size())) {
    return Choices.at(0);
  }
  else {
    return Choices.back();
  }
}


std::vector<std::string> & Menu::getChoices()
{
  return Choices;
}


bool Menu::deleteChoice(int number)
{
  if (choice_count > 0) {
    Choices.erase(Choices.begin() + number);
    Help.erase(Help.begin() + number);
    --choice_count;
    return 1;
  }
  
  return 0;
}


int & Menu::getNumberOfChoices()
{
  return choice_count;
}


bool Menu::setTitle(const std::string & title)
{
  Title = title;

  return 1;
}


const std::string & Menu::getTitle() const
{
  return Title;
}


bool Menu::setLanguage(_Language language)
{
  return 0;  // Implementation not implemented yet!! TODO!
}


bool Menu::showError(const std::string & title, const std::string & message)
{
  std::cerr << "\033[1;31m" << "-- " << title << " --\n" << message << "\033[1;0m" << std::endl;

  return 1;
}


bool Menu::showInfo(const std::string & title, const std::string & message) const
{
  std::cout << "\033[1;32m" << "-- " << title << " --\n" << message << "\033[1;0m" << std::endl;

  return 1;
}


bool Menu::showTable(const std::string & title, std::vector<std::string> & table,
		     int columns, bool has_head)
{
  std::cout << "\033[1;32m" << title << "\033[1;0m" << "\n\n";

  if (! (table.size() % columns)) {  // table is defined correctly
    int num = 1;
    for (it = table.begin(); it != table.end(); ++it) {
      std::cout << *it;
      if (! (num % columns)) { // new row (maximal number of columns reached)
	std::cout << "\n";
	if ((num == columns) && (has_head))  // table has a head (seperate it with a "\n")
	  std::cout << "\n";
      }
      num++;
    }
    return 1;
  }

  return 0;
}


bool Menu::showHelp()
{
  int num = 0;
  std::cout << "\033[1;36m" << getTitle() << "\n\nHELP CHOICES:" << "\033[1;0m" << std::endl;

  for (it = Help.begin(); it != Help.end(); it++) {
    std::cout << num << ": " << *it << std::endl;
    num++;
  }

  return num;
}


bool Menu::show()
{
  //  system(mCommandSet.GetClearCommand());  // clear all
  int num = 0;
  std::cout << "\033[1;32m" << "[" << (*this).getTitle() << "\033[1;0m" << "]\n\n";
  for (it = Choices.begin(); it != Choices.end(); ++it) {
    std::cout << num << ": " << *it << std::endl;
    num++;
  }

  return num;
}


bool Menu::askForInteger(const std::string & message, int value_min, int value_max,
			 int & input)
{
	std::cout << message;
	std::cin >> input;

	if (std::cin.fail()) {  // wrong input format!
		std::cin.clear();
		std::cin.get();  // delete char in wrong format from input (to prevent a failure loop!!)
		return false;
	}
  	if ((input >= value_min) && (input <= value_max))
    	return true;
  	return false;
}


bool Menu::askForString(const std::string & message, unsigned int length_min, unsigned int length_max,
			std::string & input)
{
	std::cout << message;
  	std::cin.width(length_max + 1);  // set max. input length
  	std::cin >> input;
  	if ((input.length() >= length_min) && (input.length() <= length_max))
    	return true;
  	return false;
}


bool Menu::askForChoice(const std::string & message, const std::vector<std::string> & choices,
			std::string & input)
{
  std::string _input;

  std::cout << message;
  _setCompletionData(choices);
  if (_readUserInput(RL0, _input)) {
    //input = atoi(_input.c_str());
    input = _input;
    return 1;
  }
  return 0;
}


bool Menu::_readUserInput(_InputMode mode, std::string & input)
{
  char *line;
  switch (mode) {
  case RL0:  // Choice completion
    Readline::rl_attempted_completion_function = ReadlineHelper::doChoiceCompletion;
    while (line = Readline::readline("")) {
      if (!line) break;
      if (*line) {
	Readline::add_history(line);
	input = line;
      }
      // "line" must be freed with "free()" because readline has allocated it with "malloc()":
      free(line);
    }
    return 1;
  case RL1:  // File completion (readline standard behaviour)
    Readline::rl_attempted_completion_function = ReadlineHelper::doFileCompletion;
    while (line = Readline::readline("")) {
      if (!line) break;
      if (*line) {
	Readline::add_history(line);
	input = line;
      }
      // "line" must be freed with "free()" because readline has allocated it with "malloc()":
      free(line);
    }
    return 1;
  default:  // == DEFAULT
    while(!(std::cin >> input)) {
      std::cin.clear(); // Reset input in case of bad input
      while(std::cin.get() != '\n')
	continue;
    }
    return 1;
  }

  return 0;
}


bool Menu::_setCompletionData(const std::vector<std::string> & choices)
{
  ReadlineHelper::completion_data.clear();
  ReadlineHelper::completion_data = choices;

  return 1;
}
