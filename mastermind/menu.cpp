/* menu.cpp
 * --------
 * This is the C++ header file for the class "menu."
 */

#include "menu.h"

/* menu::menu
 * ----------
 * Arguments:
 *     - CONSTRUCTOR_MINIUM: the menu's minimum valid input value
 *     - CONSTRUCTOR_MAXIMUM: "[. . .]" maximum "[. . .]"
 *     - CONSTRUCTOR_ERRORS: contains the menu's error codes
 * returns: N/A (Constructors cannot have a return type.)
 * initializes "MINIMUM," "MAXIMUM," and "A_ERRORS"
 */

/* menu::acquire
 * Arguments: N/A
 * returns: void
 * gets input for the menu with an integer value less than "MAXIMUM" and greater than "MINIMUM"
 */
void menu::acquire() {
    bool input_bad; /* Is the input:
                     *     - too small
                     *     - too large?
                     * (If it is not a valid number, then it will not be within range.)
                     */

    do {
        std::string buffer; // raw input from the console

        std::cout << A_MESSAGES.PROMPT;
        std::getline(std::cin, buffer);
        input = atoi(buffer.c_str()); // We convert the raw input to an integer

        // We check for errors. The respective error codes are displayed, if applicable.
        if(input < MINIMUM) {
            input_bad = true;
            std::cout << A_MESSAGES.LESS;
            continue;
        }
        else if(input > MAXIMUM) {
            input_bad = true;
            std::cout << A_MESSAGES.GREAT;
            continue;
        }
        else
            input_bad = false;
    }
    while(input_bad == true); // The loop continues while the input is bad.
}

int menu::return_input() {
    return(input);
}