/* menu.cpp
 * --------
 * This is the C++ header file for the class "menu."
 */

#include "menu.h"

/* menu::menu
 * ----------
 * Arguments:
 *     - std::string title: the title of the menu
 *     - std::string constructor_input_prompt: a prompt for input after the menu (e.g. "input: ")
 *     - std::string constructor_bad_input: the error output if the input is invalid
 *     - std::vector<command_struct> constructor_list: a list of commands
 * returns: N/A (Constructors cannot have a return type.)
 * Initializes:
 *     - list: w/ constructor_list
 *     - inpur_prompt: w/ constructor_command_prompt
 *     - bad_input: w/ constructor_bad_input
 */
menu::menu(std::string title, std::string constructor_input_prompt, std::string constructor_bad_input,
           std::vector<command_struct> constructor_list) {
    prompt += "\n" + title + "\n\n"; // The prompt will include a newline, the title, two more newlines...
    list = constructor_list;

    for(std::vector<command_struct>::size_type command_number = 0; command_number < list.size(); command_number++) /* for each command in the
                                                                                                                    * list...
                                                                                                                    */
        prompt += "    " + list[command_number].identifier + ". " + list[command_number].command_string + "\n"; /* ...two newlines,
                                                                                                * (looped for each command) a 4-space indent,
                                                                                                * a handle string, a period, a space (end loop)...
                                                                                                */

    prompt += "\n"; // ...a space (end loop), and another newline.
    input_prompt = constructor_input_prompt;
    bad_input = constructor_bad_input;
}

/* menu::acquire
 * Arguments: N/A
 * returns: the return value of the identified command
 */
void menu::acquire() {
    std::vector<command_struct>::size_type command_number; // the number of the command being accessed in the list
    bool input_bad = true; // Is the input bad?

    std::cout << prompt; // prompting...

    while(input_bad == true) {
        std::string buffer; // input

        std::cout << input_prompt; // ...prompting for input
        std::getline(std::cin, buffer);
        for(command_number = 0; command_number < list.size(); command_number++) { // for each command in the list...
            if(buffer == list[command_number].identifier) { /* If the input equals the identifier of a command, the loop breaks at the respective
                                                             * command number.
                                                             */
                input_bad = false;
                break;
            }
        }

        if(input_bad == true) /* If "input_bad" is not false after the loop, then the input did not equal the identifier of any command and is
                               * therefore bad. The respective error code is output.
                               */
            std::cout << bad_input;
    }

    input = list[command_number].return_integer; // The return value of the identified command is returned.
}

int menu::return_input() {
    return(input);
}