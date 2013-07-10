/* menu.cpp
 * --------
 * This is the C++ header file for the class "menu."
 */

#include "menu.h"

/* menu::menu
 * ----------
 * Arguments:
 *     - std::string title: the title of the menu
 *     - std::string constructor_input_prompt: the prompt for input
 *     - std::string constructor_bad_input: the error output if the input is bad
 *     - std::vector<command_struct> constructor_list: a list of the commands
 * returns: N/A (Constructors cannot have a return type.)
 * Initializes:
 *     - "list" w/ "constructor_list"
 *     - "input_prompt" w/ "constructor_command_prompt"
 *     - "bad_input" w/ "constructor_bad_input"
 */
menu::menu(std::string title, std::string constructor_input_prompt, std::string constructor_bad_input,
           std::vector<command_struct> constructor_list) {
    prompt += "\n" + title + "\n\n"; // The prompt will include a newline, the title, two more newlines...
    list = constructor_list;

    for(std::vector<command_struct>::size_type command_number = 0; command_number < list.size(); command_number++)
        prompt += "    " + list[command_number].identifier + ". " + list[command_number].command_string + "\n"; /* ...two newlines,
                                                                                                * (looped for each command in the list) a 4-space
                                                                                                * indent, a handle string, a period,
                                                                                                * a space (end loop)...
                                                                                                */

    prompt += "\n"; // ...a space (end loop), and another newline.
    input_prompt = constructor_input_prompt;
    bad_input = constructor_bad_input;
}

/* menu::acquire
 * -------------
 * Arguments: N/A
 * returns: void
 * initializes the return integer with that of the identified command
 */
void menu::acquire() {
    std::vector<command_struct>::size_type command_number; // the number of the command in the list
    bool input_bad = true; // Is the input bad?

    std::cout << prompt; // prompting...

    while(input_bad == true) {
        std::string buffer; // input

        std::cout << input_prompt; // ...prompting for input
        std::getline(std::cin, buffer);
        for(command_number = 0; command_number < list.size(); command_number++) { // for each command in the list
            if(buffer == list[command_number].identifier) { /* If the input equals the identifier of a command, then the loop breaks at that
                                                             * command number.
                                                             */
                input_bad = false;
                break;
            }
        }

        if(input_bad == true) /* If "input_bad" is not false after the loop, then the input did not equal the identifier of a command and is bad.
                               * The error for bad input is output.
                               */
            std::cout << bad_input;
    }

    class_return_int = list[command_number].struct_return_int;
}

/* menu::function_return_int
 * -------------------------
 * Arguments: N/A
 * returns: the return integer of the identified command
 */
int menu::function_return_int() {
    return(class_return_int);
}