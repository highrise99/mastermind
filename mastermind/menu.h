/* menu.h
 * ------
 * This is the C++ header file for the class "menu."
 */

#include <string>
#include <vector>
#include <iostream>

struct command_struct {
    std::string identifier;
    std::string command_string;
    int return_integer;
};

class menu {
private:
    std::string prompt;
    std::vector<command_struct> list;
    std::string input_prompt;
    std::string bad_input;
    int input;
public:
    menu(std::string, std::string, std::string, std::vector<command_struct>);
    void acquire();
    int return_input();
};