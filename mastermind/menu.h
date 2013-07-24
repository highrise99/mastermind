/*! \file menu.h
 *  the header of menu
 */

#ifndef MENU_H // #include guard

#define MENU_H
#include <string>
#include <vector>
#include <iostream>

struct command_struct { // a command
    std::string identifier; // the identifier of the command
    std::string command_string; // the command
    int struct_return_int; // the integer returned if the command is executed
};

class menu { // a menu
private:
    std::string prompt; // a prompt
    std::vector<command_struct> list; // a list of the commands
    std::string input_prompt; // the prompt for input
    std::string bad_input; // the error output if the input is bad
    int class_return_int; // the return integer of the identified command
public:
    menu(std::string, std::string, std::string, std::vector<command_struct>);
    void acquire();
    int function_return_int();
};

#endif // MENU_H